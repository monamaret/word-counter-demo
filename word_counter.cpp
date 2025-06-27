#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter the filename to analyze: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        std::cerr << "Possible reasons:" << std::endl;
        std::cerr << "  - File does not exist" << std::endl;
        std::cerr << "  - Insufficient permissions" << std::endl;
        std::cerr << "  - File is in use by another program" << std::endl;
        std::cerr << "  - Invalid file path" << std::endl;
        return 1;
    }

    // Check if file is readable
    if (file.bad()) {
        std::cerr << "Error: File stream is in a bad state" << std::endl;
        return 1;
    }

    // Check if file is empty (optional warning)
    file.seekg(0, std::ios::end);
    if (file.tellg() == 0) {
        std::cout << "Warning: File '" << filename << "' is empty" << std::endl;
    }
    file.seekg(0, std::ios::beg); // Reset to beginning

    int wordCount = 0;
    int lineCount = 0;
    int charCount = 0;
    std::string line;
    bool inWord = false;

    while (std::getline(file, line)) {
        lineCount++;
        charCount += line.length() + 1; // +1 for the newline character

        for (char c : line) {
            if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
                inWord = false;
            } else if (!inWord) {
                inWord = true;
                wordCount++;
            }
        }
    }

    // Adjust character count for the last line (which might not have a newline)
    if (!file.eof() || line.empty()) {
        charCount--;
    }

    file.close();

    std::cout << "File: " << filename << std::endl;
    std::cout << "Words: " << wordCount << std::endl;
    std::cout << "Lines: " << lineCount << std::endl;
    std::cout << "Characters: " << charCount << std::endl;

    return 0;
}