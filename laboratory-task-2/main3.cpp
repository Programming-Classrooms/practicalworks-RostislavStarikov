#include <iostream>
#include <cctype>


using std::cin;
using std::cout;
using std::endl;


int main() 
{
	int a, b, sum, nextNumber, divinded;
	cout << "Enter range" << endl << "Enter first natural number: ";
	cin >> a;
	cout << "\n Enter second natural number: ";
	cin >> b;	
	if (a <= 0 || b <= 0 ) 
	{
		cout << "Number not natural";
		return 0;
	}
	if (a > b) 
	{
		int32_t temp;
		temp = a;
		a = b;
		b = temp;
	}
	for (nextNumber = a; nextNumber <= b; nextNumber++)
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
	cout << "\nEnd.";
	return 0;
}
