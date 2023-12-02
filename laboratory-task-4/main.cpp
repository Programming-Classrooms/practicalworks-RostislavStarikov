#include <iostream>


using std::cin;
using std::cout;


void chekN(double& n)
{
	try
	{
		cout << "Enter the odd size of the square matrix: ";
		cin >> n;
		if ( n != static_cast<int32_t>(n) || static_cast<int32_t>(n) % 2 == 0 || 3>n || n>101)
		{
			throw n;
		}
	}
	catch (double n)
	{		

		cout << "Uncorrect size!!!\n";
		exit(-1);
	}
	static_cast<int32_t>(n);
}

void create_matrix(int32_t** arr, uint32_t rows, uint32_t cols)
{
	for (int i = 0; i < rows; ++i)
	{
		arr[i] = new int32_t[cols];
	}
}

//Выбор способа заполнения матрицы
bool MatrixFillType(char& way)
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
		setlocale(LC_ALL, "Rus");
		cout << "Select how to fill the array: \n\t\t\t\t    1.Entering elements randomly from a range[a,b]\n\t\t\t\t    2.Entering items from the keyboard\n";
		cin >> way;
		return  MatrixFillType(way);
	}
}

//Filling out the matrix
void fillMatrix(int32_t** arr, uint32_t rows, uint32_t cols, char way) {
	int32_t a, b;
	if (MatrixFillType(way)) {							//filling the matrix from the keyboard
		cout << "\n" << "Enter integer elements of matrix \n";
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				try
				{
					double temp = 0;
					cin >> temp;
					if (temp != static_cast<int32_t>(temp))
					{
						throw (temp);
					}
					arr[i][j] = static_cast<int32_t>(temp);
				}
				catch (double temp)
				{
					cout << "Invalid value!!!";
					exit(-1);
				}
			}
		}			
	}
	else {
		cout << "Enter range [a,b] : \n a = ";
		cin >> a;
		if (a!=static_cast<int32_t>(a))
		{
			cout << "Invalid value!!!";
			exit(-1);
		}
		cout << "\n b = ";
		cin >> b;
		if (a!=static_cast<int32_t>(b))
		{
			cout << "Invalid value!!!";
			exit(-1);
		}
		if (a == b)
		{
			cout << "\n Invalid value!!!\n";
			fillMatrix(arr, rows, cols, way);
		}
		if (b < a)
		{
			std::swap(a, b);
		}
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				arr[i][j] = rand()%(b-a+1)+a;
			}
		}
	}
}

void outputMatrix(int32_t** arr, uint32_t rows, uint32_t cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << '\n'; 
	}
}

void chekNegativCols(int32_t** arr, uint32_t rows, uint32_t cols)
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
			if (flag == true)
			break;
		}
	}

	if (flag == true)
	cout << "The number of the first column that does not contain negative elements:" << j+1 << "\n\n";
	else
		cout << "Each column contains a negative element\n\n";
}


void bypass(int32_t** arr, uint32_t rows, uint32_t cols)
{
 	uint32_t shift = 0;	//объявляем переменную, в которой хранится величина шага при обходе по спирали uint32_t i = rows / 2, j = cols / 2;//устанавливаем координаты центрального элемента матрицы
 	//цикл обхода 
 	do 
	{
		shift++;												//увеличиваем величину шага на 1  
		for (int m = 0; m < shift; m++)							//выводим n элементов со шагом вверх
   	 	cout << arr[i--][j] << ' ';  if (shift == rows)			//если шаг равен размерности массива
		break;													//выход  
		for (int m = 0; m < shift; m++)							//выводим n элементов со шагом влево
   		cout << arr[i][j--] << ' ';  
		shift++;												//опять увеличиваем шаг
 		for (int m = 0; m < shift; m++)							//выводим n элементов со шагом вниз   
		cout << arr[i++][j] << ' ';
		for (int m = 0; m < shift; m++)							//выводим n элементов со шагом вправо   
		cout << arr[i][j++] << ' ';
 	} 
	while (shift!=rows); 										//пока шаг не станет равен размерности массива
}

void deleteArr(int32_t** arr, uint32_t rows, uint32_t cols)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] arr[i];
	}
	delete[]arr;
}

int32_t main()
{
	char way = 2;

	double n = 0;
	chekN(n);

	uint32_t rows = n;
	uint32_t cols = n;

	int32_t **arr = new int32_t* [rows];//создание массива указателей на массивы	

	create_matrix(arr, rows, cols);
	MatrixFillType(way);
	fillMatrix(arr, rows, cols, way);
	outputMatrix(arr, rows, cols);
	chekNegativCols(arr, rows, cols);
	bypass(arr, rows, cols);
	deleteArr(arr, rows, cols);
	
	return 0;
}
