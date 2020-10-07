//Accept conventional matrix 
//and convert it into sparse matrix 
//using structure and perform 
//addition, simple and fast transpose. 

#include<stdio.h>
#define SIZE 10

struct Sparse
{
    int r, c, data;
};
typedef struct Sparse Sparse;

void scanMat(int mat[SIZE][SIZE], int r, int c)
{
    int i, j;
    for(i =0 ; i< r; i++)
    {
        for(j =0; j< c; j++)
        {
            printf("\n Enter value for mat[%d][%d] ", i, j);
            scanf("%d", &mat[i][j]);
        }//for(j...
    }//for(i...
}//scanMat

void printMat(int mat[SIZE][SIZE], int r, int c)
{
    int i, j;
    for(i =0 ; i< r; i++)
    {
        printf("\n");//row change
        for(j =0; j< c; j++)
            printf("%3d", mat[i][j]);
    }
}//printMat

void matrixToSparse(int mat[SIZE][SIZE], int r, int c, Sparse s[])
{
    int i, j; //indices for mat
    int k;//index for Sparse array
    
    k = 1; //because S[0] would be the header
    
    for(i =0 ; i< r; i++)
    {
        for(j =0 ; j< c; j++)
        {
            if(mat[i][j] != 0)
            {
                s[k].r = i;
                s[k].c = j;
                s[k].data = mat[i][j];
                
                k++;//move to next position
            }
        }//for(j ...
    }//for(i ...
    
    //set the sparse header 
    s[0].r = r;
    s[0].c = c;
    s[0].data = k-1; //-1 as k has moved to next position
}


void printSparse(Sparse s[])
{
    int i;
    for(i = 0; i <= s[0].data ; i++)
    {
        if(i == 0)
            printf("\n--------SPARSE--------");
        
        printf("\n %4d %4d %4d ", s[i].r, s[i].c, s[i].data);
        
        if(i == 0)
            printf("\n----------------------");
    }
}


void simpleTranspose(Sparse s1[], Sparse s2[])
{
    int i,j;
    Sparse temp; //for bubble sort swap
    
    //interchange the row and col
    for(i =0; i<= s1[0].data; i++)
    {//0 sets the header row
        
        s2[i].c = s1[i].r;
        s2[i].r = s1[i].c;
        s2[i].data = s1[i].data;    
    }
    
    //bubble sort
    for(i = s2[0].data; i > 1; i--)
    {
        for(j =1 ; j< i; j++)//1 : don't sort the header row
        {
            if(s2[j].r > s2[j+1].r) //row-wise
            {
                temp = s2[j];
                s2[j] = s2[j+1];
                s2[j+1] = temp;
            }//if
        }//for(j...
    }//for(i...
    
}//simpleTranspose

void fastTranspose(Sparse s1[], Sparse s2[])
{
    int i,x;
    
    int c[SIZE] = { 0 }; //all elements set to 0
    int p[SIZE] = { 0 }; //all elements set to 0
    
    //set the count
    for(i = 1; i<= s1[0].data; i++)
        c[s1[i].c]++;
    
    //set the position
    p[0] = 1; //col 0 would begin at position 1, as position 0 is reserved for the header
    for(i = 1; i<= s1[0].c; i++)
        p[i] = p[i-1] + c[i-1];
    
    //clean the rows of target sparse
    for(i=0;i<SIZE; i++)
        s2[i].r = -1;
    
    for(i =1; i<=s1[0].data; i++)
    {
        x = p[s1[i].c];
        if(s2[x].r == -1)
        {//empty location
            s2[x].r = s1[i].c;
            s2[x].c = s1[i].r;
            s2[x].data = s1[i].data;
        }
        else
        {//linear probing
            while(s2[x].r != -1)
                x++;
            
            s2[x].r = s1[i].c;
            s2[x].c = s1[i].r;
            s2[x].data = s1[i].data;
        }
    }
    
    //set the header row
    s2[0].r = s1[0].c;
    s2[0].c = s1[0].r;
    s2[0].data = s1[0].data;

}//fastTranspose


int addSparse(Sparse s1[], Sparse s2[], Sparse s3[])
{
    int i, j, k; //s1,s2 and s3 indices
    
    //order check
    if( !(s1[0].r == s2[0].r && s1[0].c == s2[0].c ))
        return 0;
    
    //addition
    i = 1 ;
    j = 1;
    k = 1;
    
    while(i <= s1[0].data && j <= s2[0].data)
    {
        if(s1[i].r < s2[j].r)
        {
            //s1[i] copies into s3[k]
            s3[k] = s1[i];
            i++;
            k++;
        }
        else if(s2[j].r < s1[i].r)
        {
            //s2[j] copies into s3[k]
            s3[k] = s2[j];
            j++;
            k++;
        }
        else if(s1[i].r == s2[j].r)
        {//column comparison
            if(s1[i].c < s2[j].c)
            {
                //s1[i] copies into s3[k]
                s3[k] = s1[i];
                i++;
                k++;
            }
            else if(s2[j].c < s1[i].c)
            {
                //s2[j] copies into s3[k]
                s3[k] = s2[j];
                j++;
                k++;
            }
            else if(s1[i].c == s2[j].c)
            {//add and copy
                s3[k].r = s1[i].r;
                s3[k].c = s1[i].c;
                s3[k].data = s1[i].data + s2[j].data;
                
                i++;
                j++;
                k++;
            }
        }
    }//while
    
    //remaining to be copied
    while(i <= s1[0].data)
    {
        s3[k] = s1[i];
        i++;
        k++;
    }
    
    //remaining to be copied
    while(j <= s2[0].data)
    {
        s3[k] = s2[j];
        j++;
        k++;
    }
    
    //set the header for s3
    s3[0].r = s1[0].r;
    s3[0].c = s1[0].c;
    s3[0].data = k-1;

    return 1; //success
}//addSparse
int main()
{
    int mat[SIZE][SIZE];
    int r, c;
    int x, ch;
    Sparse s1[SIZE];
    Sparse s2[SIZE];
    Sparse s3[SIZE];
    
    
    do
    {
        printf("\n 1. Simple Transpose ");
        printf("\n 2. Fast Transpose ");
        printf("\n 3. Addition ");
        printf("\n 4. Exit ");
        printf("Enter Choice ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1://simple transpose
                printf("\n Enter the number of rows for the matrix ");
                scanf("%d", &r);
                printf("\n Enter the number of columns for the matrix ");
                scanf("%d", &c);
                scanMat(mat, r, c);
                printMat(mat, r, c);
                matrixToSparse(mat, r, c, s1);
                printSparse(s1);
                simpleTranspose(s1,s2);
                printSparse(s2);
    
                break;
            case 2://fast transpose
                printf("\n Enter the number of rows for the matrix ");
                scanf("%d", &r);
                printf("\n Enter the number of columns for the matrix ");
                scanf("%d", &c);
                scanMat(mat, r, c);
                printMat(mat, r, c);
                matrixToSparse(mat, r, c, s1);
                printSparse(s1);
                fastTranspose(s1,s2);
                printSparse(s2);

                break;
            case 3://addition
                printf("\n Enter the number of rows for the matrix1 ");
                scanf("%d", &r);
                printf("\n Enter the number of columns for the matrix1 ");
                scanf("%d", &c);
                scanMat(mat, r, c);
                printMat(mat, r, c);
                matrixToSparse(mat, r, c, s1);
                
                printf("\n Enter the number of rows for the matrix2 ");
                scanf("%d", &r);
                printf("\n Enter the number of columns for the matrix2 ");
                scanf("%d", &c);
                scanMat(mat, r, c);
                printMat(mat, r, c);
                matrixToSparse(mat, r, c, s2);
                
                printSparse(s1);
                printSparse(s2);

                x = addSparse(s1,s2,s3);
                if(x == 0)
                    printf("\n Order Mismatch, Addition Fails");
                else
                    printSparse(s3);
                break;
            case 4:
                break;
            default:
                printf("\n Wrong Choice ");
                break;
        }//switch
    }while(ch != 4);
    
    
    return 0;
}

