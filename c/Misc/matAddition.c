//Program to demonstrate matrix
//Study of matrix addition

#include<stdio.h>

void scan(int m[][4], int r, int c, char nm[])
{
  int i, j;

  printf("Enter data for matrix : %s \n", nm);
  for(i =0; i < r; i++)
  {
    for(j =0; j <c; j++)
    {
      printf("%s[%d][%d] : ", nm,i,j);
      scanf("%d", &m[i][j]);
    }
  }
}

void display(int (*p)[4], int r, int c, char nm[])//formal parameter is a matrix reference with known number of columns
{
  int i , j;
  printf("\n\nmatrix : %s ", nm);
  for(i =0 ; i < r; i++)
  {
    printf("\n");
    for(j =0 ; j < c; j++)
    {
      printf("%4d", *(*(p+i)+j) );
    }
  }
}

void addition(int m1[][4],int m2[][4], int m3[][4], int r, int c)
{
  int i, j;
  for(i =0 ; i < r; i++)
    for(j =0 ; j< c; j++)
      m3[i][j] = m1[i][j] + m2[i][j];

}

int main()
{
  int mat1[2][4], mat2[2][4], mat3[2][4];

  scan(mat1,2,4, "m1");
  scan(mat2,2,4, "m2");

  addition(mat1,mat2,mat3, 2,4);

  display(mat1,2,4, "m1");//passing matrix as a parameter to a function
  display(mat2,2,4, "m2");
  display(mat3,2,4, "m3");

  return 0;
}
