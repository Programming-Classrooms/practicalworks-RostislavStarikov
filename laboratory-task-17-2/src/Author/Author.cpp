#include "Author.hpp"

/*================================================================================*/
/*================================= Конструкторы =================================*/
/*================================================================================*/

Author::Author(const std::string& inSurn, const std::string& inName, const std::string& inPatron) : 
    Surname(inSurn), 
    Name(inName),
    Patronymic(inPatron)
{}

Author::Author(const Author& obj)
{
    Surname = obj.Surname;
    Name = obj.Name;
    Patronymic = obj.Patronymic;
}

/*================================================================================*/
/*======== Перегрузка операторов сравнения для корректной работы std::set ========*/
/*================================================================================*/

bool Author::operator<(const Author& rhs) const
{
    return (Surname < rhs.Surname);
}

bool Author::operator==(const Author& rhs) const
{
    return (Surname == rhs.Surname && Name == rhs.Name && Patronymic == rhs.Patronymic);
}

/*================================================================================*/
/*==================================== Геттеры ===================================*/
/*================================================================================*/

std::string Author::getSurname()
{
    return Surname;
}
std::string Author::getName()
{
    return Name;
}
std::string Author::getPatronymic()
{
    return Patronymic;
}

/*================================================================================*/
/*====================== Перегрузка оператора вывода в поток =====================*/
/*================================================================================*/

std::ostream& operator<<(std::ostream& out, const Author& obj)
{
    out << obj.Surname << ' ' << obj.Name << ' ' << obj.Patronymic;
    return out; 
}
