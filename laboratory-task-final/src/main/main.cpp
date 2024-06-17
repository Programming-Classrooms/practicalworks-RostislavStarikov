#include "../BusTrackVector/BusTrackVector.hpp"
#include "../BusTrack/BusTrack.hpp"
int main()
{
	try
	{
		BusTrackVector a;

		std::ifstream fin("src/main/data.txt");
		checkFile(fin);

		fin >> a;
		std::cout << a;

		std::cout << "\nПосле сортировки по номреру автобуса\n";
		a.SortByNumberBus();
		std::cout << a;
		
		std::cout << "\nСозданный map из векторов BusTrack\n";
		std::map<uint16_t, BusTrack> mapBusTrack;
		for (auto it : a.createMap(mapBusTrack))
		{
			std::cout << it.first << " : " << it.second << '\n';
		}

		std::cout << "\nСозданный set из всех маршрутов BusTrack\n";
		std::set<uint16_t> setBusTrack;
		for (auto it : a.createSet(setBusTrack))
		{
			std::cout << it << ' ';
		}

		int32_t numb;
		std::cout << "\nВведите номер маршрута для просмотра всех автобусов, следующих по нему:\t";
		std::cin >> numb;
		checkNumber(numb);
		a.outputFromTrack(numb);

		BusTrack delBus;
		std::cout << "\nВведите данные для удаления автобуса:(номер маршрута, водитель, номер автобуса, марка автобуса))\n";
		std::cin >> delBus;

		a.deleteByBus(delBus);
		std::cout << "\nВсе автобусы после удаления заданного автобуса:" << a;
		

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}	
	return 0;
}
