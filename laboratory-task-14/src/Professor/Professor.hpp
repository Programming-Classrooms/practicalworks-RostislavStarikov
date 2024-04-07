#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "src/Person/Person.hpp"

class Professor final : public Person
{
private:
	char* department;
public:
	Professor();
	Professor(const char*,const char*);
	Professor(Professor&);
	~Professor();

	void setDepartment(const char*);
	char* getDepartment() const;

	// Ввод и вывод
	friend std::ostream& operator<<(std::ostream&, const Professor&);
	friend std::istream& operator>>(std::istream&, Professor&);

	//Функция вывода
	void print(std::ostream&) const override;
};

#endif
