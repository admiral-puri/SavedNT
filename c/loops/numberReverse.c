//program to reverse a number
//see : numberReverse.png
#include<stdio.h>

int main()
{
    int number;
    int reverse;
    int x;
    
    do
    {
        printf("\n Enter a positive number ");
        scanf("%d", &number);//862 (initialization)
    }while(number < 0);
    
    printf("\n Number : %d ", number);
    reverse = 0;//initialization
    
    while(number > 0)
    {
    //A) fetch the last digit of number
        x = number % 10;
    //B) merge the digit to the reverse
        reverse = reverse * 10 + x;
    //C) remove the last digit of number 
        number = number / 10; //(reinitialization)
    }//while
    
    number = reverse; //we had to reverse the number
    printf("\n Reverse : %d ", number);
    return 0;
}

