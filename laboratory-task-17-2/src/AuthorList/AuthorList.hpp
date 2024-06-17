#ifndef AUTHORLIST_HPP
#define AUTHORLIST_HPP
#include "../Author/Author.hpp"
#include <set>

class AuthorList
{
protected:
    std::set<Author> Authors;
public:
    AuthorList() = default;                 // Конструктор по умолчанию
    AuthorList(const std::set<Author>&);    // Конструктор с параметром
    AuthorList(const AuthorList&);          // Конструктор копирования
    ~AuthorList() = default;                // Деструктор

    std::set<Author> getAuthors() const;    // Геттер авторов

    void addAuthor(const Author&);          // Метод добавления автора

    void removeAuthor(const Author&);       // Метод удаления автора

    void output(std::ostream&);             // Метод вывода в поток

    friend std::ostream& operator<<(std::ostream&, const AuthorList&); // Перегрузка оператора вывода в поток
};


#endif
