//Program to test: Pass By Reference for variables
//See : swap.png

#include<stdio.h>

void swap(int *p, int *q)
{//interchange
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int main()
{
    int x, y;
    x = 10;
    y = 20;
    printf("\n %d %d ", x, y);//10 20
    swap(&x,&y);//passing memory locations of x and y as actual parameters
    printf("\n %d %d ", x, y);//20 10
    
    return 0;
}