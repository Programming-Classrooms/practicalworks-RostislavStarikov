#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>


const long double EXP = M_E;


using std::cin;
using std::cout;


// Проверка значения eps
void chekEps(double& eps)
{
	try
	{
		cin >> eps;

		if (eps < 0 || eps > 1)
		{
			throw eps;
		}
	}
	catch (double eps)
	{

		cout << "Uncorrect size!!!\nEnter the desired eps accuracy from the range ( 0 , 1): ";
		chekEps(eps);
	}
}
//Выбор формулы интеграла
double wayFunc(double& a, double& b, double x, char& way)
{
	long double func;
	if (way == NULL)
	{
		cout << "Select the integral number: \t\t1.e^(0.1*x) / x\n\t\t\t\t2.(sqrt(0.5+x*x)) /(1+cos(0.5*x))\n\t\t\t\t\t3.(pow(EXP, -x) * ((sin(0.1 * x)) / (x + 1)))\n";
		cin >> way;
	}
	switch (way)
	{
	case '1':
		func = (pow(EXP, (0.1 * x)) / x);
		a = 0.5; b = 1.5;
		return func;
		break;
	case '2':
		func = ((sqrt(0.5 + x * x)) / (1 + cos(0.5 * x)));
		a = 0; b = 1;
		return func;
		break;
	case '3':
		func = ((pow(EXP, -x) * ((sin(0.1 * x)) / (x + 1))));
		a = 0; b = 2.1;
		return func;
		break;
	default:
		cout << "Uncorrect value!!!";
		way = NULL;
		wayFunc(a, b, x, way);
		break;
	}
}
//Вычисление интеграла способом средних прямоугольников
void integrateMiddleRectangle(double& a, double& b, double eps, int32_t& n, char& way)
{
	double h = (b - a) / n; // шаг разбиения
	double S1 = 0, S2 = h * wayFunc(a, b, a + 0.5 * h, way); // первые два значения интеграла

	do
	{
		n *= 2; // удваиваем количество разбиений
		h = (b - a) / n; // пересчитываем шаг разбиения
		S1 = S2;
		S2 = 0;
		for (int32_t i = 0; i < n; i++)
		{
			S2 += h * wayFunc(a, b, a + (i + 0.5) * h, way); // суммируем значения функции на серединах интервалов
		}
	} while (abs(S1 - S2) > eps); // повторяем, пока не достигнута заданная точность
	cout.precision(8);//Количество выводимых знаков поле точки
	cout << " The value of the integral:" << S2 << " n= " << n << '\n';
}

//Вычисление интеграла по формуле Симпсона
void integrateSimpson(double a, double b, int32_t& n, double eps, char way) 
{
	double h = (b - a) / n; // Шаг
	double S1 = 0, S2 = h / 6 * (wayFunc(a, b, a, way) + 4 * wayFunc(a, b, a + h, way) + wayFunc(a, b, b, way)); // Интеграл на разбитых частях
	do 
	{
		n *= 2; //Удваиваем шаг разбиения
		h = (b - a) / n;//Шаг разбиения
		S1 = S2;
		S2 = 0;
		for (int32_t i = 0; i <= n; i++) 
		{
			S2 += (h / 6) * (wayFunc(a, b, a + (i - 1) * h, way) + 4 * wayFunc(a, b, a + i * h, way) + wayFunc(a, b, a + (i + 1) * h, way));//Вычисление интеграла по формуле Симпсона
		}
	}
	while (abs(S1 - S2) > eps);
	cout.precision(8);
	cout << "The value of the integral: " << S2 << " n = " << n << '\n';
} 

void wayIntegrate(double& a, double& b, double eps, int32_t& n, char& way, char& way_int)
{
	cout << "Choose the method of finding the integral: \t\t1.By the formula of the average rectangles \n\t\t\t\t\t2.According to Simpson's formula\n";
	cin >> way_int;
	switch (way_int)
	{
	case '1':
		integrateMiddleRectangle(a, b, eps, n, way);
		break;
	case '2':
		integrateSimpson(a, b, n, eps, way);
		break;
	default:
		cout << "Uncorrect value!!!\n";
		wayIntegrate(a, b, eps, n, way, way_int);
		break;
	}	
}



int main()
{
	double a = NULL, b = NULL, eps = NULL;
	int32_t n = 4;
	char way = NULL, way_int = 0;
	cout << "Enter the desired eps accuracy from the range ( 0 , 1):";
	chekEps(eps);
	wayIntegrate(a, b, eps, n, way, way_int);
	return 0;
}
