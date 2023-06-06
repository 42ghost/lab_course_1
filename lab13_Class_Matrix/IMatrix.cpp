#include "IMatrix.h"
#include "SparseMatrix.h"
#include "UsualMatrix.h"
#include <iostream>

#define MOD 20
#define K 100

UsualMatrix IMatrix::add(IMatrix& m)
{
    if (this->getSizeRow() != m.getSizeRow() || this->getSizeCol() != m.getSizeCol())
    {
        std::cout << "Sizes are not equal";
        return UsualMatrix();
    }
    else
    {
        UsualMatrix tmp(this->getSizeRow(), this->getSizeCol(), 0);
        for (int i = 0; i < this->getSizeRow(); i++)
        {
            for (int j = 0; j < this->getSizeCol(); j++)
            {
                int sum = this->getElem(i, j) + m.getElem(i, j);
                tmp.setElem(i, j, sum);
            }
        }
        return tmp;
    }
}

UsualMatrix IMatrix::mul(IMatrix& m)
{
    if (this->getSizeCol() != m.getSizeRow())
    {
        std::cout << "Wrong sizes";
        return UsualMatrix();
    }
    else
    {
        UsualMatrix tmp(this->getSizeRow(), m.getSizeCol(), 0);
        for (int i = 0; i < this->getSizeRow(); i++)
        {
            for (int j = 0; j < this->getSizeCol(); j++)
            {
                int sum = 0;
                for (int k = 0; k < this->getSizeCol(); k++)
                {
                    sum += this->getElem(i, k) * m.getElem(k, j);
                }
                tmp.setElem(i, j, sum);
            }
        }
        return tmp;
    }
}

UsualMatrix IMatrix::rotate(int i)
{
    if (this->getSizeRow() != this->getSizeCol())  
    {
        std::cout << "The matrix must be square\n";
        return UsualMatrix();
    } 

    UsualMatrix rotated(this->getSizeRow(), this->getSizeCol(), 0);
    
    int size = rotated.getSizeRow();
    for (int j = 0; j < size; j++)
    {
        for (int k = 0; k < size; k++)
        {
            rotated.setElem(j, k, this->getElem(k, size - j - 1));
        }
    }

    if (i == 1)
        return rotated;
    else
    {
        rotated = rotated.rotate(i - 1);
        return rotated;
    }
}


int IMatrix::countZeros(IMatrix& m)
{
    int count = 0;
    for(int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            count += ( m.getElem(i, j) == 0 );
        }
    }
    return count;
}

void IMatrix::gen()
{
    //srand(time(NULL));
    std::cout << "Zeros before: " << countZeros(*this) << '\n';

    int i = 0, j = 0; 
    while (countZeros(*this) < K)
    {
        int t = rand() % (MOD / 4);
        if(t == 0)
            this->setElem(i, j, 0);
        j++;
        i = i + (j / K) % K;
        j %= K;
    }
    while (countZeros(*this) > K)
    {
        int t = rand() % (MOD - 1) + 1;
        if(t % 2 == 0 && this->getElem(i, j) == 0)
            this->setElem(i, j, t);
        j++;
        i = (i + (j / K)) % K;
        j %= K;
    }

    std::cout << "After: " << countZeros(*this) << '\n';
}





















