#include<stdio.h>

//Program to calculate x raisedTo y recursively
//say x is 5 and y is 3
//we need to solve 5 raisedTo 3
//5 raisedTo 3
//5 * 5 raisedTo 2
//5 * 5 * 5 raisedTo 1
//5 * 5 * 5 * 5 raisedTo 0
//5 * 5 * 5 * 1
//125

//therefore
//x * x raisedTo( y-1)


int power(int x, int y)
{
  if(y == 0)//base condition
   return 1;//recursion unwinds
  else
   return x * power(x,y-1);
}

int main()
{
  int ans;
  ans = power(5,3);
  printf("\n 5 raisedTo 3 is %d ", ans);
  return 0;
}
