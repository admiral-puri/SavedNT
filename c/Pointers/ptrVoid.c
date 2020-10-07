//Program to demonstrate : void pointers
//Refer : ptrVoid.png

#include<stdio.h>

int main()
{
    int a;
    char b;
    double c;
    void *p; // a generic pointer
    
    a = 10;
    b = 'q';
    c = 3.4567;
    
    p = &a;//referencing an int
    printf("\n a : %d ", *(int*)p);//typecasted into an int for dereferencing
    
    p = &b;//referencing a char
    printf("\n b : %c ", *(char*)p);//typecasted into a char for dereferencing
    
    p = &c;//referencing a double
    printf("\n c : %f ", *(double*)p);//typecasted into a double for dereferencing
    
    return 0;
}