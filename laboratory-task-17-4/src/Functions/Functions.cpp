#include "Functions.hpp"

void checkFile(std::ofstream& fin)
{
	if (!fin.good())
	{
		throw std::runtime_error("File isn't exist \n"); //файл не найден
	}
	if (!fin)
	{
		throw std::runtime_error("Input file error \n"); //Ошибка открытия файла
	}
}

// Функция для записи вида рыб в файл
void writeFishToFile(std::ofstream& fin, const std::set<std::string>& fish) {
    for (const auto& f : fish) {
        fin << f << " ";
    }
}