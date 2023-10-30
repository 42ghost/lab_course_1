#include <stdio.h>
#include <stdlib.h>
#include "polynom.h"

int main()
{
    int n;
    int* a;
    
    if(!scanf("%d", &n))
    {
        printf("Error\n");
        return 1;
    }
    else if(n <= 0)
    {
        printf("Error\n");
        return 2;
    }
    
    a = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++)
    {
        if (!scanf("%d", &a[i]))
        {
            printf("Error\n");
            return 3;
        }
    }

    f(a, n);

    free(a);

    return 0;
}
