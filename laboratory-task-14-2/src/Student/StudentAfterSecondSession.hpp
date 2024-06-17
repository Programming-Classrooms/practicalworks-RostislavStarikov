#ifndef STUDENTAFTERSECONDSESSION_HPP
#define STUDENTAFTERSECONDSESSION_HPP

#include "StudentAfterFirstSession.hpp"
class StudentAfterSecondSession final : public StudentAfterFirstSession
{
protected:
	int secondSessionRating[5];
public:
	StudentAfterSecondSession() = delete;
	StudentAfterSecondSession(std::string, uint16_t, uint16_t, uint16_t, int[4], int[5]);
	StudentAfterSecondSession(const StudentAfterSecondSession&);
	~StudentAfterSecondSession();

	// Вывод
	std::ostream& print(std::ostream&) const override;

	// Перегрузка оператора << 
	friend std::ostream& operator<<(std::ostream&, const StudentAfterSecondSession&);

	// Средний балл за второй семестр
	double calculateAverageGrade() const override;
};
#endif
