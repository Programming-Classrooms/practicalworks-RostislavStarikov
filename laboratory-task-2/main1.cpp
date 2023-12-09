/*Найти и вывесети все простые числа от 2 до натурального number*/
#include <iostream>
#include <cmath>


int main() 
{
    uint32_t number, divided;
    std::cout << "Enter your number: " << std::endl;
    std::cin >> number;
    if (number < 1)
    {
        std::cout << "Number " << number << " is not natural"<< std::endl;
        return -1;
    }         
    divided = 1;
    bool isPrime;
    for (int nextNumber = 2; nextNumber < number; nextNumber++)
    { 
        isPrime = true;
        for (divided = 2; divided < int32_t(sqrt(nextNumber)) + 1; divided++) 
        {
            if (nextNumber % divided == 0)               
            {
                isPrime = false;
                break;
            }
        }
    if (isPrime) 
    {
        std::cout << nextNumber << " ";
    }
    }
    std::cout << std::endl << "End.";
    return 0;
}
