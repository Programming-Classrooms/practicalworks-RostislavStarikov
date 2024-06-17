#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <cstdint>
#include <iostream>

class Product
{
private:
	char* name;
	double cost;
	uint16_t yearOfManufacture;
public:
	// Конструкторы и деструктор
	Product();
	Product(const char*, double, uint16_t);
	Product(const Product&);
	~Product();

	// Геттеры

	char* getName() const;
	double getCost() const;
	uint16_t getYearOfManufacture() const;

	// Cеттер
	void setName(char*);
	void setCost(double);
	void setYearOfManufacture(uint16_t);

	// Вывод 
	friend std::ostream& operator<<(std::ostream&, const Product&);

	// Ввод
	friend std::istream& operator>>(std::istream&, Product&);


	// Перегрузка оператора сравнения == 
	friend bool operator==(const Product& ,const Product&);
};
#endif