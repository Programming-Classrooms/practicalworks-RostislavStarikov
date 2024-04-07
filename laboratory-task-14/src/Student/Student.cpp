#define _CRT_SECURE_NO_WARNINGS
#include "src/Student/Student.hpp"

/*================================================================================*/
/*================================= Конструкторы =================================*/
/*================================================================================*/

Student::Student() : Person(), course(1), group(1)
{
}

Student::Student(char* name, const int& inCourse, const int& inGroup) : Person(name), group(inGroup), course(inCourse)
{
}

Student::Student(const Student& rhs) : Person(rhs.fullName), course(rhs.course), group(rhs.group) {}

Student::~Student()
{
}

/*================================================================================*/
/*==================================== Сеттеры ===================================*/
/*================================================================================*/


void Student::setCourse(const int& setCo)
{
    course = setCo;
}

void Student::setGroup(const int& setGr)
{
    group = setGr;
}

/*================================================================================*/
/*==================================== Геттеры ===================================*/
/*================================================================================*/


int Student::getCourse() const
{
    return course;
}

int Student::getGroup() const
{
    return group;
}

/*================================================================================*/
/*================================ Функция вывода ================================*/
/*================================================================================*/


void Student::print(std::ostream& out) const
{
    out << *this;
}

/*================================================================================*/
/*===================== Перегрузка операторов ввода и вывода =====================*/
/*================================================================================*/

std::ostream& operator<<(std::ostream& out, const Student& obj)
{
    out << "\n=====================================================================\n";
    out << "Full name of Student : \t" << obj.fullName << "\nCourse of student : \t" << obj.course << "\nGroup of student : \t" << obj.group << std::endl;
    out << "\n=====================================================================\n";
    return out;
}

std::istream& operator>>(std::istream& in, Student& obj)
{
    std::cout << "\nPlease, enter information about student:\nFull name:\t";

    // Считываем полное имя в строковую переменную
    std::string fullName;
    std::getline(in, fullName);

    // Динамическое выделение памяти и копирование строки в fullName класса Student
    obj.setFullName(fullName.c_str());

    std::cout << "\nCourse:\t\t";
    int course = 0;
    in >> course;
    obj.setCourse(course);

    std::cout << "\nGroup:\t\t";
    int group = 0;
    in >> group;
    obj.setGroup(group);

    return in;
}
