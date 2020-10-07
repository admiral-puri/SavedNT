//Program to swap 2 numbers using a third variable
//see : SWAP 2.png

#include<stdio.h>//to get the definition of printf and many other functions

int main()//program begins here
{
    int a, b, c;//3 int variables
    
    a = 10;//assignment
    b = 20;//assignment
    
    c = a;//backup a into c (c becomes 10)
    a = b;//assign b to a (a becomes 20)
    b = c;//assign c to b (b becomes 10)
    
    printf("\n a : %d ", a);//20
    printf("\n b : %d ", b);//10
    
    return 0;//status representing successful completion
}

