/*Вычислить значение определения интеграла с анализом заданной подинтегральной
коррекции с заданной границей eps
В) по формуле средних величин;
Д) по формуле Симпсона (параболических трапеций).*/
#include <iostream>
#include <math.h>


// Проверка значения eps
void chekEps(double& eps)
{
	std::cin >> eps;
	if (eps < 0 || eps > 1)
	{
		throw "Uncorrect size!!!\n";
	}
}
//Выбор формулы интеграла
double wayFunc(double& lowerLimit, double& upperLimit, double x, char& way, double &S2)
{
	long double func;
	switch (way)
	{
	case '1':
		func = (exp(0.1 * x) / x);
		lowerLimit = 0.5; upperLimit = 1.5;
		return func;
		break;
	case '2':
		func = ((sqrt(0.5 + x * x)) / (1 + cos(0.5 * x)));
		lowerLimit = 0; upperLimit = 1;
		return func;
		break;
	case '3':
		func = (exp(-x) * ((sin(0.1 * x)) / (x + 1)));
		lowerLimit = 0; upperLimit = 2.1;
		return func;
		break;
	default:
		throw "Wrong function selection!!!";
	}
}
//Вычисление интеграла способом средних прямоугольников
void integrateMiddleRectangle(double& lowerLimit, double& upperLimit, double eps, int32_t& steps, char& way, double &S2)
{
	double h = (upperLimit - lowerLimit) / steps; // шаг разбиения
	double S1 = 0;
	S2 = h * wayFunc(lowerLimit, upperLimit, lowerLimit + 0.5 * h, way, S2); // первые два значения интеграла

	do
	{
		steps *= 2; // удваиваем количество разбиений
		h = (upperLimit - lowerLimit) / steps; // пересчитываем шаг разбиения
		S1 = S2;
		S2 = 0;
		for (int32_t i = 0; i < steps; i++)
		{
			S2 += h * wayFunc(lowerLimit, upperLimit, lowerLimit + (i + 0.5) * h, way, S2); // суммируем значения функции на серединах интервалов
		}
	} while (abs(S1 - S2) > eps); // повторяем, пока не достигнута заданная точность
}

//Вычисление интеграла по формуле Симпсона
void integrateSimpson(double lowerLimit, double upperLimit, int32_t& steps, double eps, char way, double &S2) 
{
	double h = (upperLimit - lowerLimit) / steps; // Шаг
	double S1 = 0;
	S2 = h / 6 * (wayFunc(lowerLimit, upperLimit, lowerLimit, way, S2) + 4 * wayFunc(lowerLimit, upperLimit, lowerLimit + h, way, S2) + wayFunc(lowerLimit, upperLimit, upperLimit, way, S2)); // Интеграл на разбитых частях
	do 
	{
		steps *= 2; //Удваиваем шаг разбиения
		h = (upperLimit - lowerLimit) / steps;//Шаг разбиения
		S1 = S2;
		S2 = 0;
		for (int32_t i = 0; i <= steps; i++) 
		{
			S2 += (h / 6) * (wayFunc(lowerLimit, upperLimit, lowerLimit + (i - 1) * h, way, S2) + 4 * wayFunc(lowerLimit, upperLimit, lowerLimit + i * h, way, S2) + wayFunc(lowerLimit, upperLimit, lowerLimit + (i + 1) * h, way, S2));//Вычисление интеграла по формуле Симпсона
		}
	}
	while (abs(S1 - S2) > eps);
} 

int main()
{
	try
		{
		double lowerLimit, upperLimit, eps, S2;
		int32_t steps = 4;
		char way, way_int;
		std::cout << "Enter the desired eps accuracy from the range ( 0 , 1):";
		chekEps(eps);
		std::cout << "Select the integral number:\t1.e^(0.1*x) / x\n\t\t\t\t2.(sqrt(0.5+x*x)) /(1+cos(0.5*x))\n\t\t\t\t3.(pow(EXP, -x) * ((sin(0.1 * x)) / (x + 1)))\n";
		std::cin >> way;
		wayFunc(lowerLimit, upperLimit, lowerLimit, way, S2);
		std::cout << "Choose the method of finding the integral:\t1.By the formula of the average rectangles \n\t\t\t\t\t\t2.According to Simpson's formula\n";
		std::cin >> way_int;
		switch (way_int)
		{
		case '1':
			integrateMiddleRectangle(lowerLimit, upperLimit, eps, steps, way, S2);
			break;
		case '2':
			integrateSimpson(lowerLimit, upperLimit, steps, eps, way, S2);
			break;
		default:
			throw "Wrong choice of integration method\n";
		}	
		std::cout.precision(8);
		std::cout << "The value of the integral: " << S2 << " Number of steps = " << steps << '\n';
		return 0;
		}
	catch (const char* msg)
		{
			std::cerr << msg << '\n';
			return -1;
		}
}
