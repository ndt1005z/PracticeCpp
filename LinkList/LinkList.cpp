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

Node* createNode(int input)
{
	Data data = { input };
	Node* node = createNode(data);
	return node;
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

void addHead(List& list, Node* pNode)
{
	if (isEmpty(list))
	{
		list.pHead = list.PTail = pNode;
	}
	else
	{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}

void addHead(List& list, int n)
{
	Node* pNode = createNode(n);
	addHead(list, pNode);
}

void addTail(List& list, Node* pNode)
{
	if (isEmpty(list))
	{
		list.pHead = list.PTail = pNode;
	}
	else
	{
		list.PTail->pNext = pNode;
		list.PTail = pNode;
	}
}

void addTail(List& list, int n)
{
	Node* pNode = createNode(n);
	addTail(list, pNode);
}

void printList(List list)
{
	if (isEmpty(list))
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		Node* pNode = list.pHead;
		while (pNode != NULL)
		{
			cout << pNode->data.n << "\t" ;
			pNode = pNode->pNext;
		}
	}
}

int getSize(List list)
{
	int count = 0;
	if (isEmpty(list))
	{
		return 0;
	}
	else
	{
		Node* pNode = list.pHead;
		while (pNode != NULL)
		{
			count++;
			pNode = pNode->pNext;
		}
	}

	return count;
}

void insertNode(List& list, Node* q, Node* pNode)
{
	if (isEmpty(list))
	{
		list.pHead = list.PTail = pNode;
	}
	else
	{
		// check if q is tail node
		if (list.PTail == q)
		{
			addTail(list, pNode);
		}
		else
		{
			pNode->pNext = q->pNext;
			q->pNext = pNode;
		}
	}
}

void insertNode(List& list, int index, Node* pNode)
{

	Node* nodeAtIndex = getNodeAt(list, index);
	if (nodeAtIndex !=NULL)
	{
		insertNode(list, nodeAtIndex, pNode);
	}
}

Node* getNodeAt(List list, int index)
{
	int count = 0;
	if (isEmpty(list) && (index < 0))
	{
		return NULL;
	}
	if (index >= getSize(list))
	{
		cout << "This index do not exist!" << endl;
		return NULL;
	}
	else
	{
		Node* pNode = list.pHead;
		while (pNode != NULL)
		{
			if (count == index)
			{
				return pNode;
			}
			count++;
			pNode = pNode->pNext;
		}
	}
}