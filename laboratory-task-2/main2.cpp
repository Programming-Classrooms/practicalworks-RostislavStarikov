#include <iostream>
#include <cctype>


using namespace std;


int main() 
{
	int N, nextTerm = 1, f1 = 0, f2 = 1, sum = 1;
	cout << "Enter natural N ";
	cin >> N;
	if ( (N < 1)) 
	{
		cout << "The number must be natural";
		return 0;
	}
	cout << '\n' << f1 << " " << f2 << " 1 ";
	while ( (f1 + f2) <= N)					
	{	
		f1 = f2;							
		f2 = nextTerm;						
		nextTerm = f1 + f2;			
		if (nextTerm < N)
		{
			cout << nextTerm << " ";
			sum += nextTerm;
		}
	}
	cout << "\nThe sum of the Fibonacci numbers= "<<sum+1;
	return 0;
}
