#include "Book.hpp"

/*================================================================================*/
/*================================= Конструкторы =================================*/
/*================================================================================*/

Book::Book() :
    UDC(1),
    List(std::set<Author>()),
    Title("title"),
    Year(2000)
    {}

Book::Book(const uint32_t udc, const AuthorList& list, const std::string& title, const uint16_t year) :
    UDC(udc),
    List(list),
    Title(title),
    Year(year)
    {}

Book::Book(const Book& rhs)
{
    UDC = rhs.UDC;
    List = rhs.List;
    Title = rhs.Title;
    Year = rhs.Year;
}

/*================================================================================*/
/*======== Перегрузка операторов сравнения для корректной работы std::set ========*/
/*================================================================================*/

bool Book::operator<(const Book& rhs) const
{
    return (Title < rhs.Title);
}

bool Book::operator==(const Book& rhs) const
{
    return (Title == rhs.Title);
}

/*================================================================================*/
/*==================================== Геттеры ===================================*/
/*================================================================================*/

uint32_t Book::getUDC() const
{
    return UDC;
}

uint16_t Book::getYear() const
{
    return Year;
}
std::string Book::getTitle() const
{
    return Title;
}

AuthorList Book::getList() const
{
    return List;
}

/*================================================================================*/
/*======================= Методы добавления/удаления автора ======================*/
/*================================================================================*/

void Book::addAuthor(const Author& author)
{
    List.addAuthor(author); 
}
void Book::removeAuthor(const Author& author)
{
    List.removeAuthor(author); 
}

/*================================================================================*/
/*====================== Перегрузка оператора вывода в поток =====================*/
/*================================================================================*/

std::ostream& operator<<(std::ostream& out, Book& obj)
{
    out << "\n=================================";
    out << "\nUDC:\t\t\t"   << obj.getUDC();
    out << "\nAuthors:\t\t" << obj.getList();
    out << "\nTitle:\t\t\t" << obj.getTitle();
    out << "\nYear of publish:\t" << obj.getYear();
    out << "\n=================================";
    return out;
}
