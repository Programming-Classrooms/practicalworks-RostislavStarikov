#include "src/Train/Train.hpp"
int main()
{
	try
	{
		std::vector<Train> trains;
		std::ifstream fin("src/Train/data.txt");
		checkFile(fin);
		
		readFromFile(trains, fin);
		printVector(trains);
		sortTrains(trains);
		printVector(trains);

		std::string from, to;
		std::cout << "Для вывода информации о поездах из заданного диапазона времени, введите диапазон:\nОт:\t";
		std::cin >> from;
		std::cout << "До:\t";
		std::cin >> to;

		printFromTimeRange(trains, from, to);

		std::string station;
		std::cout << "Введите название искомой станции:\t";
		std::cin >> station;
		printFromNameStation(trains, station);

		std::cout << "\nВведите название станции для поиска скоростных поездов, идущих до заданной станции:\t";
		std::cin >> station;
		printFastFromStation(trains, station);
	
		std::cout << "\nВведите название станции для поиска самого быстрого поезда, идущего до заданной станции:\t";
		std::cin >> station;
		std::cout << findFastestTrainToStation(trains, station);
		
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
