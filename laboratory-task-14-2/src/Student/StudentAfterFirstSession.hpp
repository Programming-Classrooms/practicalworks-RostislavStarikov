#ifndef STUDENTAFTERFIRSTSESSION_HPP
#define STUDENTAFTERFIRSTSESSION_HPP

#include "Student.hpp"

class StudentAfterFirstSession : public Student
{
protected:
	int firstSessionRating[4];
public:
	// Конструкторы

	StudentAfterFirstSession() = delete;
	StudentAfterFirstSession(std::string, uint16_t, uint16_t, uint16_t,const int[4]);
	StudentAfterFirstSession(const StudentAfterFirstSession&);
	~StudentAfterFirstSession();

	// Вывод 
	std::ostream& print(std::ostream&) const override;

	// Перегрузка оператора << 
	friend std::ostream& operator<<(std::ostream&, const StudentAfterFirstSession&);

	// Средний балл за первый семестр
	virtual double calculateAverageGrade() const;
};

#endif
