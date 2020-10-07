//Generate : Fibonacci Series upto 100
//See : fibonacci.png

#include<stdio.h>

int main()
{
    int a,b;//2 numbers
    int c;//addition

    a = -1;
    b = 1;
    while((a+b) < 100)
    {
        c = a+b;//0,1,1,2,3,5,...,89
        printf(" %d ", c);//addition
        a = b;//1,0,1,1,2,...,55
        b = c;//0,1,1,2,3,...,89
    }//while
    return 0;
}

