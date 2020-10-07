//global variables
#include<stdio.h>

int x, y; //global variables

void fx()
{
    y = x*x*x;
}

int main()
{
    printf("\n Enter a number ");
    scanf("%d", &x);
    fx();
    printf("\n Cube of %d is %d ", x, y);
    return 0;
}