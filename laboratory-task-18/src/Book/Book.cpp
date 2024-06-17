#include "Book.hpp"
/*============================================================================*/
/*=================== Функция для создания следующего ISBN ===================*/
/*============================================================================*/

std::string generateNextISBN() {
    std::string nextISBN = currentISBN;
    for (int i = currentISBN.size() - 1; i >= 0; --i) {
        if (currentISBN[i] < 'Z') {
            currentISBN[i]++;
            break;
        } else {
            currentISBN[i] = 'A';
        }
    }

    return nextISBN;
}

/*============================================================================*/
/*========================= Конструктор с параметрами ========================*/
/*============================================================================*/

Book::Book(const std::string& inTitle, const std::vector<std::string>& inAuthors, double inPrice, int inCount): 
    ISBN(generateNextISBN()), 
    Title(inTitle), 
    Authors(inAuthors), 
    Price(inPrice), 
    Count(inCount) {}

/*============================================================================*/
/*======================== Добавление/удаление автора ========================*/
/*============================================================================*/

void Book::addAuthor(const std::string& author) 
{
    Authors.push_back(author);
}

void Book::removeAuthor(const std::string& author) 
{
    Authors.erase(std::remove(Authors.begin(), Authors.end(), author), Authors.end());
}

/*============================================================================*/
/*======================== Перегрузка оператора вывода =======================*/
/*============================================================================*/

std::ostream& operator<<(std::ostream& out, Book& obj)
{
    out << "\n================================";
    out << "\nISBN:\t\t" << obj.ISBN;
    out << "\nTitle:\t\t" << obj.Title; 
    out << "\nAuthors:\t";
    for (auto& author : obj.Authors) 
    {
        out << author << ", ";
    } 
    out << "\nPrice:\t\t" << obj.Price;
    out << "\nCount:\t\t" << obj.Count;
    out << "\n================================";
    return out;
}