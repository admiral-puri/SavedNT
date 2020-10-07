//Program to check whether a number is even or odd.
//study of if statement
//refer : conditional branching.txt
//see : if-else.png

#include<stdio.h>

int main()//program begins here
{
    int x;
    
    printf("\n Enter a number ");
    scanf("%d", &x);
    
    if(x % 2 == 0)
    {//on true
        printf("\n %d is an even number ", x);
    }
    else//optional
    {//on false
        printf("\n %d is an odd number ", x);
    }    
    
    return 0;//status representing successful completion
}

