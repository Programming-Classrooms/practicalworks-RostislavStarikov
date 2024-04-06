#include "Fraction.hpp"

Fraction::Fraction() : numerator(0), denominator(1) {}

void Fraction::checkDenom(const Fraction& check)
{
	if (check.denominator == 0)
	{
		
		throw std::invalid_argument("Division by zero!");
	}
}
void Fraction::checkDenom(const int32_t& check)
{
	if (check == 0)
	{
		throw std::invalid_argument("Division by zero!");
	}
}
/*================================================================================*/
/*================================= Конструкторы =================================*/
/*================================================================================*/

Fraction::Fraction(int32_t takeNumerator, int32_t takeDenominator)
{
	if (takeDenominator == 0)
	{
		throw std::invalid_argument("Division by zero!");
	}	if (takeDenominator < 0)
	{
		takeDenominator = -takeDenominator;
		takeNumerator = -takeNumerator;
	}
	this->numerator = takeNumerator;
	this->denominator = takeDenominator;
}
Fraction::Fraction(const Fraction& obj)
{
	this->numerator = obj.numerator;
	this->denominator = obj.denominator;

}

/*================================================================================*/
/*================ Перегрузка арифметических операторов с дробями ================*/
/*================================================================================*/


Fraction Fraction::operator+(const Fraction& rhs) const
{
	Fraction result(*this); // Создаем копию текущего объекта
	result.numerator = this->numerator * rhs.denominator + rhs.numerator * this->denominator;
	result.denominator = this->denominator * rhs.denominator;
	return result;
}
Fraction Fraction::operator-(const Fraction& rhs) const
{
	Fraction result(*this);
	result.numerator = this->numerator * rhs.denominator - rhs.numerator * this->denominator;
	result.denominator = this->denominator * rhs.denominator;
	return result;
}
Fraction Fraction::operator*(const Fraction& rhs) const
{
	Fraction result(*this);
	result.numerator = this->numerator * rhs.numerator;
	result.denominator = this->denominator * rhs.denominator;
	return result;
}
Fraction Fraction::operator/(const Fraction& rhs) const
{
	checkDenom(rhs);
	Fraction result(*this);
	result.numerator = this->numerator * rhs.denominator;
	result.denominator = this->denominator * rhs.numerator;
	return result;
}
/*================================================================================*/
/*============= Перегрузка арифметических операторов с целыми числами ============*/
/*================================================================================*/

Fraction Fraction::operator+(const int32_t rhs) const
{
	Fraction result(*this);
	int32_t temp = this->denominator * rhs;
	result.numerator = this->numerator + temp;
	return result;
}
Fraction Fraction::operator-(const int32_t rhs) const
{
	Fraction result(*this);
	int32_t temp = this->denominator * rhs;
	result.numerator = this->numerator - temp;
	return result;
}
Fraction Fraction::operator*(const int32_t rhs) const
{
	Fraction result(*this);
	int32_t temp = this->numerator * rhs;
	result.numerator = temp;
	return result;
}
Fraction Fraction::operator/(const int32_t rhs) const
{
	checkDenom(rhs);
	Fraction result(*this);
	int32_t temp = this->denominator * rhs;
	result.denominator = temp;
	return result;
}
/*================================================================================*/
/*=============== Перегрузка арифметических операторов число-дробь ===============*/
/*================================================================================*/

Fraction operator+(const int32_t lhs, const Fraction& rhs)
{
	return rhs + lhs;
}
Fraction operator-(const int32_t lhs, const Fraction& rhs)
{
	Fraction result(lhs * rhs.denominator - rhs.numerator, rhs.denominator);
	return result;
}
Fraction operator*(const int32_t lhs, const Fraction& rhs)
{
	return rhs * lhs;
}
Fraction operator/(const int32_t lhs, const Fraction& rhs)
{
	Fraction result(lhs * rhs.denominator, rhs.numerator);
	Fraction::checkDenom(result);
	return result;
}

/*================================================================================*/
/*=========== Перегрузка арифметических операторов с дробными числами ============*/
/*================================================================================*/

double Fraction::operator+(const double& rhs) const
{
	Fraction temp(*this);
	return (temp.toDouble() + rhs);
}
double Fraction::operator-(const double& rhs) const
{
	Fraction temp(*this);
	return (temp.toDouble() - rhs);
}
double Fraction::operator*(const double& rhs) const
{
	Fraction temp(*this);
	return (temp.toDouble() * rhs);
}
double Fraction::operator/(const double& rhs) const
{
	Fraction temp(*this);
	checkDenom(static_cast<int32_t>(rhs));
	return (temp.toDouble() / rhs);
}
/*================================================================================*/
/*=========== Перегрузка арифметических операторов дробное число-дробь ===========*/
/*================================================================================*/

double operator+(const double& lhs, const Fraction& rhs)
{
	return rhs + lhs;
}
double operator-(const double& lhs, const Fraction& rhs)
{
	return -(rhs - lhs);
}
double operator*(const double& lhs, const Fraction& rhs)
{
	return rhs * lhs;
}
double operator/(const double& lhs, const Fraction& rhs)
{
	Fraction temp(rhs);
	Fraction::checkDenom(temp);
	return rhs / lhs;
}
/*================================================================================*/
/*=============================== Инкрементирование ==============================*/
/*================================================================================*/

Fraction Fraction::operator++() const
{

	return (*this + 1);
}
Fraction Fraction::operator++(int32_t post)
{
	Fraction temp(*this);
	*this = *this + 1;
	return temp;
}
/*================================================================================*/
/*=============================== Декрементирование ==============================*/
/*================================================================================*/

Fraction Fraction::operator--() const
{

	return (*this - 1);
}
Fraction Fraction::operator--(int32_t post)
{
	Fraction temp(*this);
	*this = *this - 1;
	return temp;
}
/*================================================================================*/
/*========================== Перегрузка унарного минуса ==========================*/
/*================================================================================*/

Fraction Fraction::operator-()
{
	return (*this * (-1));
}
/*================================================================================*/
/*======================= Перегрузка ! (перевернуть дробь) =======================*/
/*================================================================================*/

Fraction Fraction::operator!()
{
	Fraction result(this->denominator, this->numerator);
	return result;
}
/*================================================================================*/
/*============================= Сравнение дробь-дробь ============================*/
/*================================================================================*/

bool Fraction::operator>(const Fraction& rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() > rhs.toDouble());
}
bool Fraction::operator<(const Fraction& rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() < rhs.toDouble());
}
bool Fraction::operator==(const Fraction& rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() == rhs.toDouble());
}
bool Fraction::operator!=(const Fraction& rhs) const
{
	Fraction lhs = *this;
	return !(lhs.toDouble() == rhs.toDouble());
}
bool Fraction::operator>=(const Fraction& rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() == rhs.toDouble() && lhs.toDouble() > rhs.toDouble());
}
bool Fraction::operator<=(const Fraction& rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() == rhs.toDouble() && lhs.toDouble() < rhs.toDouble());
}
/*================================================================================*/
/*============================= Сравнение дробь-число ============================*/
/*================================================================================*/

bool Fraction::operator>(const int32_t rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() > rhs);
}
bool Fraction::operator<(const int32_t rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() < rhs);
}
bool Fraction::operator==(const int32_t rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() == rhs);
}
bool Fraction::operator!=(const int32_t rhs) const
{
	Fraction lhs = *this;
	return !(lhs.toDouble() == rhs);
}
bool Fraction::operator>=(const int32_t rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() == rhs && lhs.toDouble() > rhs);
}
bool Fraction::operator<=(const int32_t rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() == rhs && lhs.toDouble() < rhs);
}

/*================================================================================*/
/*============================= Сравнение число-дробь ============================*/
/*================================================================================*/

bool operator>(int32_t rhs, const Fraction& lhs)
{
	return lhs > rhs;
}
bool operator<(int32_t rhs, const Fraction& lhs)
{
	return lhs < rhs;
}
bool operator == (int32_t rhs, const Fraction& lhs)
{
	return lhs == rhs;
}
bool operator!=(int32_t rhs, const Fraction& lhs)
{
	return lhs != rhs;
}
bool operator<=(int32_t rhs, const Fraction& lhs)
{
	return lhs <= rhs;
}
bool operator>=(int32_t rhs, const Fraction& lhs)
{
	return lhs >= rhs;
}
/*================================================================================*/
/*========================= Сравнение дробь-дробное число ========================*/
/*================================================================================*/

bool Fraction::operator>(const double rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() > rhs);
}
bool Fraction::operator<(const double rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() < rhs);
}
bool Fraction::operator==(const double rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() == rhs);
}
bool Fraction::operator!=(const double rhs) const
{
	Fraction lhs = *this;
	return !(lhs.toDouble() == rhs);
}
bool Fraction::operator>=(const double rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() == rhs && lhs.toDouble() > rhs);
}
bool Fraction::operator<=(const double rhs) const
{
	Fraction lhs = *this;
	return (lhs.toDouble() == rhs && lhs.toDouble() < rhs);
}

/*================================================================================*/
/*========================= Сравнение дробное число-дробь ========================*/
/*================================================================================*/

bool operator>(double rhs, const Fraction& lhs)
{
	return lhs > rhs;
}
bool operator<(double rhs, const Fraction& lhs)
{
	return lhs < rhs;
}
bool operator == (double rhs, const Fraction& lhs)
{
	return lhs == rhs;
}
bool operator!=(double rhs, const Fraction& lhs)
{
	return lhs != rhs;
}
bool operator<=(double rhs, const Fraction& lhs)
{
	return lhs <= rhs;
}
bool operator>=(double rhs, const Fraction& lhs)
{
	return lhs >= rhs;
}
/*================================================================================*/
/*======================== Смешанные операторы дробь-дробь =======================*/
/*================================================================================*/

Fraction Fraction::operator+=(const Fraction& rhs)
{
	return (*this + rhs);
}
Fraction Fraction::operator-=(const Fraction& rhs)
{
	return (*this - rhs);
}
Fraction Fraction::operator*=(const Fraction& rhs)
{
	return (*this * rhs);
}
Fraction Fraction::operator/=(const Fraction& rhs)
{
	return (*this / rhs);
}
/*================================================================================*/
/*===================== Смешанные операторы дробь-целое число ====================*/
/*================================================================================*/

Fraction Fraction::operator+=(const int32_t rhs)
{
	*this = *this + rhs;
	return *this;
}
Fraction Fraction::operator-=(const int32_t rhs)
{
	*this = *this - rhs;
	return *this;
}
Fraction Fraction::operator*=(const int32_t rhs)
{
	*this = *this * rhs;
	return *this;
}
Fraction Fraction::operator/=(const int32_t rhs)
{
	*this = *this / rhs;
	return *this;
}
/*================================================================================*/
/*============================ Перегрузка оператора = ============================*/
/*================================================================================*/

Fraction Fraction::operator=(const Fraction& rhs) {
	if (this != &rhs) {
		numerator = rhs.numerator;
		denominator = rhs.denominator;
	}
	return *this;
}
/*================================================================================*/
/*=================== Перевод дроби в дробное число типа double ==================*/
/*================================================================================*/

double Fraction::toDouble() const
{
	return (this->numerator * 1.0 / this->denominator);
}
/*================================================================================*/
/*=============================== Сокращение дроби ===============================*/
/*================================================================================*/

Fraction& Fraction::reducing()
{
	int32_t a = numerator;
	int32_t b = denominator;
	int32_t gcd = 1;
	if (a % b == 0)
	{
		numerator = a / b;
		denominator = 1;
		return *this;
	}

	for (int32_t i = 1; i <= a && i <= b; ++i) {
		if (a % i == 0 && b % i == 0) {
			gcd = i;
		}
	}
	numerator /= gcd;
	denominator /= gcd;

	return *this;
}

/*================================================================================*/
/*========================== Перегрузка оператора вывода =========================*/
/*================================================================================*/

std::ostream& operator << (std::ostream& out, const Fraction& obj)
{
	Fraction temp = obj; // Создаем копию, тк obj константный
	temp.reducing(); // Вызываем функцию упрощения для временного объекта
	if (temp.numerator == 0)
	{
		out << 0;
	}
	if (temp.denominator == 1)
	{
		out << temp.numerator;
	}
	else
	{
		out << temp.numerator << '/' << temp.denominator;
	}
	return out;
}

/*================================================================================*/
/*========================== Перегрузка оператора ввода ==========================*/
/*================================================================================*/


std::istream& operator>>(std::istream& in, Fraction& rhs)
{
	std::string input;
	in >> input;
	size_t pos = input.find('/');
	if (pos != std::string::npos) {
		rhs.numerator = std::stoi(input.substr(0, pos));
		rhs.denominator = std::stoi(input.substr(pos + 1));
		if (rhs.denominator == 0)
		{
			throw std::invalid_argument("Division by zero!");
		}
	}
	else
	{
		throw std::invalid_argument("Invalid argument!!!");
	}
	return in;
}
/*================================================================================*/
/*================================== Деструктор ==================================*/
/*================================================================================*/

Fraction::~Fraction()
{

}
