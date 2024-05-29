#include "Library.hpp"

/*================================================================================*/
/*=========================== Конструктор с параметром ===========================*/
/*================================================================================*/

Library::Library(std::set<Book>& inBooks) : Books(inBooks) 
{}

/*================================================================================*/
/*======================= Метод добавления/удаления автора =======================*/
/*================================================================================*/

void Library::addBook(const Book& inBook)
{
    Books.insert(inBook);
}

void Library::deleteBook(const Book& delBook)
{
    Books.erase(delBook);
}

/*================================================================================*/
/*==================================== Геттер ====================================*/
/*================================================================================*/

std::set<Book> Library::getBook() const
{
    return Books;
}

/*================================================================================*/
/*================== Методы нахождения книги по названию/автору ==================*/
/*================================================================================*/

void Library::searchTitle(const std::string& name) 
{
    bool find = false;
    for (auto obj : Books)
    {
        if (obj.getTitle() == name) 
        find = true;
        std::cout << obj << '\n'; 
    }
    if (!find)
    std::cout << "\nКнига с названием " << name << "не найдена\n";
}

void Library::searchAuthor(const Author& name) 
{
    bool find = false;
    for (auto book : Books)
    {
        for (auto author : book.getList().getAuthors())
        {
            if (author == name)
            {
                std::cout << book << '\n';
                find = true;
            }
        }
    }
    if (!find)
    std::cout << "\nКнига с автором " << name << "не найдена\n";
}

/*================================================================================*/
/*====================== Перегрузка оператора вывода в поток =====================*/
/*================================================================================*/

std::ostream& operator<<(std::ostream& out, const Library& library)
{
    for (auto book : library.getBook())
    {
        out << "\n=================================";
        out << "\nUDC:\t\t\t"   << book.getUDC();
        out << "\nAuthors:\t\t" << book.getList();
        out << "\nTitle:\t\t\t" << book.getTitle();
        out << "\nYear of publish:\t" << book.getYear();
        out << "\n=================================";
    }
    return out;
}