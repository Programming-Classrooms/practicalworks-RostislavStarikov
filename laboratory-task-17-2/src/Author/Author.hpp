#ifndef AUTHOR_HPP
#define AUTHOR_HPP

#include <iostream>

class Author
{
protected:
std::string Surname;
std::string Name;
std::string Patronymic;
public:

Author  (const std::string& Surname = "Surname",        // Конструктор по умолчанию и параметрам
        const std::string& Name = "Name", 
        const std::string& Patronymic = "Patronymic"); 
Author(const Author&);                                  // Конструктор копирования
~Author() = default;                                    // Деструктор
 
std::string getSurname();   // Геттер фамилии
std::string getName();      // Геттер имени
std::string getPatronymic();// Геттер отчества

// Перегрузка операторов сравнения для корректной работы std::set<Author>
bool operator<(const Author&) const;
bool operator==(const Author&) const;

friend std::ostream& operator<<(std::ostream&, const Author&);  // Перегрузка оператора вывода в поток

};
#endif
