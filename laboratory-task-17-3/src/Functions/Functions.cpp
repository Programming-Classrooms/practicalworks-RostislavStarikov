#include "Functions.hpp"


void checkInputFile(std::ifstream& fin)
{
	if (!fin.good())
	{
		throw std::runtime_error("File isn't exist \n"); //файл не найден
	}
	if (!fin)
	{
		throw std::runtime_error("Input file error \n"); //Ошибка открытия файла
	}
	if (fin.peek() == EOF)
	{
		throw std::runtime_error("File is empty \n"); //файл пустой
	}
}

void readFile(std::istream& fin, std::string& word, std::unordered_map<std::string, size_t>& wordCount, std::set<std::string>& uniqueWords)
{
    while (fin >> word) 
	{
        for (char& c : word) {
            c = std::tolower(c);
        }

        if (!word.empty() && ispunct(*word.rbegin())) 
        {
            word.pop_back(); 
        }

        if (!word.empty()) {
            wordCount[word]++;
            uniqueWords.insert(word);
        }
    }
}