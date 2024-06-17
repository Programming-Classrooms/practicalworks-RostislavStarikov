#include "Library.hpp"

/*============================================================================*/
/*================== Методы добавления/поиска/удаления книги =================*/
/*============================================================================*/

void Library::addBook(const Book& book) 
{
    if (books.find(book.ISBN) != books.end()) 
    {
        std::cout << "Книга с данным ISBN: " << book.ISBN << " уже присутсвует в библиотеке.\n";
        return;
    }
    books[book.ISBN] = book;
}

Book* Library::findBook(const std::string& isbn)
{
    
    auto it = books.find(isbn);
    if (it != books.end()) 
    {
        return &it->second;
    }
    return nullptr;
}

void Library::removeBook(const std::string& isbn) 
{
    books.erase(isbn);
}

/*============================================================================*/
/*===================== Методы добавления/удаления автора ====================*/
/*============================================================================*/

void Library::addAuthor(const std::string& isbn, const std::string& author) 
{
    Book* book = findBook(isbn);
    if (book) 
    {
        book->addAuthor(author);
    } 
    else 
    {
        std::cout << "Книга с ISBN " << isbn << " не найдена.\n";
    }
}

void Library::removeAuthor(const std::string& isbn, const std::string& author) 
{
    Book* book = findBook(isbn);
    if (book) 
    {
        book->removeAuthor(author);
    } 
    else {
        std::cout << "Книга с ISBN " << isbn << " не найдена.\n";
    }
}

/*============================================================================*/
/*================================ Сортировки ================================*/
/*============================================================================*/

void Library::sortBooksByISBN() 
{
    std::cout << *this;
}

void Library::sortBooksByTitle() 
{
    std::vector<Book> sortLibrary;
    for (auto book : books)
    {
        sortLibrary.push_back(book.second);
    }
    for (auto el : sortLibrary)
    {
        std::cout << el;
    }
}

/*============================================================================*/
/*======================== Перегрузка оператора вывода =======================*/
/*============================================================================*/

std::ostream &operator<<(std::ostream& out, Library& obj)
{
    for (auto el : obj.books)
    {
        out << el.second;
    }
    return out;
}
