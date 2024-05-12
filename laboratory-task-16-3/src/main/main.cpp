#include "src/Functions/Functions.hpp"
int main()
{
	try
	{
		setlocale(LC_ALL, "RU");
		std::vector<std::string> vec{};
		char search, deleteWords;

		std::ifstream fin("src/Functions/Text.txt");
		std::cout << "Проверка файла...\n";
		checkFile(fin);
		getText(vec, fin);
		print(vec);
		Sort(vec);
		print(vec);
		std::cout << "\nВведите букву для поиска слов по первой букве:\t";
		std::cin >> search;
		Search(vec, search);
		std::cout << "\n\nВведите букву для удаления слов по первой букве:\t";
		std::cin >> deleteWords;
		Delete(vec, deleteWords);
		std::cout << "\nИтоговый вектор:";
		print(vec);
	}
	catch (const std::exception& m)
	{
		std::cerr << "\nError: " << m.what() << '\n';
	}
}
