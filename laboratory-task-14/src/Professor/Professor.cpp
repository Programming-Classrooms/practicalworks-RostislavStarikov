#define _CRT_SECURE_NO_WARNINGS_
#include "src/Professor/Professor.hpp"

/*================================================================================*/
/*================================= Конструкторы =================================*/
/*================================================================================*/


Professor::Professor() : Person(), department(nullptr)
{
}

Professor::Professor(const char* name,const char* depart) : Person(name)
{
    department = new char[strlen(depart) + 1];
    strcpy(department, depart);
}

Professor::Professor(Professor& rhs) : Person(rhs.fullName), department(rhs.department)
{}

Professor::~Professor()
{
    delete[] department;
}

/*================================================================================*/
/*==================================== Сеттеры ===================================*/
/*================================================================================*/


void Professor::setDepartment(const char* rhs)
{
    if (department) {
        delete[] department;
    }

    department = new char[strlen(rhs) + 1];

    strcpy(department, rhs);
}

/*================================================================================*/
/*==================================== Геттеры ===================================*/
/*================================================================================*/


char* Professor::getDepartment() const
{
    return department;
}

/*================================================================================*/
/*================================ Функция вывода ================================*/
/*================================================================================*/

void Professor::print(std::ostream& out) const
{
    out << *this;
}

/*================================================================================*/
/*===================== Перегрузка операторов ввода и вывода =====================*/
/*================================================================================*/


std::ostream& operator<<(std::ostream& out, const Professor& obj)
{
    out << "\n=====================================================================\n";
    out << "Full name of Professor : \t" << obj.fullName << "\nDepartment of Professor : \t" << obj.department << std::endl;
    out << "\n=====================================================================\n";
    return out;
}

std::istream& operator>>(std::istream& in, Professor& obj)
{
    std::cout << "\nPlease, enter information about Professor:\nFull name:\t";

    // Считываем полное имя в строковую переменную
    //std::string fullName;
    //std::getline(in >> std::ws, fullName);// Пропускаем начальные пробелы во входном потоке перед считыванием строки
    // Динамическое выделение памяти и копирование строки в fullName класса Professor
    //obj.setFullName(fullName.c_str());
    char buffer[100];
    in.getline(buffer, 100);
    obj.setFullName(buffer);


    std::cout << "\nDepartment:\t\t";
    std::string departments;
    std::getline(in, departments);

    // Динамическое выделение памяти и копирование строки в department класса Professor
    obj.setDepartment(departments.c_str());

    return in;
}
