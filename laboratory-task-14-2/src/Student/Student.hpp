#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <cstdint>
#include <iostream>


class Student
{
protected:
	const uint16_t ID;
	std::string name;
	uint16_t course;
	uint16_t group;
	const uint16_t recordNumber;
	static uint16_t counter;
public:
	// Конструкторы
	Student();
	Student(std::string, uint16_t, uint16_t, uint16_t);
	Student(const Student&);
	virtual ~Student();

	//	Геттеры
	const uint16_t getID();
	std::string getName();
	uint16_t getCourse();
	uint16_t getGroup();
	const uint16_t getRecordNumber();

	// Сеттеры
	void setName(std::string);
	void setCourse(uint16_t);
	void setGroup(uint16_t);

	// Вывод
	virtual std::ostream& print(std::ostream&) const;

	// Перегрузка оператора << 
	friend std::ostream& operator<<(std::ostream&,const Student&);
};


#endif
