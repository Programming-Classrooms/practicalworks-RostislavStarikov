#include "Train.hpp"

void checkTime(const std::string& time)
{
	int hours, minutes;
	size_t colonPos = time.find(':');

	if (colonPos == std::string::npos || colonPos == 0) {
		throw std::invalid_argument("Неверный формат времени!!!");
	}
	
	hours = std::stoi(time.substr(0, colonPos));
	minutes = std::stoi(time.substr(colonPos + 1));

	if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) 
	{
		throw std::invalid_argument("Неверный формат времени!!!");
	}
}

/*================================================================================*/
/*=========================== Конструктор и деструктор ===========================*/
/*================================================================================*/

Train::Train(uint32_t num, std::string station, Train_type tp, std::string dpTime, std::string trvlTime):number(num),nameStation(station), type(tp), departureTime(dpTime), travelTime(trvlTime)
{
	setlocale(LC_ALL, "RU");
}
Train::Train(const Train& rhs) : number(rhs.number), nameStation(rhs.nameStation), type(rhs.type), departureTime(rhs.departureTime), travelTime(rhs.travelTime) {}
Train::~Train(){}

/*================================================================================*/
/*==================================== Геттеры ===================================*/
/*================================================================================*/

uint32_t Train::getNumber() const
{
	return number;
}

std::string Train::getStation() const
{
	return nameStation;
}

Train_type Train::getType() const
{
	return type;
}

std::string Train::getDepartureTime() const
{
	return departureTime;
}

std::string Train::getTravelTime() const
{
	return travelTime;
}


/*================================================================================*/
/*==================================== Сеттеры ===================================*/
/*================================================================================*/

void Train::setNumber(uint32_t& input)
{
	number = input;
}

void Train::setStation(std::string& input)
{
	nameStation = input;
}

void Train::setType(Train_type& input)
{
	type = input;
}

void Train::setDepartureTime(std::string& input)
{
	departureTime = input;
}

void Train::setTravelTime(std::string& input)
{
	travelTime = input;
}



std::istream& operator >> (std::istream& in, Train_type& type) {
	int input;
	in >> input;
	if (input == 1)	type = Train_type::Passenger;
	else if (input == 2) type = Train_type::Fast;
	return in;
}

std::istream& operator>>(std::istream& in, Train& obj)
{
	int temp;
	std::cout << "Введите номер поезда:\t\t\t\t\t";
	in >> obj.number;
	std::cout << "Введите название пункта прибытия поезда:\t\t";
	in >> obj.nameStation; 
	std::cout << "Введите тип поезда (Пассажирский - 0, Скорый - 1):\t";
	in >> temp;
	obj.type = temp? Train_type::Passenger : Train_type::Fast;
	std::cout << "Введите время отправления поезда в формате ЧЧ:ММ:\t";
	in >> obj.departureTime;
	checkTime(obj.departureTime);
	std::cout << "Введите в пути поезда в формате ЧЧ:ММ:\t\t\t";
	in >> obj.travelTime;
	checkTime(obj.travelTime);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Train& obj)
{
	out << "\n=======================================================\n";
	out << "Номер поезда:\t\t\t" << obj.number;
	out << "\nНазвание пункта назначения:\t" << obj.nameStation;
	out << "\nТип поезда:\t\t\t" << (obj.type == Train_type::Fast ? "Скорый" : "Пассажирский");
	out << "\nВремя отправления:\t\t" << obj.departureTime;
	out << "\nВремя в пути:\t\t\t" << obj.travelTime;
	out << "\n=======================================================\n";
	return out;
}

std::ifstream& operator>>(std::ifstream& fin, Train& obj)
{
	int temp;
	fin >> obj.number;
	fin >> obj.nameStation;
	fin >> temp;
	obj.type = temp ? Train_type::Passenger : Train_type::Fast;
	fin >> obj.departureTime;
	checkTime(obj.departureTime);
	fin >> obj.travelTime;
	checkTime(obj.travelTime);

	return fin;
}

bool Train::operator<(const Train& other)
{
	return this->departureTime < other.departureTime;
}

void sortTrains(std::vector<Train>& trains)
{
	std::cout << "\nСортировка данных по времени отправления поездов...";
	std::sort(trains.begin(), trains.end());
}

void printVector(const std::vector<Train>& trains)
{
	for (const auto& el : trains)
	{
		std::cout << el;
	}
}

//Проверка файла
void checkFile(std::ifstream& fin)
{
	if (!fin.good())
	{
        throw std::runtime_error("File isn't exist"); //файл не найден
	}
	if (!fin)
	{
        throw std::runtime_error("Input file error"); //Ошибка открытия файла
	}
    if (fin.peek() == EOF)
    {
        throw std::runtime_error("File is empty"); //файл пустой
    }
}

void readFromFile(std::vector<Train>& trains, std::ifstream& fin)
{

	size_t i = 0;
	Train temp;

	while (fin >> temp)
	{
		trains.push_back(temp);
	}
}

bool timeIsBetween(const Train& train, const std::string& from, const std::string& to)
{
	// Извлекаем часы и минуты из строки времени отправления поезда
	int fromHours = std::stoi(from.substr(0, from.find(':')));
	int fromMinutes = std::stoi(from.substr(from.find(':') + 1));
	int toHours = std::stoi(to.substr(0, to.find(':')));
	int toMinutes = std::stoi(to.substr(to.find(':') + 1));
	int timeHours = std::stoi(train.getDepartureTime().substr(0, train.getDepartureTime().find(':')));
	int timeMinutes = std::stoi(train.getDepartureTime().substr(train.getDepartureTime().find(':') + 1));

	// Проверяем, находится ли время отправления поезда между заданными интервалами
	if (((fromHours < timeHours || (fromHours == timeHours && fromMinutes <= timeMinutes)) &&  (timeHours < toHours || (timeHours == toHours && timeMinutes <= toMinutes))))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void printFromTimeRange(const std::vector<Train>& trains,const std::string& from,const std::string& to)
{
	checkTime(from);
	checkTime(to);
	Train temp;
	for (const auto& iterator : trains)
	{
		if (timeIsBetween(iterator, from, to))
		{
			std::cout << iterator;
		}
	}
}

bool inStation(const Train& iterator, const std::string& nameStation)
{
	return (iterator.getStation() == nameStation);
}

void printFromNameStation(const std::vector<Train>& TrainVector, const std::string& nameStation)
{
	bool noFind = true;
	std::cout << "Все поезда идущие до станции " << nameStation << ":\n";
	for (const auto& iterator : TrainVector)
	{
		if (inStation(iterator, nameStation))
		{
			std::cout << iterator;
			noFind = false;
		}
	}
	if (noFind) std::cout << "\nНет поездов с заданным пунктом назначения\n";
}

void printFastFromStation(const std::vector<Train>& TrainVector, const std::string& nameStation)
{
	bool noFind = true;
	std::cout << "Все скоростные поезда идущие до станции " << nameStation << ":\n";
	for (const auto& iterator : TrainVector)
	{
		if (inStation(iterator, nameStation) && iterator.getType() == Train_type::Fast)
		{
			std::cout << iterator;
			noFind = false;
		}
	}
	if (noFind) std::cout << "\nНет скоростных поездов с заданным пунктом назначения\n";
}

Train findFastestTrainToStation(const std::vector<Train>& TrainVector, const std::string& nameStation)
{
	Train fastestTrain(123, "Temp", Train_type::Passenger, "00:00", "99:99"); 
	bool found = false;

	for (const auto& train : TrainVector)
	{
		if (inStation(train, nameStation))
		{
			if (train.getTravelTime() < fastestTrain.getTravelTime())
			{
				fastestTrain = train;
				found = true;
			}
		}
	}

	if (!found) throw std::invalid_argument("Нет поездов до указанного пункта назначения.");
	return fastestTrain;
}
