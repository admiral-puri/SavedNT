//Program to replace the maximum value of the array with zero
//see : replaceArrayMax.png

#include<stdio.h>

int main()
{
    int arr[6];//declare an array of 6 elements
    int i;
    int max;
    
    printf("\n Enter 6 numbers : ");
    for(i =0; i < 6; i++)
        scanf("%d", &arr[i]);

    printf("\n ");
    for(i =0 ; i < 6; i++)
        printf(" %d ", arr[i]);
    
    //find the max value in array
    max = 0;//index of assumed maximum
    for(i = 1; i < 6; i++)
    {
        if(arr[i]  > arr[max])
            max = i;
    }//for
    
    printf("\n Replacing maximum value %d with 0 ", arr[max]);
    arr[max] = 0;
    
    printf("\n ");
    for(i =0 ; i < 6; i++)
        printf(" %d ", arr[i]);

    return 0;
}