#include<stdio.h>
//Program to implement : Selection Sort

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

int main()
{
    int arr[6];//array
    scanArray(arr, 6);
    displayArray(arr, 6);
    selectionSort(arr, 6);
    displayArray(arr, 6);
                
    return 0;
}
