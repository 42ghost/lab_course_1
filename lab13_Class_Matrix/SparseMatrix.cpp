#include <ctime>
#include <cstdlib>
#include <iostream>

#include "SparseMatrix.h"

#define MOD 20

SparseMatrix::SparseMatrix()
{
	row = 0;
	col = 0;
	count = 0;
	data = new LinkedList();
}

SparseMatrix::SparseMatrix(const SparseMatrix &m)
{
	if (this != &m)
	{
		row = m.row;
		col = m.col;

		data = new LinkedList(m.data->elem.x, m.data->elem.y, m.data->find(m.data->elem.x, m.data->elem.y));

		Node* cur = m.data->head->next;
		count = 1;
		while (count != m.count)
		{
			data->addNode(cur->elem.x, cur->elem.y, cur->elem.value);
			cur = cur->next;
			count++;
		}
	}
}

SparseMatrix::SparseMatrix(int r, int c)
{
	row = r;
	col = c;
	count = r * c;

	//srand(time(NULL));    
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0 && j == 0)
				data = new LinkedList(i, j, rand() % MOD);
			else
				data->addNode(i, j, rand() % MOD);
		}
	}
}

SparseMatrix::SparseMatrix(int r, int c, int val)
{
	row = r;
	col = c;
	count = r * c;


	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0 && j == 0)
				data = new LinkedList(0, 0, val);
			else
				data->addNode(i, j, val);
		}
	}
}

void SparseMatrix::setElem(int i, int j, int val)
{
	if (data->elem.value == 0)
	{
		delete data;
		data = new LinkedList(i, j, val);
	}
	else if(val != 0)
	{
		if (i > row)
			row = i;
		if (j > col)
			col = j;
		data->addNode(row, col, val);
		count++;
	}
}

int SparseMatrix::getElem(int i, int j)
{
	return data->find(i, j);
}

int SparseMatrix::getSizeRow()
{
	return row;
}

int SparseMatrix::getSizeCol()
{
	return col;
}

int SparseMatrix::getSize(){
	return count;
}

void SparseMatrix::print()
{
	data->print();
}

SparseMatrix& SparseMatrix::operator=(const SparseMatrix &m)
{
	if (this != &m)
	{
		row = m.row;
		col = m.col;

		data = new LinkedList(m.data->elem.x, m.data->elem.y, m.data->find(m.data->elem.x, m.data->elem.y));

		Node* cur = m.data->head->next;
		count = 1;
		while (count != m.count)
		{
			data->addNode(cur->elem.x, cur->elem.y, cur->elem.value);
			cur = cur->next;
			count++;
		}
	}
	return *this;
}

SparseMatrix::~SparseMatrix()
{
	delete data;
}
