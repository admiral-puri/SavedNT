//Program to demonstrate
//Code Managed Memory Management
//Using: malloc/calloc, realloc and free
//Refer: MemoryManagement.txt
//See: DynMemoryManagement.png

#include<stdio.h>
#include<stdlib.h>

int * fx1(int n)//allocate an array of n units
{
    int qty;
    int *p;
    qty = n * sizeof(int);//20 
    
    p = (int*) malloc(qty);
    //being a continuous block of 20 bytes
    //being splitted as integers
    //it can be used like an array
    
    return p;
}

int * fx2(int *q, int n)
{
    int i, qty;
    
    n++;
    qty = n * sizeof(int);
    
    //redimension the block to new qty
    //q may get a new address
    q = realloc(q, qty);
    
    printf("\n Enter %d numbers ", n);
    for(i =0 ; i < n; i++)
        scanf("%d", (q+i));
    
    return q;
}

int main()
{
    int i,n;
    int *ptr;
    
    printf("\n Enter the size of the array ");
    scanf("%d", &n);//say 5
    
    ptr = fx1(n);
    
    if(ptr == NULL)//malloc status
    {//failed
        printf("\n Memory Allocation Error ");
        exit(1);//exit with no sucess status
    }
    
    ptr = fx2(ptr, n);
    n++;//as we know that n is incremented
    
    //display and free
    printf("\n");
    for(i =0; i < n; i++)
        printf(" %d ", *(ptr+i));
    
    //deallocate the block
    free(ptr);
    //here after ptr should not be dereferenced
    
    return 0;
}