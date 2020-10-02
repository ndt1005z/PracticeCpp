#include <iostream>
using namespace std;

template <typename Type> 
void mySwap(Type& var1, Type& var2) {
	Type temp;
	temp = var1;
	var1 = var2;
	var2 = temp;
}

template <typename Type1, typename Type2>
void mySwap2(Type1& var1, Type2& var2) {
	double tmp;
	tmp = var1;
	var1 = var2;
	var2 = tmp;
}

int main()
{
	int a = 10, b = 20;
	double c = 1.2, d = 3.4;
	mySwap(a, b);
	cout << a << " " << b << endl;
	mySwap(c, d);
	cout << c << " " << d << endl;

	mySwap2(c, a);
	cout << a << " " << c;
	return 0;
}