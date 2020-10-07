//Program to study :
//pointer to a pointer
//refer : Pointers.txt

#include<stdio.h>

int main()
{
    int i; //a variable
    int *p; //a pointer
    int **q; //a pointer to a pointer
    
    i =10; //assignment
    p = &i; //referencing a variable
    q = &p; //referencing a pointer
    
    printf("\n i : %d ", i);//access by name
    printf("\n i : %d ", *p);//access by dereferencing
    printf("\n i : %d ", **q);//access by double dereferencing
    
    
    return 0;
}
