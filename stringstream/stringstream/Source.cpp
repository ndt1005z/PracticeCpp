#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	string s = "<tag1 value = HelloWorld";
	stringstream ss(s);

	string t1, p1, v1;
	char ch;
	ss >> ch >> t1 >> p1 >> ch >> v1;
	cout << t1 << "|" << p1 << "|" << ch << "|" << v1;
	while (ss)
	{
		ss >> p1 >> ch >> v1;
	}
	cout << "after while: " << endl;
	cout << p1 <<"|" << ch << "|" << v1;

	return 0;
}