/*
A classic problem that can be solved by backtracking
is called the Eight Queens problem, which comes from
the game of chess.
The chess board consists of 64 square arranged in
an 8 by 8 grid.
The board normally alternates between black and
white square, but this is not relevant for the present problem.

The queen can move as far as she wants in any direction,
as long as she follows a straight line, Vertically, horizontally,
or diagonally.

Write C program with recursive function for generating
all possible configurations for 4-queen's problem.


*/
#include<stdio.h>
#define SIZE 8

void displayBoard(int mat[][SIZE], int n)
{
    int i, j;
    printf("\n");
    for(i =0; i< n; i++)
    {
        for(j =0 ;  j < n; j++)
        {
            printf (" %d ", mat[i][j]);
        }
        printf("\n");
    }
}//displayBoard

int isSafe(int mat[][SIZE], int n, int r, int c)
{
    int i,j;

    //check LHS of this row
    for(i =0 ; i < c; i++)
        if( mat[r][i] == 1)
            return 0;//not safe

    //check upper left diagonal
    for(i = r-1, j = c-1; i>=0 && j >=0; i--, j--)
        if( mat[i][j] == 1)
            return 0;//not safe

    //check lower left diagonal
    for(i =r+1, j = c-1; i < n && j >=0; i++, j--)
        if( mat[i][j] == 1)
            return 0;

    //otherwise
    return 1;//safe
}

int solve(int mat[][SIZE], int n, int c)
{
  int i;
  if(c == n) //base case to stop recursion
    return 1;

  for(i=0; i< n; i++)// consider column and try placing the queen in all rows
  {
    if(isSafe(mat,n, i, c))
    {
      mat[i][c] = 1; //place the queen at mat[i][col]
      if (solve(mat, n, c+1)) //recursion to place rest of the queens
        return 1;

      mat[i][c] = 0; //backtrack
    }//if
  }//for
  //queen cannot be placed in any row corresponding to this col
  return 0;
}

int main()
{
    int n,i,j;
    int mat[SIZE][SIZE];

    do
    {
      printf("\n Enter the number of Queens (max 8) ");
      scanf("%d", &n);
    }while(!(n >=1 && n <= 8 ));

    //Quadratic loop (cycles : n*m)
    for(i =0 ; i< n; i++)
      for(j =0; j< n ; j++)
        mat[i][j] = 0;

    if (solve(mat, n, 0))
        displayBoard(mat,n);
    else
        printf("\n SOLUTION DOESNT EXIST");

    return 0;
}
