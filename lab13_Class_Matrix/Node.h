#ifndef _NODE_
#define _NODE_

struct Element
{
	int x;
	int y;
	int value;
};

class Node
{
	public:
		Node *next;
		Element elem;

		Node(int i, int j, int value);
		Node();
};
#endif
