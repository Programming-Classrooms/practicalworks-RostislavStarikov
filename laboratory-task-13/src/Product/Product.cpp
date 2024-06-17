#include "Product.hpp"
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>


/*================================================================================*/
/*=========================== Конструкторы и деструктор ==========================*/
/*================================================================================*/

Product::Product() :
	name(nullptr),
	cost(0),
	yearOfManufacture(0)
{}

Product::Product(const char* initName, double initCost, uint16_t initYear) :
	cost(initCost),
	yearOfManufacture(initYear)
{
	name = new char[strlen(initName) + 1];
	strcpy(name, initName);
}

Product::Product(const Product& rhs) : cost(rhs.cost), yearOfManufacture(rhs.yearOfManufacture)
{

	this->name = new char[strlen(rhs.name) + 1];
	strcpy(name, rhs.name);
}

Product::~Product()
{
	if (name != nullptr)
	{
		delete[]name;
		name = nullptr;
	}
}

/*================================================================================*/
/*==================================== Геттеры ===================================*/
/*================================================================================*/

char* Product::getName() const
{
	char* getterName = new char[strlen(name) + 1];
	strcpy(getterName, name);
	return getterName;
}

double Product::getCost() const
{
	return cost;
}

uint16_t Product::getYearOfManufacture() const
{
	return yearOfManufacture;
}


/*================================================================================*/
/*==================================== Сеттер ====================================*/
/*================================================================================*/

void Product::setName(char* initName)
{
	this->name = initName;
}

void Product::setCost(double initCost)
{
	this->cost = initCost;
}

void Product::setYearOfManufacture(uint16_t initYear)
{
	this->yearOfManufacture = initYear;
}

/*================================================================================*/
/*========================== Перегрузка оператора вывода =========================*/
/*================================================================================*/


std::ostream& operator<<(std::ostream& out, const Product& obj)
{
	out << "\n========================================================\n";
	out << "Name of product:\t\t" << obj.name << "\nCost of product:\t\t" << obj.cost << "\tBYN\nYear of product release:\t" << obj.yearOfManufacture;
	out << "\n========================================================\n";
	return out;
}

/*================================================================================*/
/*========================== Перегрузка оператора ввода ==========================*/
/*================================================================================*/


std::istream& operator>>(std::istream& in, Product& obj)
{
	char inName[100];
	double inCost;
	uint16_t inYear;
	std::cout << "\nEnter the product name:\t\t\t";
	in >> inName;
	std::cout << "Enter the price of the product:\t\t";
	in >> inCost;
	std::cout << "Enter the year of manufacture:\t\t";
	in >> inYear;

	char* Name = new char[strlen(inName) + 1];
	strcpy(Name, inName);

	obj.name = Name;
	obj.cost = inCost;
	obj.yearOfManufacture = inYear;
	return in;
}

/*================================================================================*/
/*======================= Перегрузка оператора сравнения == ======================*/
/*================================================================================*/

bool operator==(const Product& lhs, const Product& rhs) {
	// Сравниваем поля объектов lhs и rhs
	return (strcmp(lhs.getName(), rhs.getName()) == 0 &&
		lhs.getCost() == rhs.getCost() &&
		lhs.getYearOfManufacture() == rhs.getYearOfManufacture());
}
