//Program to find factors of a number
//See factors.png

#include<stdio.h>

int main()
{
 int x;//loop control
 int n;//input
 
 printf("\n Enter the number to find factors of : ");
 scanf("%d", &n);//say 40
 printf("\n Factors of %d are : \n", n);
 
 x = 1;//initialization (smallest factor)
 while(x <= n) //condition (largest factor)
 {
     if(n % x == 0)
     {
         printf(" %d ", x);
     }
     x++;//reinitialization
 }//while

 return 0;
}