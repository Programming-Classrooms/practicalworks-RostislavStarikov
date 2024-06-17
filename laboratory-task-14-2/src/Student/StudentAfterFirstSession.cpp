#include "StudentAfterFirstSession.hpp"

/*================================================================================*/
/*================================= Конструкторы =================================*/
/*================================================================================*/

StudentAfterFirstSession::StudentAfterFirstSession(std::string initName, uint16_t initCourse, uint16_t initGroup, uint16_t initRecordNumber,const int arr[4]) :
	Student(initName, initCourse, initGroup, initRecordNumber)
{
	for (size_t i = 0; i < 4; ++i)
	{
		firstSessionRating[i] = arr[i];
	}
}


StudentAfterFirstSession::StudentAfterFirstSession(const StudentAfterFirstSession& rhs) : Student(rhs.name, rhs.course, rhs.group, rhs.recordNumber)
{
	for (size_t i = 0; i < 4; ++i)
	{
		firstSessionRating[i] = rhs.firstSessionRating[i];
	}
}

StudentAfterFirstSession::~StudentAfterFirstSession()
{
}

/*================================================================================*/
/*===================================== Вывод ====================================*/
/*================================================================================*/

std::ostream& StudentAfterFirstSession::print(std::ostream& out) const
{
    Student::print(out);
    out << "\nFirst semester ratings: ";
    for (size_t i = 0; i < 4; ++i) {
        out << firstSessionRating[i];
        if (i < 3) {
            out << ", ";
        }
    }
    out << "\nFirst semester average : " << StudentAfterFirstSession::calculateAverageGrade() << std::endl;
    return out;
}


/*================================================================================*/
/*============================ Перегрузка оператора << ===========================*/
/*================================================================================*/

std::ostream& operator<<(std::ostream& out, const StudentAfterFirstSession& obj) 
{
    obj.print(out);
    out << "\n=========================================\n";
    return out;
}

/*================================================================================*/
/*========================= Средний балл за 1-ый семестр =========================*/
/*================================================================================*/
double StudentAfterFirstSession::calculateAverageGrade() const
{
    double sum = 0;
    for (size_t i = 0; i < 4; ++i) sum += firstSessionRating[i];
    return sum / 4.0;
}
