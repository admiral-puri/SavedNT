#include<stdio.h>
//Program to implement : Insertion Sort

void scanArray(int a[], int s)
{
    int i;
    printf("\n Enter %d numbers : ", s);
    for(i =0; i < s; i++)
        scanf("%d", &a[i]);
}

void displayArray(int a[], int s)
{
    int i;
    printf("\n");
    for(i =0; i < s; i++)
        printf(" %d ", a[i]);
}

void insertionSort(int a[], int s)
{
    int i, j;//loop control
    int current;
    
    for(i = 1; i < s; i++)
    {
        current = a[i];//pick an element
        //compare with the elements on LHS
        for(j=i-1; j>=0; j--)
        {
            if(current < a[j])
                a[j+1] = a[j];//slide
            else
                break;
        }//for(j
        a[j+1] = current; //insertion
    }//for(i
}//insertionSort

int main()
{
    int arr[6];
    scanArray(arr, 6);
    displayArray(arr, 6);
    insertionSort(arr, 6);
    displayArray(arr, 6);
    
    
    return 0;
}
