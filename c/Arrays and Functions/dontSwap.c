//Program to demonstrate : Pass By Value resulting in no swap
#include<stdio.h>

void swap(int a, int b)//a,b are formal parameters to receive values of actual parameters x, y respectively.
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}//swap

int main()
{
    int x, y;
    x = 10;
    y = 20;
    printf("\n %d %d", x, y);//10, 20
    swap(x, y);
    printf("\n %d %d", x, y);//10, 20
    
    return 0;
}
