#include "../Functions/Functions.hpp"

int main()
{
	try
	{
		// Виды рыб пойманные каждым рыбаком
		std::set<std::string> fisher1 = {"лосось", "краснопёрка", "окунь"};
		std::set<std::string> fisher2 = {"карп", "щука"};
		std::set<std::string> fisher3 = {"краснопёрка", "щука"};

		// Все виды рыб в озере
		std::set<std::string> fishInLake = {"лосось", "карп", "краснопёрка", "окунь", "сом", "щука"};

		// Виды рыб пойманнык хотя бы одним рыбаком
		std::set<std::string> caughtFish;

		std::set_union	(fisher1.begin(), fisher1.end(),			// "Объединение" множества рыб
						fisher2.begin(), fisher2.end(),
						std::inserter(caughtFish, caughtFish.begin()));

		std::set_union	(caughtFish.begin(), caughtFish.end(),
						fisher3.begin(), fisher3.end(),
						std::inserter(caughtFish, caughtFish.begin()));

		// Виды рыб, которые есть в озере, но никто из рыбаков не поймал
		std::set<std::string> notCaughtFish;

		std::set_difference(fishInLake.begin(), fishInLake.end(),	// Вставляем в notCaughtFish элементы 
							caughtFish.begin(), caughtFish.end(),	// из fishInLake, не встречающихся в caughtFish
							std::inserter(notCaughtFish, notCaughtFish.begin()));

		std::ofstream fin("src/main/result.txt");
		checkFile(fin);

		fin << "Рыбы, пойманные первым рыбаком:\t";
		writeFishToFile(fin, fisher1);
		fin << "\nРыбы, пойманные вторым рыбаком:\t";
		writeFishToFile(fin, fisher2);
		fin << "\nРыбы, пойманные третьим рыбаком:\t";
		writeFishToFile(fin, fisher3);
		fin << "\nВсе виды пойманных рыб:\t";
		writeFishToFile(fin, caughtFish);
		fin << "\nРыбы, не пойманные никаким рыбаком:\t";
		writeFishToFile(fin, notCaughtFish);

		fin.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
