#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "../Book/Book.hpp"

class Library
{
protected:
    std::set<Book> Books;
public:

    Library() = default;                    // Конструктор по умолчанию
    Library(std::set<Book>&);               // Конструктор с параметрами

    void addBook(const Book&);              // Метод добавления книги

    void deleteBook(const Book&);           // Метод удаления книги

    std::set<Book> getBook() const;                  // Геттер книги
    void searchTitle(const std::string&);   // Метод нахождения книги по названию
    void searchAuthor(const Author&);       // Метод нахождения книги по автору

    friend std::ostream& operator<<(std::ostream&, const Library&);

};


#endif
