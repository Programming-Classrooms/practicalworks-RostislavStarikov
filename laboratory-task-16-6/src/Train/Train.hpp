#ifndef TRAIN_HPP
#define TRAIN_HPP


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdint.h>

enum class Train_type
{
	Passenger,
	Fast
};

class Train
{
private:
	uint32_t number;
	std::string nameStation;
	Train_type type;
	std::string departureTime;
	std::string travelTime;
public:
	// Конструкторы
	Train(uint32_t num = 1, std::string station = "Minsk", Train_type tp = Train_type::Passenger, std::string dpTime = "12:00", std::string trvlTime = "3:00");
	Train(const Train&);
	~Train();

	// Геттеры
	uint32_t getNumber() const;
	std::string getStation() const;
	Train_type getType() const;
	std::string getDepartureTime() const;
	std::string getTravelTime() const;

	// Сеттеры
	void setNumber(uint32_t&);
	void setStation(std::string&);
	void setType(Train_type&);
	void setDepartureTime(std::string&);
	void setTravelTime(std::string&);

	// Перегрузка операторов ввода и вывода
	friend std::istream& operator >> (std::istream&, Train_type&);
	friend std::istream& operator >> (std::istream&, Train&);
	friend std::ostream& operator << (std::ostream&, const Train&);

	friend std::ifstream& operator >> (std::ifstream&, Train&);

	bool operator<(const Train&);

};
	void sortTrains(std::vector<Train>&);
	void printVector(const std::vector<Train>&);
    void checkFile(std::ifstream&);
	void readFromFile(std::vector<Train>&, std::ifstream&);

	bool timeIsBetween(const Train&, const std::string& From, const std::string& To);
	void printFromTimeRange(const std::vector<Train>& TrainVector,const std::string& From,const std::string& To);

	bool inStation(const Train&, const std::string& station);
	void printFromNameStation(const std::vector<Train>& TrainVector, const std::string& nameStation);
	void printFastFromStation(const std::vector<Train>& TrainVector, const std::string& nameStation);

	Train findFastestTrainToStation(const std::vector<Train>& TrainVector, const std::string& nameStation);
#endif
