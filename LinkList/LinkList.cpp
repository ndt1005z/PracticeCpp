#include "LinkList.h"

Node* createNode(Data data)
{
	Node* node = new Node;
	if (node == NULL)
	{
		return NULL;
	}

	node->data = data;
	node->pNext = NULL; //pNext point to NULL (last element)
}

void initList(List& lst)
{
	lst.pHead = lst.PTail = NULL;
}

bool isEmpty(List list)
{
	if (list.pHead == NULL)
	{
		return true;
	}
	return false;
}