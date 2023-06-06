#include <ctime>
#include <cstdlib>
#include <iostream>

#include "UsualMatrix.h"

#define MOD 20

UsualMatrix::UsualMatrix()
{
	row = 0;
	col = 0;
	data = nullptr;
}

UsualMatrix::UsualMatrix(const UsualMatrix &m)
{
	if (this != &m)
	{
		this->row = m.row;
		this->col = m.col;
		this->data = new int*[this->row];
		for (int i = 0; i < this->row; i++)
		{
			this->data[i] = new int[this->col];
			for (int j = 0; j < this->col; j++)
			{
				this->data[i][j] = m.data[i][j];
			}
		}
	}
}

UsualMatrix::UsualMatrix(int r, int c)
{
	row = r;
	col = c;

	data = new int*[row];

	//srand(time(NULL));
	for (int i = 0; i < row; i++)
	{
		data[i] = new int[col];
		for(int j = 0; j < col; j++)
		{
			data[i][j] = rand() % MOD;
		}
	}
}

UsualMatrix::UsualMatrix(int r, int c, int val)
{
	row = r;
	col = c;

	data = new int*[row];
	for (int i = 0; i < row; i++)
	{
		data[i] = new int[col];
		for(int j = 0; j < col; j++)
		{
			data[i][j] = val;
		}
	}
}

void UsualMatrix::setElem(int x, int y, int value)
{
	if (x < 0 && this->row < x || y < 0 && this->col < y)
	{
		std::cout << "Wrong sizes\n";
		return;
	}
	data[x][y] = value;
}

int UsualMatrix::getElem(int x, int y)
{
	return data[x][y];
}

int UsualMatrix::getSizeRow()
{
    return row;
}

int UsualMatrix::getSizeCol()
{
	return col;
}

int UsualMatrix::getSize()
{
	return row * col;
}

void UsualMatrix::print()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << data[i][j] << "\t";
		}
		std::cout << '\n';
	}
}

UsualMatrix& UsualMatrix::operator=(const UsualMatrix &m)
{
	if (this != &m)
	{
		this->row = m.row;
		this->col = m.col;

		this->data = new int*[row];
		for (int i = 0; i < this->row; i++)
		{
			this->data[i] = new int[col];
			for (int j = 0; j < this->col; j++)
			{
				this->data[i][j] = m.data[i][j];
			}
		}
	}
	return *this;
}

UsualMatrix::~UsualMatrix()
{
	for (int i = 0; i < row; i++)
		delete [] data[i];
	delete [] data;
}
