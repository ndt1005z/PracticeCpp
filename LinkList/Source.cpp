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

	addHead(list, node);

	node = createNode(100);
	addHead(list, node);

	node = createNode(20);
	addHead(list, node);

	node = createNode(1);
	addTail(list, node);

	node = createNode(99);
	addTail(list, node);

	addTail(list, 22);

	//Insert a node after node q
	Node* node1 = createNode(2);
	insertNode(list, node, node1);

	//insert a node after index of node
	//random position
	insertNode(list, 2, createNode(3));
	cout << "print list: " << endl;
	printList(list);
	//boundary position
	insertNode(list, 0, createNode(111));
	cout << "print list: " << endl;
	printList(list);
	insertNode(list, getSize(list) - 1, createNode(999));
	cout << "print list: " << endl;
	printList(list);

	cout << "Print link list: " << endl;
	printList(list);

	cout << "Get size of list: " << getSize(list) << endl;

	Node* temp;
	temp = getNodeAt(list, 2);
	cout << "data at index is 2: " << temp->data.n << endl;


	system("pause");
	return 0;
}