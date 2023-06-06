#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <iostream>
#include "Node.h"

class LinkedList : public Node 
{
	public:
		Node *head;
		LinkedList();

		LinkedList(int i, int j, int value);

		void addNode(int i, int j, int val);
		int change(int i, int j, int val);
		int find(int i, int j);
		int lenght();

		void print();
};

#endif
