//Program to demonstrate 
//creation and inclusion of custom header file
//use of macro to support conditional compilation
//refer : preprocessor.txt, arith.h
//see : Build.png

#include<stdio.h>
#include<stdio.h>//attempt to include again

#include<arith.h>
#include<arith.h>//attempt to include again


int main()
{
  double ans;

  ans = add(7, 9.1);
  printf("\n 7 + 9.1 = %f", ans);

  ans = subtract(7, 9.1);
  printf("\n 7 - 9.1 = %f", ans);


  ans = multiply(7, 9.1);
  printf("\n 7 * 9.1 = %f", ans);


  ans = divide(7, 9.1);
  printf("\n 7 / 9.1 = %f", ans);

  return 0;
}
