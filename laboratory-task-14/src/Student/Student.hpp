#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "src/Person/Person.hpp"
class Student final : public Person
{
private:
	int course;
	int group;
public:
	// Конструкторы
	Student();
	Student(char*, const int&, const int&);
	Student(const Student&);
	~Student();

	// Геттеры и сеттеры
	void setCourse(const int&);
	void setGroup(const int&);
	int getCourse() const;
	int getGroup() const;

	// Ввод и вывод
	friend std::ostream& operator<<(std::ostream&, const Student&);
	friend std::istream& operator>>(std::istream&, Student&);

	// Функция вывода
	void print(std::ostream&) const override;
};

#endif
