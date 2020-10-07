//Program to demonstrate matrix
//Study of matrix transpose

#include<stdio.h>

void display(int m[][3], int r, int c)//formal parameter is a matrix reference with known number of columns
{
  int i , j;
  printf("\n");
  for(i =0 ; i < r; i++)
  {
    printf("\n");
    for(j =0 ; j < c; j++)
    {
      printf("%4d", m[i][j]);
    }
  }
}

void transpose(int m[][3], int r, int c)
{
  int i,j;
  int temp;
  for(i =0; i < r; i++)
  {
    for(j =i+1 ; j < c; j++)
    {//swapping upper triangular part with the lower
      temp = m[i][j];
      m[i][j] = m[j][i];
      m[j][i] = temp;

    }//for(j
  }//for(i
}

int main()
{
  //declare and initialize a matrix of 3x3
  int mat[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

  display(mat,3,3);//passing matrix as a parameter to a function
  transpose(mat,3,3);
  display(mat,3,3);


  return 0;
}
