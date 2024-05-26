#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <string>

class Fraction
{
private:
	int32_t numerator;
	int32_t denominator;

	// Сокращение числителся и знаменателя на общий делитель
	Fraction& reducing();
public:

	// Конструкторы
	Fraction();
	Fraction(int32_t, int32_t);
	Fraction(const Fraction&);
	~Fraction();

	static void checkDenom(const Fraction&);
	static void checkDenom(const int32_t&);
	// Бинарные алгебраические операции

	// Дробь - дробь
	Fraction operator+(const Fraction&) const;
	Fraction operator-(const Fraction&) const;
	Fraction operator*(const Fraction&) const;
	Fraction operator/(const Fraction&) const;

	// Дробь - целое число
	Fraction operator+(const int32_t) const;
	Fraction operator-(const int32_t) const;
	Fraction operator*(const int32_t) const;
	Fraction operator/(const int32_t) const;

	// Целое цисло - дробь
	friend Fraction operator+(const int32_t, const Fraction&);
	friend Fraction operator-(const int32_t, const Fraction&);
	friend Fraction operator*(const int32_t, const Fraction&);
	friend Fraction operator/(const int32_t, const Fraction&);

	// дробь - вещественное число
	double operator+(const double&) const;
	double operator-(const double&) const;
	double operator*(const double&) const;
	double operator/(const double&) const;

	// вещественное число - дробь 
	friend double operator+(const double&, const Fraction&);
	friend double operator-(const double&, const Fraction&);
	friend double operator*(const double&, const Fraction&);
	friend double operator/(const double&, const Fraction&);

	// Унарные операторы

	// Префиксный инкремент
	Fraction operator++() const;

	// Постфиксный инкремент
	Fraction operator++(int32_t);

	// Префиксный декремент
	Fraction operator--() const;

	// Постфиксный декремент
	Fraction operator--(int32_t);

	//Унарный минус
	Fraction operator-();


	// Получение обратной дроби
	Fraction operator!();

	// Операторы сравнения дробь-дробь
	bool operator>(const Fraction&) const;
	bool operator<(const Fraction&) const;
	bool operator==(const Fraction&) const;
	bool operator!=(const Fraction&) const;
	bool operator>=(const Fraction&) const;
	bool operator<=(const Fraction&) const;

	// Операторы сравнения дробь-число
	bool operator>(const int32_t) const;
	bool operator<(const int32_t) const;
	bool operator==(const int32_t) const;
	bool operator!=(const int32_t) const;
	bool operator>=(const int32_t) const;
	bool operator<=(const int32_t) const;

	// Операторы сравнения число-дробь
	friend bool operator<(int32_t, const Fraction&);
	friend bool operator>(int32_t, const Fraction&);
	friend bool operator<=(int32_t, const Fraction&);
	friend bool operator>=(int32_t, const Fraction&);
	friend bool operator==(int32_t, const Fraction&);
	friend bool operator!=(int32_t, const Fraction&);

	// Операторы сравнения дробь-вещественное число
	bool operator>(const double) const;
	bool operator<(const double) const;
	bool operator==(const double) const;
	bool operator!=(const double) const;
	bool operator>=(const double) const;
	bool operator<=(const double) const;

	// Операторы сравнения вещественное число-дробь
	friend bool operator<(double, const Fraction&);
	friend bool operator>(double, const Fraction&);
	friend bool operator<=(double, const Fraction&);
	friend bool operator>=(double, const Fraction&);
	friend bool operator==(double, const Fraction&);
	friend bool operator!=(double, const Fraction&);


	// Cоставные операторы присваивания
	// Cоставные операторы присваивания дробь-дробь
	Fraction operator+=(const Fraction&);
	Fraction operator-=(const Fraction&);
	Fraction operator*=(const Fraction&);
	Fraction operator/=(const Fraction&);

	// Cоставные операторы присваивания дробь-число
	Fraction operator+=(const int32_t);
	Fraction operator-=(const int32_t);
	Fraction operator*=(const int32_t);
	Fraction operator/=(const int32_t);

	// Оператор присваивания
	Fraction operator=(const Fraction&);

	// Приведение к вещественному виду
	double toDouble() const;

	// Поток вывода для класса дробь
	friend std::ostream& operator << (std::ostream&, const Fraction&);
	// Поток вводадля класса дробь
	friend std::istream& operator >> (std::istream&, Fraction&);


};

#endif
