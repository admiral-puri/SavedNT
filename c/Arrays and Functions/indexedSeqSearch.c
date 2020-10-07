//Indexed Sequential Search

#include<stdio.h>

void scanArray(int a[], int s)
{//scan
    int i;
    printf("\n Enter %d numbers ", s);
    for(i =0 ; i < s; i++)
        scanf("%d", &a[i]);
}

void displayArray(int a[], int s)
{//print
    int i;
    printf("\n ");
    for(i =0 ; i < s; i++)
        printf(" %d ", a[i]);
}

int indexedSeqSearch(int a[], int s, int val)
{
    int i;
    for(i=0; i<s; i++)
    {
        if(a[i] == val)
            return i;//stop and send back the index
        else if(a[i] > val)
            return -1;//stop and send back -1
    }//for
    return -1;//Not found status
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
    int arr[8];//array declaration
    int x;//search
    int flag;//search result status
    
    scanArray(arr, 8);
    insertionSort(arr, 8);
    displayArray(arr, 8);
    
    printf("\n Enter the value to search ");
    scanf("%d", &x);
    
    flag = indexedSeqSearch(arr, 8, x);
    
    if(flag == -1)
        printf("\n %d not found ", x);
    else
        printf("\n %d found at index %d ", x, flag);
    return 0;
}

