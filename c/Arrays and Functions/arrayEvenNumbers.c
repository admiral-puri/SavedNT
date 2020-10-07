//Program to print the even numbers of an array

#include<stdio.h>

int main()
{
    int arr[6];//declare an array of 6 elements
    int i;
    printf("\n Enter 6 numbers : ");
    for(i =0; i < 6; i++)
        scanf("%d", &arr[i]);

    printf("\n Even Numbers of the array are : \n ");
    for(i =0 ; i < 6; i++)
    {
        if(arr[i] % 2 == 0)
            printf(" %d ", arr[i]);
    }
    return 0;
}