/*
    При написании программ использовать нуль–терминированные строки
    и работать только с типом char *. Длина каждой строки не превосходит 300
    символов. Словом, входящим в состав строки, назовём непрерывную
    последовательность символов, ограниченную символами–разделителями,
    началом и концом строки. Символы, относящиеся к разделителям, определяет
    пользователь, если иное не сказано в условии задачи. Если решить задачу
    невозможно, программа должна выдать соответствующее сообщение.
    Вариант 11
    Строка состоит из слов, разделенных ровно одним пробелом, пробелов
    перед первым и после последнего слова нет.Поместить в начало строки
    слова, содержащие только цифры, а затем – все остальные слова.Порядок
    слов внутри заданных групп не должен изменяться.
*/
#include <iostream>
#include <cstring>
#include <cctype>


void processWordsFromConsole(char* line,char** digits, char** nonDigits, size_t& digitCount,size_t& nonDigitCount ) 
{

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
}

 void printResultLine(char** digits, char** nonDigits, size_t digitCount,size_t nonDigitCount)
 { 
    for (int i = 0; i < digitCount; i++) {
        std::cout << digits[i] << " ";
    }

    for (int i = 0; i < nonDigitCount; i++) {
        std::cout << nonDigits[i] << " ";
    }
}

int main() {
    char line[301]; 
    char* digits[300];  
    char* nonDigits[300];  
    size_t digitCount = 0;  
    size_t nonDigitCount = 0;  

    std::cout << "Enter a line : ";
    std::cin.getline(line, 301);

    processWordsFromConsole(line, digits, nonDigits, digitCount, nonDigitCount);
    printResultLine(digits, nonDigits, digitCount, nonDigitCount);
    return 0;
}
