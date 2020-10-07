//C program to study operator -
/*
 C allows operator - to be used in 2 ways.
 1) Unary usage
 2) Binary usage
 
 When used in unary form - performs negation.
 When used in binary form - performs subtraction.
 
 Refer the code.
 */
#include<stdio.h>

int main()
{
    int x, y;
    int ans;
    
    printf("\n Enter 2 numbers ");
    scanf("%d%d", &x,&y);
    
    y = -y;//negation
    ans = x - y;//subtraction
    
    printf("\n %d - %d = %d ", x, y, ans);
    
    return 0;
}

