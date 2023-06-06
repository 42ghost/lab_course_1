#ifndef _IMATRIX_
#define _IMATRIX_

#include <ctime>
#include <cstdlib>

class UsualMatrix;

class IMatrix
{
    protected:
        virtual void setElem(int x, int y, int value) = 0;
        virtual int getElem(int x, int y) = 0;
        virtual int getSizeRow() = 0;
        virtual int getSizeCol() = 0;
        virtual int getSize() = 0;
        virtual void print() = 0;
    public:
        UsualMatrix add(IMatrix& m);
        UsualMatrix mul(IMatrix& m);
        UsualMatrix rotate(int angle);

        int countZeros(IMatrix& m);
        void gen();
};

#endif 
