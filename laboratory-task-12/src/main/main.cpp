#include "../myString/myString.hpp"
int main() 
{
    // Тестирование конструкторов
    myString s1; // Пустая строка
    myString s2("Hello"); // Строка "Hello"
    std::cout << "s2:" << s2 << '\n';
    myString s3 = s2; // Копирование строки s2
    std::cout << "s3 = s2: " << s3 << '\n';
    // Тестирование перегрузки оператора присваивания
    myString s4;
    s4 = s3; // Копирование содержимого строки s3 в s4

    // Тестирование конкатенации
    myString s5 = s2 + " World"; // Строка "Hello World"
    std::cout << "s2 + World: " << s5 << '\n';
    // Тестирование операторов сравнения
    if (s2 == s3) {
        std::cout << "s2 is equal to s3\n";
    }
    if (s2 != s3) {
        std::cout << s2 << " is not equal to " << s3 << '\n';
    }

    // Тестирование методов класса
    std::cout << "Length of s2: " << s2.getLength() << std::endl;
    myString buffer;
    s2.getStr(buffer, s2.getLength());
    std::cout << "Content of s2: " << buffer << std::endl;

    // Добавление символа в конец строки и вывод
    s2.push_back('!');
    std::cout << "After push_back ! : " << s2 << std::endl;

    return 0;
}