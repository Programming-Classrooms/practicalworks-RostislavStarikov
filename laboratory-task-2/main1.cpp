git #include <iostream>
#include <cctype>


using namespace std;


int main() 
{
    int N, divided;
    cout << "Enter number N: ";
    cin >> N;
    if (N < 1)
    {
        cout << "Number " << N << " is not natural";
        return 0;
    }         
    divided = 1;
    bool isPrime;
    for (int nextNumber = 2; nextNumber < N; nextNumber++)
    { 
        isPrime = true;
        for (divided = 2; divided < nextNumber; divided++) 
        {
            if (nextNumber % divided == 0)               
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime) 
	{
            cout << nextNumber << " ";
        }
    }
    cout << endl << "End.";
    return 0;
}
