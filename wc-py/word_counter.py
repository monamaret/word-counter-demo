#!/usr/bin/env python3

def main():
    filename = input("Enter the filename to analyze: ")
    
    try:
        with open(filename, 'r') as file:
            word_count = 0
            line_count = 0
            char_count = 0
            in_word = False
            
            for line in file:
                line_count += 1
                char_count += len(line)
                
                for c in line:
                    if c in [' ', '\t', '\n', '\r']:
                        in_word = False
                    elif not in_word:
                        in_word = True
                        word_count += 1
            
            print(f"File: {filename}")
            print(f"Words: {word_count}")
            print(f"Lines: {line_count}")
            print(f"Characters: {char_count}")
            
    except FileNotFoundError:
        print(f"Error: Could not open file {filename}")
        return 1
    
    return 0

if __name__ == "__main__":
    main()