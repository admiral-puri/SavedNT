//Program to check whether a number
//is a prime number or not

//see : numberPrime.png
//see : flag.png

#include<stdio.h>

int main()
{
    int n;//number
    int i;//a possible factor
    int x;//flag (signal indicator)
    
    printf("\n enter a number ");
    scanf("%d", &n);//15, 25, 13
    
    x = 1;//any initial value for flag

    //check for factors in range 2-n/2
    for(i = 2; i <= n/2; i++)
    {
        if(n %i == 0)
        {//on true : i is a factor of n
            x =0;//change the value of flag (signal)
            break;//stop the loop, as a factor is found
        }
    }//for
 
    //as per the value (signal)   
    if(x == 1)
        printf("\n %d is a prime number ", n); 
    else if(x == 0)
        printf("\n %d is not a prime number ", n); 
        
    return 0;
}

