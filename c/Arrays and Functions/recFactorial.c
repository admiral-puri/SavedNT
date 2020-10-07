#include<stdio.h>
//Program to calculate factorial of a number recursively.
//Say the number is 5
//So, 5! = 5*4*3*2*1
//And, 4! = 4*3*2*1
//Hence, 5! = 5 * 4!
//Generic, n! = n * (n-1)!

int factorial(int n)
{
  if(n == 0)
    return 1;//recursion unwinds
  else if(n > 0)
    return n * factorial(n-1);
}

int main()
{
  int n, ans;
  n= 4;//scan
  ans = factorial(n);
  return 0;
}
