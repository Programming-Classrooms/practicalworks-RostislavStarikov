#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream>
#include <cstring>

class myString
{
private:
	size_t len;
	char* str;
public:

	// Конструкторы
	myString();
	myString(const char*);
	myString(const myString&);

	// Перегрузка оператора присваивания
	myString& operator = (myString&);

	// Перегрузка смешанных операторов
	myString& operator += (const myString&);

	// Конкатенация
	myString& operator + (const myString&);

	// Перегрузка операторов сравнения
	bool operator == (const myString&);
	bool operator > (const myString&);
	bool operator >= (const myString&);
	bool operator < (const myString&);
	bool operator <= (const myString&);
	bool operator != (const myString&);

	// Проверка на пустоту файла
	bool is_empty();

	// Геттер
	const char* getStr() const;
	size_t getLength() const;

	// Сеттер
	void setStr(const char*);

	// Методы поиска подстроки
	friend int32_t search_first_of(const char, const myString&);


	// Добавление символа в конец строки
	void push_back(const char);


	// Перегрузка оператора вывода
	friend std::ostream& operator << (std::ostream&, const myString&);

	// Перегрузка оператора ввода
	friend std::istream& operator>>(std::istream&, myString&);
	~myString();
};
#endif