/* Сумма чисел Фиббоначи до введёного числа number*/
#include <iostream>
#include <cctype>


int main() 
{
	int32_t number, nextTerm = 1, firstFibonacciNumber = 0, secondFibonacciNumber = 1, sum = 1;
	std::cout << "Enter natural natural " << std::endl;
	std::cin >> number;
	if (number < 1) 
	{
		std::cout << "The number must be natural" << std::endl;
		return -1;
	}
	std::cout << '\n' << firstFibonacciNumber << " " << secondFibonacciNumber << " 1 ";
	while ((firstFibonacciNumber + secondFibonacciNumber) <= number)					
	{	
		firstFibonacciNumber = secondFibonacciNumber;							
		secondFibonacciNumber = nextTerm;						
		nextTerm = (firstFibonacciNumber + secondFibonacciNumber);			
		if (nextTerm < number)
		{
			std::cout << nextTerm << " ";
			sum += nextTerm;
		}
	}
	std::cout << "\nThe sum of the Fibonacci numbers = " << sum + 1;
	return 0;
}
