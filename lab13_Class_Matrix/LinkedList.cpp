#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = new Node();
}

LinkedList::LinkedList(int i, int j, int val)
{
	head = new Node(i, j, val);
}

void LinkedList::addNode(int i, int j, int val)
{
	LinkedList *cur = (LinkedList*)head;
	while (cur->next != nullptr)
	{
		cur = (LinkedList*)cur->next;

		if (cur->elem.x == i && cur-> elem.y == j)
		{
			cur->elem.value = val;
			return;
		}
	}
	Node *tmp = cur->next;
	Node *tmp2 = cur;
	tmp = new Node(i, j, val);
	tmp2->next = tmp;
}

int LinkedList::change(int i, int j, int val)
{
	Node* cur = head;
	while (cur != nullptr)
	{
		if (cur->elem.x == i && cur->elem.y == j)
		{
			cur->elem.value = val;
			return 1;
		}
		cur = cur->next;
	}
	std::cout << "! Element with given index not found (hasn't changed) !" << '\n';
	return 0;
}

int LinkedList::find(int i, int j)
{ 
	Node* cur = head;

	while (cur != nullptr)
	{
		//std::cout << cur->elem.x << ' ' << cur->elem.y << '\n';
		if (cur->elem.x == i && cur->elem.y == j)
			return cur->elem.value;
		cur = cur->next;
	}
	return 0;
}

int LinkedList::lenght() //проверить, заменив cur->next на cur
{
	if (head == nullptr)
		return 0;

	Node* cur = head;    
	int len = 0;
	while (cur->next != nullptr)
	{
		cur = cur->next;
		len++;
	}
	return len;
}

void LinkedList::print()
{
	Node* cur = head;
	while (cur != nullptr)
	{
		printf("(%d, %d): %d\n", cur->elem.x, cur->elem.y, cur->elem.value);
		cur = cur->next;
	}
}
