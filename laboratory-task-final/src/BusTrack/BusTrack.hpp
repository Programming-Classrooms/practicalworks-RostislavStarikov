#ifndef BUSTRACK_HPP
#define BUSTRACK_HPP

#include <iostream> // Для std::cout, std::cerr
#include <fstream>  // Для std::ifstream, std::ofstream
#include <stdint.h> // Для uint16_t
#include <string>   // Для работы со строками
#include <exception>// Для квалификации ошибок

class BusTrack
{
private:
uint16_t NumberTrack;
std::string Driver;
uint16_t NumberBus;
std::string BrandBus;

public:

BusTrack();                                                 // Конструктор по умолчанию и с параметрами
BusTrack(uint16_t, std::string&, uint16_t, std::string&);   // Конструктор с параметрами
BusTrack(const BusTrack&);                                  // Конструктор копирования
~BusTrack() = default;                                      // Деструктор

void setNumberTrack(uint16_t);      // Сеттер номера маршрута
void setNumberBus(uint16_t);        // Сеттер номера автобуса
void setDriver(std::string&);       // Сеттер фамилии водителя
void setBrandBus(std::string&);     // Сеттер марки автобуса

uint16_t getNumberTrack() const;    // Геттер номера маршрута
uint16_t getNumberBus() const;      // Геттер номера автобуса
std::string getDriver() const;      // Геттер фамилии водителя
std::string getBrandBus() const;    // Геттер марки автобуса

bool operator==(BusTrack&);         // Перегрузка оператора сравнения
friend std::ostream& operator<<(std::ostream&, const BusTrack&);    // Перегрузка оператора <<
friend std::istream& operator>>(std::istream&, BusTrack&);    // Перегрузка оператора >>


};
uint16_t checkNumber(int32_t);
void checkFile(std::ifstream&);

#endif
