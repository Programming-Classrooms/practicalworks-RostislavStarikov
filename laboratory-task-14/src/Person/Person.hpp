#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <cstring>
#include <string>

class Person {
protected:
    char* fullName;

public:
    // Конструктор по умолчанию
    Person();

    // Конструктор с параметром
    Person(const char* name);

    // Конструктор копирования
    Person(const Person& other);

    // Деструктор
    virtual ~Person();

    // Геттер для имени
    char* getFullName() const;

    // Сеттер для имени
    void setFullName(const char*);

    // Оператор ввода
    friend std::istream& operator>>(std::istream&, Person&);

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream&, const Person&);

    // Функция вывода
    virtual void print(std::ostream&) const;
};
#endif
