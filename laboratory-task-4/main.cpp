/*В целочисленной квадратной матрице N x N (3<=n<=101, n - нечетное)

найти номер первого из столбцов, не содержащих отрицательных элементов;
Начиная с центра, обойдите по спирали все элементы квадратной матрицы, выведя
их в обход. Обход выполняйте против часовой стрелки, первый ход —
вверх.*/
#include <iostream>


void checkSize(double& size)
{
	std::cout << "Enter the odd size of the square matrix: ";
	std::cin >> size;
	if ( size != static_cast<int32_t>(size) || static_cast<int32_t>(size) % 2 == 0 || 3>size || size>101)
	{
		throw "Incorrect size";
	}
	static_cast<int32_t>(size);
}

void createMatrix(int32_t** arr, uint32_t rows, uint32_t cols)
{
	for (int i = 0; i < rows; ++i)
	{
		arr[i] = new int32_t[cols];
	}
}

//Выбор способа заполнения матрицы
bool matrixFillType(char& way)
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
		throw "Incorrect type of fill array!!!";
	}
}

//Filling out the matrix
void fillRand(int32_t** arr, uint32_t rows, uint32_t cols, char way)
{
	int32_t leftBorder, rightBorder;
	std::cout << "Enter range [leftBorder,rightBorder] : \nLeft border = ";
	std::cin >> leftBorder;
	std::cout << "\nRight border = ";
	std::cin >> rightBorder;
	if (leftBorder != static_cast<int32_t>(leftBorder) || rightBorder != static_cast<int32_t>(rightBorder) || leftBorder == rightBorder)
	{
		throw "Incorrect border!!";
		exit(-1);
	}
	if (rightBorder < leftBorder)
	{
		std::swap(leftBorder, rightBorder);
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			arr[i][j] = rand()%(rightBorder-leftBorder+1)+leftBorder;
		}
	}
}

void fillFromKeyboard(int32_t** arr, uint32_t rows, uint32_t cols, char way)
{
	std::cout << "\n" << "Enter integer elements of matrix \n";
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			double temp = 0;
			std::cin >> temp;
			if (temp != static_cast<int32_t>(temp))
			{
				throw "Your elment in matrix must be integer";
			}
			arr[i][j] = static_cast<int32_t>(temp);
		}
	}			
}

void printMatrix(int32_t** arr, uint32_t rows, uint32_t cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << '\t';
		}
		std::cout << '\n'; 
	}
}

bool chekNegativCols(int32_t** arr, uint32_t rows, uint32_t cols, uint32_t &collWithNegativeElements)
{
	int32_t j;
	bool flag;
	for (j = 0; j < cols; ++j) 
	{
		flag = true;
		for (int i = 0; i < rows; ++i)
		{
			if (arr[i][j] < 0) 
			{
				flag = false;
				break; 
			}
		}
		if (flag)
		{
		collWithNegativeElements = j;
		return true;
		}
	}
	return false;
}


void spiralTraversalOfTheMatrix(int32_t** arr, uint32_t rows, uint32_t cols)
{
	uint32_t shift = 0; 			//объявляем переменную, в которой хранится величина шага при обходе по спирали 
	uint32_t i = rows / 2, j = cols / 2;	//устанавливаем координаты центрального элемента матрицы
 	//цикл обхода 
 	do 
	{
		++shift;									//увеличиваем величину шага на 1  
		for (int m = 0; m < shift; m++)							//выводим n элементов со шагом вверх
   	 	std::cout << arr[i--][j] << ' ';
		if (shift == rows)								//если шаг равен размерности массива
		break;										//выход  
		for (int m = 0; m < shift; m++)							//выводим n элементов со шагом влево
   		std::cout << arr[i][j--] << ' ';  
		++shift;									//опять увеличиваем шаг
 		for (int m = 0; m < shift; m++)							//выводим n элементов со шагом вниз   
		std::cout << arr[i++][j] << ' ';
		for (int m = 0; m < shift; m++)							//выводим n элементов со шагом вправо   
		std::cout << arr[i][j++] << ' ';
 	} 
	while (shift != rows); 									//пока шаг не станет равен размерности массива
}

void arrMemFree(int32_t** arr, uint32_t rows, uint32_t cols)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] arr[i];
	}
	delete[]arr;
}

int32_t main()
{
try
	{
		char way = 2;

		double n = 0;
		checkSize(n);

		uint32_t collWithNegativeElements = 0;
		uint32_t rows = n;
		uint32_t cols = n;

		int32_t **arr = new int32_t* [rows];//создание массива указателей на массивы	

		createMatrix(arr, rows, cols);
		std::cout << "Select how to fill the array: \n\t\t\t\t    1.Entering elements randomly from a range[a,b]\n\t\t\t\t    2.Entering items from the keyboard\n";
		std::cin >> way;

		if (matrixFillType(way))
		{
			fillRand(arr, rows, cols, way);
		}
		else
		{
			fillFromKeyboard(arr, rows, cols, way);
		}
			
		printMatrix(arr, rows, cols);
			
		if (chekNegativCols(arr, rows, cols, collWithNegativeElements))
		{	
			std::cout << "The number of the first column that does not contain negative elements:" << collWithNegativeElements + 1 << "\n\n";
		}
		else
		{
			std::cout << "Each column contains leftBorder negative element\n\n";
		}
			
		spiralTraversalOfTheMatrix(arr, rows, cols);
			
		arrMemFree(arr, rows, cols);
		
		return 0;
	}
	catch (const char* &msg)
		{
			std::cerr << msg;
			return -1;
		}
}
