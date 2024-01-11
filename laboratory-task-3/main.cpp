
/*
	Вариант 29
	В одномерном массиве, состоящем из n вещественных элементов, вычислить:
	-длину самой длинной упорядоченной цепочки подряд идущих элементов;
	-произведение элементов массива, расположенных между максимальным по модулю и
	минимальным по модулю элементами.
	Упорядочить элементы на четных местах массива по убыванию, а на нечтных местах по
	возрастанию.
*/

#include <iostream>
#include <cmath>


//Вводим число элементов
void checkSize(double& checkedSize)  
{
	std::cout << "Enter size of array: ";
	std::cin >> checkedSize;
	if (std::cin.fail() || checkedSize < 0 || checkedSize != static_cast<int32_t>(checkedSize))//Проверка на целое число
	{
		throw std::runtime_error("Uncorrect size!!!\n");
	}		
}

//Выбор способа заполнения массива
bool selectingArrayInputMethod(char way)
{
	switch (way)
	{
	case '1':
		return true;
		break;
	case '2':
		return false;
		break;
	default:
			throw std::runtime_error("Uncorrect type of fill array!!!");
	}
}

//Заполнение массива
void inputFromKeyboard(int32_t size, double* arr)
{
	std::cout << "\n" << "Enter elements on keyboard: ";
	for (uint32_t i = 0; i < size; i++) std::cin >> arr[i];			//Заполнение массива с клавиатуры
}

void inputRandom (int32_t size, double* arr)
{
	double leftBorder, rightBorder;
	std::cout << "Enter range [a,b] : \n a = ";
	std::cin >> leftBorder;
	std::cout << "\n b = ";
	std::cin >> rightBorder;

	if (leftBorder == rightBorder)
	{
		throw std::runtime_error("\nUncorrect border value (left and right borders are equal)\n");
	}
	if (leftBorder < rightBorder)
	{
		std::swap(leftBorder, rightBorder);
	}

	std::cout << "\nSelect the type of numbers: \n\t\t\t\t    1.Filling with reals\n\t\t\t\t    2.Filling with integer\n";
	char way_number;
	std::cin >> way_number;
	switch (way_number)
	{
	case '1':
		leftBorder *= 10;
		rightBorder *= 10;
		for (uint32_t i = 0; i < size; i++)
		{				//Ввод элементов рандомом
			double temp = ((rand() % static_cast<uint32_t>(rightBorder) - static_cast<uint32_t>(leftBorder) + 1) + static_cast<int32_t>(leftBorder));
			arr[i] = temp * 0.1;
		}
		break;
	case '2':
		for (uint32_t i = 0; i < size; i++)
		{
			arr[i] = (rand() % (static_cast<int32_t>(rightBorder) - static_cast<int32_t>(leftBorder) + 1) + static_cast<int32_t>(rightBorder));
		}
		break;
	default:
		throw std::runtime_error("\nUncorrect value in choosing the type of numbers to be filled in randomly\n");
	}
}

//Вывод массива
void printArray(int32_t size, double* arr) {
	for (uint32_t i = 0; i < size; i++) {
		std::cout << " | " << arr[i];
	}
	std::cout << " | ";
	std::cout << "\n";
}

//Нахождение упорядоченной цепочки
void findOrderedChain(int32_t size, double* arr, int32_t len , int32_t &maxLen) {
	for (uint32_t i = 0; i < size; i++)			//Проверка всего массива 
	{
		if (arr[i] <= arr[i + 1])			//сравнение очередного и следующего элемента массива
		{
			len += 1;
		}
		else {
			if (len > maxLen) {
				maxLen = len;
				len = 1;
			}
		}
	}
}

//Нахождение минимального и максимального по модулю элемента и произведения
void findMaxMinEl(int32_t size, double* arr, int32_t &minInd, int32_t &maxInd, double long result) {
	for (uint32_t i = 1; i < size; i++)			//Проверка всего массива для макс и мин элементов
	{
		if (abs(arr[i]) > abs(arr[maxInd]))	//Нахождение индекса минимального по модуля элемента
		{
			maxInd = i;
		}
		if (abs(arr[i]) < abs(arr[minInd]))
		{
			minInd = i;
		}
	}


	//нахождение произведения 
	if (minInd < maxInd)
	{
		if ((maxInd - minInd) == 2)
		{
			std::cout << "There is only one element between the maximum modulo element and the minimum modulo element \n";
		}
		else {
			while ((minInd + 1) < maxInd)
			{
				result *= arr[minInd + 1];
				minInd++;
			}
			if (result == 1)
			{
				std::cout << "There are NO elements between the maximum modulo element and the minimum modulo element\n";
			}
			else
			{
				std::cout << "\n" << "The product of the array elements located between the maximum modulo and minimum modulo elements =" << result << '\n';
			}
		}
	}
	else
	{
		if ((minInd - maxInd) == 2)
		{
			std::cout << "There is only one element between the maximum modulo element and the minimum modulo element\n";
		}
		else {
			while ((minInd - 1) > maxInd)
			{
				result *= arr[maxInd + 1];
				maxInd++;
			}
			if (result == 1)
			{
				std::cout << "There are NO elements between the maximum modulo element and the minimum modulo element\n";
			}
			else
			{
				std::cout << "\n" << "The product of the array elements located between the maximum modulo and minimum modulo elements =" << result << '\n';
			}
		}
	}
}

			//Расположение элементов на четных местах массива по убыванию, а на неч тных местах по возрастанию.

//Сортировка элементов на четных местах по убыванию
void evenInd(int32_t size, double* arr)
{
	for (uint32_t i = 0; i < size; i += 2)
	{
		for (uint32_t j = i + 2; j < size; j += 2)
		{
			if (arr[i] < arr[j])
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}
}

// Сортировка элементов на нечетных местах по возрастанию
void oddInd(int32_t size, double* arr) {
	for (uint32_t i = 1; i < size; i += 2)
		for (uint32_t j = i + 2; j < size; j += 2)
		{
			if (arr[i] > arr[j])
			{
				std::swap(arr[i], arr[j]);
			}
		}
}

int32_t main()
{
	try
	{
	srand(time(NULL));

	double chekedSize = 0;
	int32_t len = 1, maxLen = 1,minInd = 0, maxInd = 0;
	char way = '0';
	char way_number = '0';
	double long result = 1;	

	checkSize(chekedSize);

	uint32_t size = static_cast<int32_t>(chekedSize);
	double* arr = new double[size];

	std::cout << "Choose how to fill the array: \n\t\t\t\t    1.Filling with random values from a range [a,b]\n\t\t\t\t    2.Filling an array with the keyboard\n";
	std::cin >> way;

	if (selectingArrayInputMethod(way))
	{
		inputRandom(size, arr);
	}
	else
	{
		inputFromKeyboard(size, arr);
	}

	std::cout << "Entered array" << "\n";
	printArray(size, arr);
	
	findOrderedChain(size, arr, len, maxLen);
	std::cout << "\n" << "The length of the longest ordered chain of consecutive elements:" << maxLen << " elements." << "\n";
	
	findMaxMinEl(size, arr, minInd, maxInd, result);
	std::cout << "\n" << "The minimum modulo element " << arr[minInd] << ". \nThe maximum modulo element " << arr[maxInd] << "\n";

	std::cout << "\nThe arrangement of elements in even places of the array in descending order, and in odd places in ascending order.\n";
	evenInd(size, arr);
	oddInd(size, arr);
	std::cout << "\nModified array" << "\n";
	printArray(size, arr);
	std::cout << "\n";

	delete[]arr;
	}

	catch (const char* msg)
	{
		std::cerr << msg;
		return -1;	
	}
	return 0;
}
