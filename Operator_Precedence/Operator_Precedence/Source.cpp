#include <iostream>

using namespace std;

int main()
{
#if 0
	int a = 1, b = 2, c;
	c = a + b-- * 2;

	cout << c << endl;
#endif

#if 0
	// i++ 
	cout << "i++" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "loop 1: " << i << endl;
	}

	// ++i
	cout << "++i" << endl;
	for (int j = 0; j < 5; ++j)
	{
		cout << "loop 2: " << j << endl;
	}
#endif

	int* p_scalar = new int(5);  // Does not create 5 elements, but initializes to 5
	int* p_array = new int[5];  // Creates 5 elements
	cout << "size of new int(5): " << sizeof(&p_scalar) << endl;
	cout << "size of new int[5]: " << sizeof(&p_array) << endl;
	return 0;
}