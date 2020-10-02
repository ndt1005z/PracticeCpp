#include <iostream>
using namespace std;

int main()
{
	int value = 10;
	
	int* ptr = &value;
	cout << *ptr << endl;

	int** ptr2 = &ptr;
	cout << *ptr2 << endl;
	cout << **ptr2 << endl;
	
	
	return 0;
}