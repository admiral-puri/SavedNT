//program to find GCD of 2 numbers
//see : GCD.png
#include<stdio.h>

int main()
{
    int n1, n2;
    int x;
    printf("\n Enter 2 numbers ");
    scanf("%d%d", &n1, &n2);
    
    //find the smaller of n1 and n2
    x = n1<n2 ? n1 : n2;
    
    while(x > 0)//from smaller number to 1
    {
        if(n1%x==0 &&  n2%x==0)
        {
            printf("\n GCD : %d", x);
            break;//stop the loop (checking)
        }
        x--;
    }//while
    
    
    return 0;
}

