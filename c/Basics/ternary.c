//Program to study conditional branching using ternary operator
//refer : conditional branching.txt
//see : ternary.png

#include<stdio.h>

int main()//program begins here
{
    int x, y, z;
    
    printf("\n Enter 2 numbers ");
    scanf("%d%d", &x,&y);
    
    z = x>y ? x*x : x*y;
    
    printf("\n x: %d ", x);//say 20
    printf("\n y : %d ", y);//say 15
    printf("\n z : %d ", z);//then 400

    return 0;//status representing successful completion
}

