//Program to demonstrate : 
//Passing parameter to a function by value.
//Refer : Functions.txt
//See : passByValue.png

#include<stdio.h>

void fx(int a)//int a is formal parameter. It is initialized as a copy of actual parameter (x).
{
    printf("\n in fx(), a : %d ",a);
    a = 99;//change the formal parameter
    printf("\n in fx(), a : %d ",a);
}

int main()
{
    int x;
    x = 10;
    printf("\n in main(), x : %d",x);
    fx(x);//call to fx with x as actual parameter
    printf("\n in main(), x : %d",x);
    