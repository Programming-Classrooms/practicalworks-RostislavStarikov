#include "src/Functions/Functions.hpp"

int main()
{
	try
	{
		setlocale(LC_ALL, "RU");

		std::vector<int> vec; 
		int search;
		input(vec);
		std::sort(vec.begin(), vec.end());
		print(vec);

		// ##### 1 #####
		std::cout << "Сумма чисел вектора:\t\t" << sumOfVector(vec) << '\n';

		// ##### 2 #####
		std::cout << "Количество чисел векторa:\t" << amountOfNumbers(vec);
		
		// ##### 3 #####
		std::cout << "\nВведите число для подсчета сравнения с другими числами:\t";
		std::cin >> search;
		if (std::cin.fail()) throw std::runtime_error("Ошибка: Невереный ввод данных для пдсчета!!!\n");
		std::cout << "Количество чисел, равных заданному:\t" << operator==(search, vec) << '\n';
		
		// ##### 4 #####
		std::cout << "\nКоличество чисел, не равных заданному:\t" << operator!=(search, vec) << '\n';
		std::cout << "\nКоличество чисел, меньше заданного:\t" << operator<(search, vec) << '\n';
		std::cout << "\nКоличество чисел, меньше либо равных заданному:\t" << operator<=(search, vec) << '\n';
		std::cout << "\nКоличество чисел, больше заданного:\t" << operator>(search, vec) << '\n';
		std::cout << "\nКоличество чисел, больше либо равных заданному:\t" << operator>=(search, vec) << '\n';
	
		// ##### 5 #####
		std::cout << "\nЗаменa всех нулей средним арифметическим";
		averageArithmeticalWithoutZero(vec);
		
		// ##### 6 #####
		int start, end;
		std::cout << "\nДобавить к каждому элементу вектора сумму всех чисел из заданного интервала этого же вектора\nВведите начало интервала:\t";
		std::cin >> start;
		std::cout << "Введите конец интервала:\t";
		std::cin >> end;
		addToEachInInterval(vec, start, end);
		
		// ##### 7 #####
		std::cout << "\nЗамена всех чисел, модуль которых есть четное число, на разность максимального и минимального элемента этого вектора\n";
		replaceEven(vec);

		// ##### 8 #####
		std::cout << "\nУдаление из последовательности все равные по модулю числа, кроме первого из них\n";
		removeDuplicatesExceptFirstAbs(vec);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
