#include <iostream>
#include <functional>

using namespace std;


// hoán đổi giá trị hai số
void swapNumber(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

#if 0 // normal way
// hàm sắp xếp tăng sử dụng thuật toán selection sort
void selectionSortAsc(int* arr, int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray  
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array  
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[min_idx] > arr[j])
			{
				min_idx = j;
			}
		}

		// Swap the found minimum element with the first element  
		swapNumber(arr[min_idx], arr[i]);
	}
}

// hàm sắp xếp giảm sử dụng thuật toán selection sort
void selectionSortDesc(int* arr, int n)
{
	int i, j, max_idx;

	// One by one move boundary of unsorted subarray  
	for (i = 0; i < n - 1; i++)
	{
		// Find the maximum element in unsorted array  
		max_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[max_idx] < arr[j])
			{
				max_idx = j;
			}
		}

		// Swap the found maximum element with the first element  
		swapNumber(arr[max_idx], arr[i]);
	}
}
#endif

/*desc and asc*/
bool asc(int a, int b)
{
	return a > b;
}

bool desc(int a, int b)
{
	return a < b;
}

/* selection sort using function pointer*/
void selectionSort(int* arr, int n, bool(*sort)(int, int))
{
	int i, j, max_idx;

	// One by one move boundary of unsorted subarray  
	for (i = 0; i < n - 1; i++)
	{
		// Find the maximum element in unsorted array  
		max_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (sort(arr[max_idx], arr[j]))
			{
				max_idx = j;
			}
		}

		// Swap the found maximum element with the first element  
		swapNumber(arr[max_idx], arr[i]);
		cout << "element " << i << " :" << arr[i] << endl;
	}
}


/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//prototype
int funcA(int a, int b)
{
	return 0;
}
int main()
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(int);

	// asc sort
	cout << "ascending sort" << endl;
	selectionSort(arr, n, asc);
	printArray(arr, n);

	//desc sort
	cout << "descenting sort" << endl;
	selectionSort(arr, n, desc);
	printArray(arr, n);

	function<int(int, int)> fncPtrA = funcA;
	function<void(int&, int&)> fncPtrB = swapNumber;
	int a = 5, b = 15;
	/*fncPtrB(a, b);
	cout << a << b;*/

	auto ptrSwap = swapNumber;
	ptrSwap(a, b);
	cout << a << b << endl;
	return 0;
}