#ifndef BOOK_HPP
#define BOOK_HPP

#include <stdint.h>
#include <string>

#include "../AuthorList/AuthorList.hpp"

class Book 
{
private:
    uint32_t UDC;
    AuthorList List;
    std::string Title;
    uint16_t Year;

public:
    Book();                                                                     // Конструктор по умолчанию
    Book(const uint32_t, const AuthorList&, const std::string&, const uint16_t);// Конструктор с параметрами
    Book(const Book&);                                                          // Конструктор копирования

    uint32_t getUDC() const;
    uint16_t getYear() const;
    std::string getTitle() const; // Геттер названия
    AuthorList getList() const; // Геттер автора

    void addAuthor(const Author&);      // Метод добавления автора
    void removeAuthor(const Author&);   // Метод удаления автора
    
    bool operator<(const Book&) const;    // Перегрузка оператора < для корректной работы сортировки в std::set<Book>
    bool operator==(const Book&) const;   // Перегрузка оператора == для корректной работы сортировки в std::set<Book>

    ~Book() = default; // Деструктор

    friend std::ostream& operator<<(std::ostream&, Book&); // Перегрузка оператора вывода в поток
};

#endif 
