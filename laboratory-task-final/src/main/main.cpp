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
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}	
	return 0;
}
