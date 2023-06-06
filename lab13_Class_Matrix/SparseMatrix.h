#ifndef _SPARSE_MATRIX_
#define _SPARSE_MATRIX_

#include "IMatrix.h"
#include "LinkedList.h"

class SparseMatrix : public IMatrix, public LinkedList
{
	private:
		int row;
		int col;
		int count;
		LinkedList *data;
	public:
		SparseMatrix();
		SparseMatrix(const SparseMatrix &m);
		SparseMatrix(int row, int col); //Матрица заполненная rand до row и до col
		SparseMatrix(int row, int col, int value); //Матрица заполненная value  до row и до col

		void setElem(int x, int y, int value);
		int getElem(int x, int y);
		int getSizeRow();
		int getSizeCol();   
		int getSize();
		void print();

		SparseMatrix& operator=(const SparseMatrix &m);
		~SparseMatrix();
};

#endif
