//Program to demonstrate : Pointers (pass  by reference for a variable)
//See : ptrVarPassByRef.png

#include<stdio.h>

void fx(int *q)//formal parameter is a pointer. It gets address from the actual parameter.
{
    *q = 99;//dereference q to access the target
}

int main()
{
    int x;//variable
    x = 10;//access by name
    printf("\n x : %d ", x);//10
    fx(&x);//passing address of a variable as actual parameter (referencing)
    printf("\n x : %d ", x);//99
    return 0;
}
