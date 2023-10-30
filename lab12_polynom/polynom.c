#include <stdio.h>
#include <stdlib.h>
#include "polynom.h"

void print(int* p, int len)
{
    int i = len;
    while(i)
    {
        printf("%d ", p[--i]);
    }
}

void copy(int* a, int* b, int size)
{
    b = (int*)realloc(b, size * sizeof(int));
    for (int i = 0; i < size; i++)
        b[i] = a[i];
}

int* pxp(int* a, int len_a, int b[], int len_b)
{
    int* res = (int*)malloc((len_a + len_b - 1) * sizeof(int));
    for (int i = 0; i < (len_a + len_b - 1); i++)
    {
        res[i] = 0;
    }
    
    for (int i = 0; i < len_a; i++)
    {
        for (int j = 0; j < len_b; j++)
        {
            res[i + j] += a[i] * b[j];
        }
    }
    
    return res;
}

void f(int* a, int n)
{
    int len_res = 2;
    int* res = (int*)malloc(len_res * sizeof(int));
    res[0] = -a[0];
    res[1] = 1;
    
    for (int i = 1; i < n; i++)
    {   
        int t[] = {-a[i], 1};
        int* tmp_res = pxp(res, len_res, t, 2);

        copy(tmp_res, res, len_res + 1);
        len_res++;        

        free(tmp_res);
    }   
    printf("Max pow: %d\n", len_res - 1);
    print(res, len_res);
    free(res);
}
