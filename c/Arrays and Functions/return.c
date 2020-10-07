//Program to demonstrate : return 
//Refer : functions.txt
//See : return.png

#include<stdio.h>

int cube(int n)//n is the formal parameter that receives data of actual parameter as a copy
{
    int m;
    m = n*n*n;
    return m;//transferring a value back to the caller function
}

int main()
{
    int x, ans;
    printf("\n Enter a number ");
    scanf("%d", &x);
    ans = cube(x);
    printf("\n Cube of %d is %d", x, ans);
    
    return 0;
}
