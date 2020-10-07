/*
Represent matrix using two dimensional arrays and perform following operations: 
i. Addition  
ii. multiplication  
iii. transpose  
iv. Saddle point
*/

#include<stdio.h>
#define SIZE 10

void setMat(int mat[][SIZE], int r, int c)
{
    int i, j;
    printf("\n Enter data for : ");
    for(i =0; i< r; i++)
    {
        for(j =0 ; j< c; j++)
        {
            printf("\n mat[%d][%d] ", i, j);
            scanf("%d", &mat[i][j]);
        }//for(j
    }//for(i
}//setMat


void displayMat(int mat[][SIZE], int r, int c)
{
    int i, j;
    printf("\n");
    for(i =0; i< r; i++)
    {
        printf("\n");
        for(j =0 ; j< c; j++)
        {
            printf(" %d  ", mat[i][j]);
        }//for(j
    }//for(i
}//displayMat

//Using a pointer to a matrix
void addition(int (*mat1)[SIZE], int r1, int c1, int (*mat2)[SIZE], int r2, int c2)
{
    if(r1 == r2 && c1 == c2)
    {
        int mat3[SIZE][SIZE];
        int i,j;
        
        for(i =0 ; i< r1; i++)
            for(j =0; j< c1; j++)
                mat3[i][j] = *(*(mat1+i) +j) + *(*(mat2+ i)+j);
        
        displayMat(mat1, r1,c1);
        displayMat(mat2, r2,c2);
        displayMat(mat3, r1,c1);
    }
    else
        printf("\n Addition Not Possible");
}//addition

/*
void addition(int mat1[][SIZE], int r1, int c1, int mat2[][SIZE], int r2, int c2)
{
    if(r1 == r2 && c1 == c2)
    {
        int mat3[SIZE][SIZE];
        int i,j;
        
        for(i =0 ; i< r1; i++)
            for(j =0; j< c1; j++)
                mat3[i][j] = mat1[i][j] + mat2[i][j];
        
        displayMat(mat1, r1,c1);
        displayMat(mat2, r2,c2);
        displayMat(mat3, r1,c1);
    }
    else
        printf("\n Addition Not Possible");
}//addition
*/
void multiplication(int mat1[SIZE][SIZE], int r1, int c1, int mat2[SIZE][SIZE], int r2, int c2)
{
    if(c1 == r2)
    {
        int mat3[SIZE][SIZE];
        int r3, c3;
        int i,j,k;
        int sum;
        
        r3 = r1;
        c3 = c2;
        
        for(i =0; i < r1; i++)
        {
            for(j =0 ; j < c2; j++)
            {
                sum =0 ;
                for(k = 0; k < c1; k++)
                {
                    sum = sum + mat1[i][k] * mat2[k][j];
                }
                mat3[i][j] = sum;
            }
        }
        
        displayMat(mat1, r1, c1);
        displayMat(mat2, r2, c2);
        displayMat(mat3, r3, c3);
    }
    else
        printf("\n Multiplication Not Possible");
}

void transpose(int mat[SIZE][SIZE], int r, int c)
{
    int i, j;
    int temp;
    
    for(i =0 ; i < r; i++)
    {
        for(j = i+1; j< c; j++)
        {
            temp  = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
    
}//transpose

void saddlePoint(int mat[SIZE][SIZE], int r, int c)
{
    int maxCols[SIZE], minRows[SIZE];
    int i, j;
    int temp;
    int minC, maxR;
    
    //get max of cols
    for(i =0 ; i< c; i++)
    {
        temp = mat[0][i];
        for(j =1; j < r; j++)
        {
            if(mat[j][i] > temp )
                temp = mat[j][i];
        }
        maxCols[i] = temp;
    }
    
    
    //get min of rows
    for(i =0 ; i< r; i++)
    {
        temp = mat[i][0];
        for(j =1; j < c; j++)
        {
            if(mat[i][j] < temp )
                temp = mat[i][j];
        }
        minRows[i] = temp;
    }
    
    //getMin of maxCols
    minC = maxCols[0];
    for(i =1 ; i< c; i++)
    {
        if(maxCols[i] < minC)
            minC = maxCols[i];
    }
    
    //getMax of minRows
    maxR = minRows[0];
    for(i =1 ; i< r; i++)
    {
        if(minRows[i] > maxR)
            maxR = minRows[i];
    }
    
    //When minC and maxR are equal then 
    //saddle point exits
    
    if(maxR == minC)
        printf("\n Saddle Point Exists @ %d ", minC);
    else
        printf("\n Saddle Point Doesnt Exists");
        
}//saddlePoint

int main()
{
    int mat1[SIZE][SIZE], mat2[SIZE][SIZE];
    int r1,c1, r2, c2;
    int ch, temp;
    do
    {
        printf("\n 1. Set Matrix1 ");
        printf("\n 2. Set Matrix2 ");
        printf("\n 3. Addition ");
        printf("\n 4. Multiplication ");
        printf("\n 5. Transpose Matrix 1");
        printf("\n 6. Saddle Point Check for Matrix 1 ");
        printf("\n 7. Exit ");
        printf("\n Enter Choice ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1://set matrix
                printf("\n Enter the number of rows in matrix 1 ");
                scanf("%d", &r1);
                printf("\n Enter the number of cols in matrix 1 ");
                scanf("%d", &c1);
                
                setMat(mat1,r1,c1);
                displayMat(mat1, r1,c1);
                break;
            case 2://set matrix 2
                printf("\n Enter the number of rows in matrix 2 ");
                scanf("%d", &r2);
                printf("\n Enter the number of cols in matrix 2 ");
                scanf("%d", &c2);
                
                setMat(mat2,r2,c2);
                displayMat(mat2, r2,c2);
   
                break;
            case 3://addition
                addition(mat1, r1, c1, mat2, r2, c2);
                break;
            case 4://multiplication
                multiplication(mat1, r1, c1, mat2, r2, c2);
                break;
            case 5://transpose
                displayMat(mat1,r1,c1);
                
                transpose(mat1, r1,c1);
                temp = r1;
                r1 = c1;
                c1 = temp;
                displayMat(mat1,r1,c1);
                
                break;
            case 6://saddle point
                displayMat(mat1,r1,c1);
                saddlePoint(mat1, r1,c1);
                
                break;
            case 7://exit
                break;
            default:
                printf("\n Wrong Choice ");
                break;
        }//switch
    }while(ch != 7);
    return 0;
}//main
