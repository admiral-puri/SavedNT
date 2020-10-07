//Program to add n numbers
//See : addXNumbers.png 

#include<stdio.h>

int main()
{
    int i;//loop counter
    int x;//times
    int n;//input
    int ans;//result
    
    printf("\n How many numbers to add : ");
    scanf("%d", &x);//say  5
    
    //     1               2,5,8          4,7
    //for(initialization ; condition; reinitialization)
    //{ (on true) 3,6
    //  body
    //} 
    //...(on false) 9
    
    ans = 0;
    for(i= 1; i <= x; i++ )
    {
        printf("\n Enter number %d : ", i);
        scanf("%d", &n);//(7),(9),(4),(12),(3)
        ans = ans + n;//(0+7),(7+9), (16+4), (20+12), (32+3)
    }
    printf("\n Addition : %d ", ans);
    return 0;
}

