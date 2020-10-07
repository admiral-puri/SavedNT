//Program to find greater of 3 numbers
//study of else if statement
//refer : conditional branching.txt
//see : else if.png

#include<stdio.h>

int main()
{
    int n1,n2,n3;
    
    printf("\n Enter 3 numbers ");
    scanf("%d%d%d", &n1,&n2,&n3);
    
    if(n1 == n2 && n1 == n3)
        printf("\n All numbers are %d ", n1);
    else if(n1 > n2 && n1 > n3)
        printf("\n %d is greatest ", n1);
    else if(n2 > n3)
        printf("\n %d is greatest ", n2);
    else
        printf("\n %d is greatest ", n3);
    
    return 0;
}

