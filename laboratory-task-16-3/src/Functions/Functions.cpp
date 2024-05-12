#include "Functions.hpp"

void checkFile(std::ifstream& fin)
{
	std::cout << "Провека на существование файла:\t";
	if (!fin.good())
	{
		throw std::invalid_argument("Bad file!");
	}
	std::cout << "файл существует.\nПопытка открыть файл:\t";
	if (!fin)
	{
		throw std::invalid_argument("coudn't open file!");
	}
	std::cout << "файл успешно открыт.\nПроверка файла на заполненность:\t";
	if (fin.peek() == EOF)
	{
		fin.close();
		throw std::invalid_argument("File is empty!");
	}
	std::cout << "файл не пуст.";
}

void getText(std::vector<std::string>& vec, std::ifstream& fin)
{
	std::cout << "\nЧтение данных из файла в вектоp...";
	std::string take;
	while (fin >> take)
	{
		vec.push_back(take);
		take = "";
	}
}
void print(std::vector<std::string> vec)
{
	std::cout << "\nВектор строк:";
	std::cout << '\n';
	for (std::string str : vec)
	{
		std::cout << str << '\n';
	}
}

void Sort(std::vector<std::string>& vec)
{
	std::cout << "\nСортировка вектора...";
	quickSort(vec, 0, vec.size() - 1);
}

void quickSort(std::vector<std::string>& vec, size_t left, size_t right) {
	int i = left, j = right;
	std::string pivot = vec[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (vec[i] < pivot)
			i++;
		while (vec[j] > pivot)
			j--;
		if (i <= j) {
			std::swap(vec[i], vec[j]);
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(vec, left, j);
	if (i < right)
		quickSort(vec, i, right);
}

void Search(std::vector<std::string> vec, char c)
{
	std::cout << "Найденные слова на букву " << c << ":\n";
	for (std::string n : vec)
	{
		[n, c]() {std::cout << (n[0] == c ? n + '\n' : ""); }();
	}
}

void Delete(std::vector<std::string>& vec, char c)
{
	std::cout << "Удаление слов на букву " << c << "...";
	auto iterator = vec.begin();
	while (iterator != vec.end())
	{
		if ((*iterator)[0] == c)
		{
			vec.erase(iterator);
		}
		++iterator;
	}
}
