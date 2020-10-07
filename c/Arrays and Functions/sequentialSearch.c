#include<stdio.h>
//Program to implement : Sequential Search

void scanArray(int a[], int s)
{
    int i;
    printf("\n Enter %d values ", s);
    for(i =0 ; i < s; i++)
        scanf("%d", &a[i]);   
}

void displayArray(int a[], int s)
{
    int i;
    printf("\n");
    for(i =0 ; i < s; i++)
        printf(" %d ", a[i]);
}

int sequentialSearch(int a[], int s, int val)
{
    int i;
    for(i =0 ; i < s; i++)
    {
        if(val == a[i])
            return i;//found, return the position
    }
    return -1;//array has exhausted and there was no match
}

int main()
{
    int arr[8];//array
    int val;//to search
    int pos;//position
    
    scanArray(arr, 8);
    displayArray(arr, 8);
                
    printf("\n Enter the value to search : ");
    scanf("%d", &val);
    
    pos = sequentialSearch(arr, 8, val);
    if(pos == -1)
        printf("\n %d not found ", val);
    else
        printf("\n %d is found at index %d ", val, pos);
    
    
    return 0;
}
