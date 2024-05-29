#include "../Functions/Functions.hpp"

int main() 
{
	try
	{
		std::ifstream fin("src/main/data.txt"); 
		checkInputFile(fin);

		std::unordered_map<std::string, size_t> wordCount; 	// Для подсчета количества различных слов
		std::set<std::string> uniqueWords; 					// Для хранения уникальных слов

		std::string word;
		readFile(fin, word, wordCount, uniqueWords);
		
		fin.close(); 

		// Вывод списка всех слов
		std::cout << "Список всех слов:\n";
		for (const std::string& word : uniqueWords) {
			std::cout << word << "\n";
		}

		// Вывод количества различных слов
		std::cout << "\nКоличество вхождений каждого слова:\n";
		for (const auto& pair : wordCount) {
			std::cout << pair.first << ": " << pair.second << "\n";
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}	
    return 0;
}
