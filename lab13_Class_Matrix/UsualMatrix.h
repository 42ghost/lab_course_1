#ifndef _USUAL_MATRIX_
#define _USUAL_MATRIX_

#include "IMatrix.h"


class UsualMatrix : public IMatrix
{
	private:
		int row;
		int col;
		int **data;
	public:
		UsualMatrix();
		UsualMatrix(const UsualMatrix &m);
		UsualMatrix(int row, int col);				//Матрица заполненная rand
		UsualMatrix(int row, int col, int value);	//Матрица заполненная value

		void setElem(int x, int y, int value);
		int getElem(int x, int y);
		int getSizeRow();
		int getSizeCol();
		int getSize();
		void print();

		UsualMatrix& operator=(const UsualMatrix &m);
		~UsualMatrix();
};
#endif
