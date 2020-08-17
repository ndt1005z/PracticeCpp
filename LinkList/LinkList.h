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
Node* createNode(int data);

// Initilize list
void initList(List& lst);

// check if list is null
bool isEmpty(List list);

// add a element to head of list
void addHead(List& list, Node* pNode);
void addHead(List& list, int n);

void addTail(List& list, Node* pNode);
void addTail(List& list, int n);

// print list
void printList(List list);

// get size of list
int getSize(List list);

//insert a node after node q
void insertNode(List& list, Node* q, Node* pNode);

//Insert a node after index of node
void insertNode(List& list, int index, Node* pNode);

//Get node at index
Node* getNodeAt(List list, int index);