#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <algorithm>
#include <unordered_map>

#include "../Book/Book.hpp"

class Library {
private:
    std::unordered_map<std::string, Book> books;

public:
    void addBook(const Book&);              // Метод добавления книги

    Book* findBook(const std::string&);     // Метод поиска книги

    void removeBook(const std::string&);    // Метод удаления книги

    void addAuthor(const std::string&, const std::string&); // Метод добавления автора по ISBN 

    void removeAuthor(const std::string&, const std::string&);  // Метод удаления автора

    void sortBooksByISBN();     // Сортировка по ISBN 
    
    void sortBooksByTitle();    // Сортровка по названию 

    friend std::ostream& operator<<(std::ostream&, Library&); // Перегрузка оператора вывода
};

#endif
