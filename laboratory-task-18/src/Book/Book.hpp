#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Для корректной работы std::remove

static std::string currentISBN = "AAAAAA";

// Функция для создания следующего ISBN
std::string generateNextISBN();

class Book {
public:
    std::string ISBN;
    std::string Title;
    std::vector<std::string> Authors;
    double Price;
    int Count;

    Book() = default;
    Book(const std::string&, const std::vector<std::string>&, double, int);  // Конструктор с параметрами

    void addAuthor(const std::string&);     // Добавление автора

    void removeAuthor(const std::string&);  // Удаление автора

    friend std::ostream& operator<<(std::ostream&, Book&);  // Перегрузка оператора вывода
};

#endif
