#include<stdio.h>
//Program to implement : Binary Search

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

void selectionSort(int a[], int s)
{
    int i, j; //loop control
    int min; //selection
    int temp;//swap
    
    for(i =0; i < s-1; i++)
    {
        min = i;//assumed minimum
        //comparison range
        for(j = i+1; j < s; j++)
        {
            if(a[j] < a[min])
                min = j;//selection
        }//for(j
        
        if(i != min)
        {//swap
            temp= a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }//for(i
}//selectionSort

int binarySearch(int a[], int s, int val)
{
    int x; //lower boundary
    int y; //upper boundary
    int mid;//point of comparison
    
    //spanning the entire array
    x = 0;
    y = s -1;
    
    while(x <= y)
    {
        mid = (x+y)/2;
        if(val == a[mid])//found
            return mid;//index 
        else if(val < a[mid])//may occur on the LHS
            y = mid -1;
        else if(val > a[mid])//may occur on the RHS
            x = mid +1;
        
    }//while
    return -1;//not found
}

int main()
{
    int arr[8];//array
    int val;//to search
    int pos;//position
    
    scanArray(arr, 8);
    selectionSort(arr, 8);
    displayArray(arr, 8);
                
    printf("\n Enter the value to search : ");
    scanf("%d", &val);
    
    pos = binarySearch(arr, 8, val);
    if(pos == -1)
        printf("\n %d not found ", val);
    else
        printf("\n %d is found at index %d ", val, pos);
    
    
    return 0;
}
