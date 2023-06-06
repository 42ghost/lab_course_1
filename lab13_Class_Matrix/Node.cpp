#include "Node.h"

Node::Node(int i, int j, int val)
{
	elem.x = i;
	elem.y = j;
	elem.value = val;
	next = nullptr;
}

Node::Node()
{
	next = nullptr;
}

