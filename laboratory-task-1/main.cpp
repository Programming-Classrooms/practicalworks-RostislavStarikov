#include <iostream>
#include <cmath>


using std::log;
using std::cout;
using std::cin;
using std::endl;


int main() {
	double x, begDiff, result, epsilon;
	int k, n;
	
	cout << "Enter x: -1 < x < 1 " << endl;
	cin >> x;
	if (x > 1 || x < -1) {
		cout << "\nx can be - 1<x<1";
		return 0;
	}
	
	cout << "Enter k" << endl;
	cin >> k;
	if (k <= 0)
	{
		cout << "\nk must be natural number!!";
		return 0;
	}
	
	epsilon = pow(10, -k);
	result = 0.0;
	n = 1;
	begDiff = 2*x;
	
	while (abs(begDiff) >= epsilon)			
	{
		result += begDiff;		
		begDiff *= (x*x) * (2*n-1) / (2*n+1);
		n++;
	}
	
	cout << "ln((x+1)/(x-1))= " << (log((1 + x) / (1 - x))) << endl;
	cout << "S= " << result;
	return 0;
}

