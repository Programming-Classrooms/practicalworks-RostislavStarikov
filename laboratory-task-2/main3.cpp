/*Нахождение совершенных чисел из заданного пользователем диапазона*/
#include <iostream>
#include <cctype>


int main() 
{
	int32_t leftBorder, rightBorder, sum, nextNumber, divinded;
	cout << "Enter range" << endl << "Enter first natural number: ";
	cin >> leftBorder;
	cout << "\n Enter second natural number: ";
	cin >> rightBorder;	
	if (leftBorder <= 0 || rightBorder <= 0 || rightBorder==leftBorder) 
	{
		cout << "Incorrect value" << std::endl;
		return -1;
	}
	if (leftBorder > rightBorder) 
	{
		int32_t temp;
		temp = leftBorder;
		leftBorder = rightBorder;
		rightBorder = temp;
	}
	for (nextNumber = leftBorder; nextNumber <= rightBorder; nextNumber++)
	{
		sum = 0;
		for (divinded = 1; divinded < nextNumber; divinded++)
		{
			if (nextNumber % divinded == 0)
			{
				sum += divinded;
			}
		}
		if (sum == nextNumber)
		{
			cout << nextNumber << " ";						
		}
	}
	cout << "\nEnd.\n";
	return 0;
}
