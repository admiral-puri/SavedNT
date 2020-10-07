//Program to demonstrate function
//Refer : Functions.txt
//See : Functions.png

#include<stdio.h>

void fx() //signature
{//body
    printf("1");
    printf("2");
    printf("3");
}

int main()//signature
{//body
    printf("A");
    printf("B");
    printf("C");
    fx();//function call
    printf("D");
    printf("E");
    printf("F");
    return 0;
}