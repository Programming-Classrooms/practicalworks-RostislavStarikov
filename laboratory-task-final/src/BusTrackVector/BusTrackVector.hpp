#ifndef BUSTRACKVECTOR_HPP
#define BUSTRACKVECTOR_HPP

#include <vector>   // Для работы с вектором
#include <map>      // Для создания map
#include <set>      // Для создания set

#include "../BusTrack/BusTrack.hpp"

class BusTrackVector
{
private:
std::vector<BusTrack> Vector;

public:
BusTrackVector() = default;             // Конструктор по умолчанию
BusTrackVector(std::vector<BusTrack>&); // Конструктор с параметром
BusTrackVector(const BusTrackVector&);  // Конструктор копирования

void SortByNumberBus();  // Сортировка по номеру автобуса
void SortByNumberTrack();// Сортировка по номеру маршрута

std::map<uint16_t, BusTrack>& createMap(std::map<uint16_t, BusTrack>&); // Создание контейнера map
std::set<uint16_t>& createSet(std::set<uint16_t>&);                     // Создание контейнера set  

void outputFromTrack(uint16_t);                                // Вывод списка автобусов указанного маршрута

void deleteByBus(BusTrack&);                                   // Удаление из вектора определенного автобуса

std::vector<BusTrack> getVector() const;     // Геттер вектора

friend std::ostream& operator<<(std::ostream&, const BusTrackVector&);  // Перегрузка оператора вывода
friend std::istream& operator>>(std::istream&, BusTrackVector&);        // Перегрузка оператора ввода

};

#endif
