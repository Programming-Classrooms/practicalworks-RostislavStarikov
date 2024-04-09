#include "StudentAfterSecondSession.hpp"

StudentAfterSecondSession::StudentAfterSecondSession(std::string initName, uint16_t initCourse, uint16_t initGroup, uint16_t initRecordNumber, int arr1[4], int arr2[5]) :
	StudentAfterFirstSession(initName, initCourse, initGroup, initRecordNumber, arr1)
{
	for (size_t i = 0; i < 5; ++i)
	{
		secondSessionRating[i] = arr2[i];
	}
}

StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterSecondSession& rhs) : StudentAfterFirstSession(rhs.name, rhs.course, rhs.group, rhs.recordNumber, rhs.firstSessionRating)
{
	for (size_t i = 0; i < 5; ++i)
	{
		secondSessionRating[i] = rhs.secondSessionRating[i];
	}
}

StudentAfterSecondSession::~StudentAfterSecondSession()
{}

/*================================================================================*/
/*===================================== Вывод ====================================*/
/*================================================================================*/

std::ostream& StudentAfterSecondSession::print(std::ostream& out) const
{
	StudentAfterFirstSession::print(out);
	out << "\nSecond semester ratings : ";
	for (size_t i = 0; i < 5; ++i) {
		out << secondSessionRating[i];
		if (i < 4) {
			out << ", ";
		}
	}
	out << "\nSecond semester average : " << this->calculateAverageGrade() << std::endl;
	return out;
}



/*================================================================================*/
/*============================ Перегрузка оператора << ===========================*/
/*================================================================================*/

std::ostream& operator<<(std::ostream& out, const StudentAfterSecondSession& obj) \
{
	obj.print(out);
	out << "\n=========================================\n";
	return out;
}

/*================================================================================*/
/*========================= Средний балл за 2-oй семестр =========================*/
/*================================================================================*/

double StudentAfterSecondSession::calculateAverageGrade() const
{
	double sum = 0;
	for (size_t i = 0; i < 4; ++i) {
		sum += firstSessionRating[i];
	}
	for (size_t i = 0; i < 5; ++i) {
		sum += secondSessionRating[i];
	}
	return sum / 9.0;
}
