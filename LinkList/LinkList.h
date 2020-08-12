#pragma once
#include <iostream>
using namespace std;

struct Data
{
	int n;
};

struct Node
{
	Data data;
	Node *pNext;
};

struct List
{
	Node *pHead;
	Node *PTail;
};

// create node
Node* createNode(Data data);

// Initilize list
void initList(List& lst);

// check if list is null
bool isEmpty(List list);