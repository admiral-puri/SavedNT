//Program to demonstrate : Pointers To Functions

#include<stdio.h>

void f1()
{
    printf("\n This is f1()");
}

void f2(int a)
{
    printf("\n Square of %d is %d ",a , a*a);
}

int f3(int a, int b)
{
    return a + b;
}

int main()
{
    int q;

    void (*p1)();//pointer to any function that is void and takes no parameters.
    void (*p2)(int);//pointer to any function that is void and takes 1 int parameter.
    int (*p3)(int,int);//pointer to any function that takes 2 int parameters and returns an int.

    //referencing
    p1 = f1;
    p2 = f2;
    p3 = f3;

    //dereferencing
    p1();
    p2(5);
    q = p3(5,6);
    printf("\n %d ", q);

    return 0;
}
