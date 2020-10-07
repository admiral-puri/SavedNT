//Program to demonstrate : use to pointers to access a variable
//ptrVarAccess.png
#include<stdio.h>

int main()
{
    int x;//variable
    int *p;//pointer
    
    x = 10;//access by name
    printf("\n x : %d ", x);
    
    p = &x;//referencing
    
    *p = 99;//dereference p to get the access of x 
    
    printf("\n x : %d ", x);
    return 0;
}
