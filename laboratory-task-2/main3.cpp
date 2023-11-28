/*Нахождение совершенных чисел из диапазона[a; b] */
#include <iostream>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;

int main() {
	int a, b, sum, nextNumber, divinded;
	cout << "Enter range" << endl << "Enter first natural number: ";
	cin >> a;
	cout << "\n Enter second natural number: ";
	cin >> b;
	//Проверка на ненатуральность
	if (a <= 0 || b <= 0 ) 
	{
		cout << "Number not natural";
		return 0;
	}
	//Проверка диапазона а>b
	if (a > b) {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	for (nextNumber = a; nextNumber <= b; nextNumber++)				//Перечисление чисел из промежутка [a;b]
	{
		sum = 0;

		for (divinded = 1; divinded < nextNumber; divinded++)	//Цмкл для проверки делимости числа на divinded
		{
			if (nextNumber % divinded == 0)						//Если число divinded является делителем очередного числа, то
			{
				sum += divinded;								//Подсчёт суммы делителей
			}
		}
		if (sum == nextNumber)	//Если сумма делителей числа равна самому числу,то есть оно является совершенны
		{
			cout << nextNumber << " ";							//Выводим его
		}
	}
	cout << "\nEnd.";
	return 0;
}
