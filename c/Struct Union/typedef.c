#include<stdio.h>

/*
Study of "typedef" statement

typedef statement is used to assign an alternate 
name to an existing datatype.

Usage:
typedef <existingType> <alternateName>;

Example:
typedef int integer;

After typedef, the datatype can be used with either 
of the names.
*/

typedef int integer;

int main()
{
  int i;
  integer j;
  i = 10;
  j = i*i;

  printf("\n Square of %d is %d", i,j);
  return 0;
}

