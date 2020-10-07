//Program to implement a basic arithmetic calculator
//Study of switch selection statement
//Refer : Conditional Branching.txt

#include<stdio.h>

int main()
{
    float n1,n2;//input
    float ans;//output
    int ch;//operation choice
    
    printf("\n Enter 2 numbers ");
    scanf("%f%f", &n1, &n2);
    
    printf("\n 1. Addition ");
    printf("\n 2. Subtraction ");
    printf("\n 3,4,5. Multiplication");
    printf("\n 6. Division");
    printf("\n Enter choice ");
    scanf("%d", &ch);
    
    
    switch(ch)
    {
        case 1:
            ans = n1 + n2;
            printf("\n %.2f + %.2f = %.2f", n1,n2,ans);
            break;
        default:
            printf("\n Invalid Choice");
            break;
        case 6:
            ans = n1 / n2;
            printf("\n %.2f / %.2f = %.2f", n1,n2,ans);
            break;
        
        case 5:
        case 4:
        case 3:
            ans = n1 * n2;
            printf("\n %.2f * %.2f = %.2f", n1,n2,ans);
            break;
        case 2:
            ans = n1 - n2;
            printf("\n %.2f - %.2f = %.2f", n1,n2,ans);
            break;
    }
    return 0;
}

