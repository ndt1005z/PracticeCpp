#include "LinkList.h"

int main()
{
	List list;
	Data data = { 69 };
	

	Node* node = createNode(data);
	cout << node->data.n << endl;
	
	//Init list
	initList(list);

	//check if list is empty
	if (isEmpty(list))
	{
		cout << "The list is empty." << endl;
	}
	else 
	{
		cout << "The list is not empty" << endl;
	}

	system("pause");
	return 0;
}