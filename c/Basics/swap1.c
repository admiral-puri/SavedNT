//Program to swap 2 numbers without using a third variable
//See : SWAP 1.png

#include<stdio.h>//to get the definition of printf and many other functions

int main()//program begins here
{
    int a, b;//2 int variables
    
    a = 10;//assignment
    b = 20;//assignment
    
    a = a + b;//a becomes 30
    b = a - b;//b becomes 10
    a = a - b;//a becomes 20
    
    printf("\n a : %d ", a);//20
    printf("\n b : %d ", b);//10
    
    return 0;//status representing successful completion
}

