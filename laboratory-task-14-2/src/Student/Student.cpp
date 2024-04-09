#include "Student.hpp"
uint16_t Student::counter = 0;

/*================================================================================*/
/*================================= Конструкторы =================================*/
/*================================================================================*/

Student::Student() :
	ID(++counter), 
	name("No Name"), 
	course(1), 
	group(1), 
	recordNumber(rand() % (UINT16_MAX) + 1) 
{}

Student::Student(std::string initName, uint16_t initCourse, uint16_t initGroup, uint16_t initRecordNumber) : ID(++counter), recordNumber(initRecordNumber)
{
	name = initName;
	course = initCourse;
	group = initGroup;
}

Student::Student(const Student& rhs) : 
	name(rhs.name), 
	course(rhs.course), 
	group(rhs.group), 
	ID(++counter), 
	recordNumber(rhs.recordNumber)
{}

Student::~Student()
{
}


/*================================================================================*/
/*==================================== Геттеры ===================================*/
/*================================================================================*/

const uint16_t Student::getID()
{
	return ID;
}

std::string Student::getName()
{
	return name;
}

uint16_t Student::getCourse()
{
	return course;
}

uint16_t Student::getGroup()
{
	return group;
}

const uint16_t Student::getRecordNumber()
{
	return recordNumber;
}

/*================================================================================*/
/*==================================== Сеттеры ===================================*/
/*================================================================================*/

void Student::setName(std::string initName)
{
	name = initName;
}
void Student::setGroup(uint16_t initGroup)
{
	group = initGroup;
}


void Student::setCourse(uint16_t initCourse)
{
	course = initCourse;
}

/*================================================================================*/
/*===================================== Вывод ====================================*/
/*================================================================================*/

std::ostream& Student::print(std::ostream& out) const
{
	out << "\n=========================================\n";
	out << "\nID:\t" << ID << "\nName:\t" << name << "\nCourse:\t" << course << "\nGroup:\t" << group << "\nRecord number:\t" << recordNumber;
	return out;
}

/*================================================================================*/
/*============================ Перегрузка оператора << ===========================*/
/*================================================================================*/


std::ostream& operator<<(std::ostream& out, const Student& obj)
{
	obj.print(out);
	out << "\n=========================================\n";
	return out;
}
