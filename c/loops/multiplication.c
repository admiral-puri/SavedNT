//Program to generate the multiplication table of a number
//See : multiplication.png

#include<stdio.h>

int main()
{
 int x;//loop control
 int n;//input
 int ans;//output
 
 printf("\n Enter the number to generate the multiplication table ");
 scanf("%d", &n);

 x = 1;//initialization
 while(x <= 10) //condition 
 {
  ans = n * x;
  printf("\n %d * %d = %d ", n, x, ans);
  x++;
 }

 return 0;
}