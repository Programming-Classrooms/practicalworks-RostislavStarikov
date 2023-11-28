
/*Вариант 29
В одномерном массиве, состоящем из n вещественных элементов, вычислить:
-длину самой длинной упорядоченной цепочки подряд идущих элементов;
-произведение элементов массива, расположенных между максимальным по модулю и
минимальным по модулю элементами.
Упорядочить элементы на четных местах массива по убыванию, а на нечтных местах по
возрастанию.*/

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::swap;

//Вводим число элементов
void chek_size(double& size)  
{
	cout << "Enter size of array: ";
	try 
	{
		cin >> size;
		if (size < 0 && size != static_cast<int32_t>(size))//Проверка на целое число
		{
			throw size;
		}
		
	}
	catch (double size)
	{

		cout << "Uncorrect size!!!\n";
		chek_size(size);
	}
	static_cast<int32_t>(size);
}

//Выбор способа заполнения массива
bool arrayFillType(char way)
{
	switch (way)
	{
	case '1':
		return false;
		break;
	case '2':
		return true;
		break;
	default:
			cout << "Choose how to fill the array: \n\t\t\t\t    1.Filling with random values from a range [a,b]\n\t\t\t\t    2.Filling an array with the keyboard\n";
			cin >> way;
			return  arrayFillType(way);
	}
}

//Заполнение массива
void arrayFill(int32_t size, double* arr, int32_t way) {
	double a, b;
	if (arrayFillType(way)) {
		cout << "\n" << "Enter elements on keyboard: ";
		for (uint32_t i = 0; i < size; i++) cin >> arr[i];			//Заполнение массива с клавиатуры
	}
	else {
		cout << "Enter range [a,b] : \n a = ";
		cin >> a;
		cout << "\n b = ";
		cin >> b;
		if (a == b)
		{
			cout << "\n Invalid value!!!\n";
			arrayFill(size, arr, way);
		}
		if (b < a)
		{
			swap(a, b);
		}
		cout << "\nSelect the type of numbers: \n\t\t\t\t    1.Filling with reals\n\t\t\t\t    2.Filling with integer\n";
		char way_number;
		cin >> way_number;
		switch (way_number)
		{
		case '1':
			a *= 10;
			b *= 10;
			for (uint32_t i = 0; i < size; i++)
			{				//Ввод элементов рандомом
				double temp = ((rand() % ((int32_t)b - (int32_t)a + 1) + (int32_t)a));
				arr[i] = temp / 10;
			}
			break;
		case '2':
			for (uint32_t i = 0; i < size; i++)
			{
				arr[i] = (rand() % ((int32_t)b - (int32_t)a + 1) + (int32_t)a);
			}
			break;
		default:
			cout << "\nIvalid value!!!\n";
			arrayFill(size, arr, way);
			break;
		}
	}
}

//Вывод массива
void arrayOutput(int32_t size, double* arr) {
	for (uint32_t i = 0; i < size; i++) {
		cout << " | " << arr[i];
	}
	cout << " | ";
	cout << "\n";
}

//Нахождение упорядоченной цепочки
void orderedChain(int32_t size, double* arr, int32_t len = 1, int32_t max_len = 1) {
	for (uint32_t i = 0; i < size; i++)			//Проверка всего массива 
	{
		if (arr[i] <= arr[i + 1])			//сравнение очередного и следующего элемента массива
		{
			len += 1;
		}
		else {
			if (len > max_len) {
				max_len = len;
				len = 1;
			}
		}
	}
	cout << "\n" << "The length of the longest ordered chain of consecutive elements:" << max_len << " elements." << "\n";
}

//Нахождение минимального и максимального по модулю элемента и произведения
void findMaxMinEl(int32_t size, double* arr, int32_t min_ind, int32_t max_ind, double long result) {
	for (uint32_t i = 1; i < size; i++)			//Проверка всего массива для макс и мин элементов
	{
		if (abs(arr[i]) > abs(arr[max_ind]))	//Нахождение индекса минимального по модуля элемента
		{
			max_ind = i;
		}
		if (abs(arr[i]) < abs(arr[min_ind]))
		{
			min_ind = i;

		}
	}
	cout << "\n" << "The minimum modulo element" << arr[min_ind] << ". \nThe maximum modulo element" << arr[max_ind] << "\n";


	//нахождение произведения 
	if (min_ind < max_ind)
	{
		if ((max_ind - min_ind) == 2)
		{
			cout << "There is only one element between the maximum modulo element and the minimum modulo element \n";
		}
		else {
			while ((min_ind + 1) < max_ind)
			{
				result *= arr[min_ind + 1];
				min_ind++;
			}
			if (result == 1)
			{
				cout << "There are NO elements between the maximum modulo element and the minimum modulo element\n";
			}
			else
			{
				cout << "\n" << "The product of the array elements located between the maximum modulo and minimum modulo elements =" << result << '\n';
			}
		}
	}
	else
	{
		if ((min_ind - max_ind) == 2)
		{
			cout << "There is only one element between the maximum modulo element and the minimum modulo element\n";
		}
		else {
			while ((min_ind - 1) > max_ind)
			{
				result *= arr[max_ind + 1];
				max_ind++;
			}
			if (result == 1)
			{
				cout << "There are NO elements between the maximum modulo element and the minimum modulo element\n";
			}
			else
			{
				cout << "\n" << "The product of the array elements located between the maximum modulo and minimum modulo elements =" << result << '\n';
			}
		}
	}
}

			//Расположение элементов на четных местах массива по убыванию, а на неч тных местах по возрастанию.

//Сортировка элементов на четных местах по убыванию
void evenInd(int32_t size, double* arr)
{
	cout << "\nThe arrangement of elements in even places of the array in descending order, and in odd places in ascending order.\n";
	for (uint32_t i = 0; i < size; i += 2)
	{
		for (uint32_t j = i + 2; j < size; j += 2)
		{
			if (arr[i] < arr[j])
			{
				swap(arr[i], arr[j]);
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
				swap(arr[i], arr[j]);
			}
		}
}

//Вывод конечного массива
void finalArrayOutput(int32_t size, double* arr)
{
	evenInd(size, arr);
	oddInd(size, arr);
	cout << "\nModified array" << "\n";
	arrayOutput(size, arr);
	cout << "\n";
}


int32_t main()
{

	srand(time(NULL));
	double size = 0;
	int32_t len, max_len,min_ind = 0, max_ind = 0;
	char way = '0';
	char way_number = '0';
	double long result = 1;	
	chek_size(size);
	double* arr = new double[size];
	cout << "Choose how to fill the array: \n\t\t\t\t    1.Filling with random values from a range [a,b]\n\t\t\t\t    2.Filling an array with the keyboard\n";
	cin >> way;
	arrayFillType(way);
	arrayFill(size, arr, way);
	cout << "Entered array" << "\n";
	arrayOutput(size, arr);
	orderedChain(size, arr, len = 1, max_len = 1);
	findMaxMinEl(size, arr, min_ind, max_ind, result);
	finalArrayOutput(size, arr);
	delete[]arr;

	return 0;
}
	
