#include<stdio.h>
//Program to find the greatest of n numbers using recursion
//Say n is 4 then greater of 4 numbers is : 4th number compared with greater of 3 numbers
//When n is 3 then greater of 3 numbers is : 3rd number compared with greater of 2 numbers
//When n is 2 then greater of 2 numbers is : 2nd number compared with greater of 1 number
//When n is 1 then greater of 1 number is : number itself
//In generalized form :
//Greatest(n) = nth number compared with Greatest(n-1)

int greatest(int n)
{
  int x, y;
  printf("\n Enter a number : ");
  scanf("%d", &x);
  if(n == 1)
    return x;//itself is greater
  else
  {
    y = greatest(n-1);
    if(x > y)
      return x;
    else
      return y;
  }
}

int main()
{
  int ans, n;
  printf("\n How many numbers to compare : ");
  scanf("%d", &n);//say n is 4
  ans = greatest(n);
  printf("\n greatest of %d numbers is %d", n,ans);
  return 0;
}
