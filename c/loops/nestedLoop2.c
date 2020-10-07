#include<stdio.h>

//* 
//* *  
//* * * 
//* * * *
//* * * * *

int main()
{
    int i, j;
    
    for(i =1; i <=5 ; i++)
    {//5 times
        printf("\n");
        for(j =0 ; j < i; j++)
        {//5 * i times
            printf(" *");
        }
    }
    return 0;
}
