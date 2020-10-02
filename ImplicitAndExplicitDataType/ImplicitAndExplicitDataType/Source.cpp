#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Explicit data type
	//C-type cast
	int n1 = 2;
	int n2 = 5;
	double result = (double)n2 / n1;
	cout << result << endl;

	//static cast
	double result2 = static_cast<double> (n2) / n1;
	cout << result2;
	return 0;
}