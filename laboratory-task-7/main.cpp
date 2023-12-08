#include <iostream>
#include <cstring>
#include <cctype>


void processWordsFromConsole(char* line) {
    char* digits[300];  
    char* nonDigits[300];  
    int digitCount = 0;  
    int nonDigitCount = 0;  

    char* word = std::strtok(line, " ");
    while (word) {
        bool onlyDigits = true;
        for (size_t i = 0; i < std::strlen(word); i++) {
            if (!std::isdigit(word[i])) {
                onlyDigits = false;
                break;
            }
        }
        if (onlyDigits) {
            digits[digitCount++] = word;  
        }
        else {
            nonDigits[nonDigitCount++] = word;  
        }
        word = std::strtok(NULL, " ");
    }

   
    for (int i = 0; i < digitCount; i++) {
        std::cout << digits[i] << " ";
    }

    for (int i = 0; i < nonDigitCount; i++) {
        std::cout << nonDigits[i] << " ";
    }
}

int main() {
    char line[301]; 

    std::cout << "Enter a line : ";
    std::cin.getline(line, 301);

    processWordsFromConsole(line);
    return 0;
}
