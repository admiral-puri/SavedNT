//Program to demonstrate : pass by reference
#include<stdio.h>

void fx(int a[])//formal parameter a is an int array reference. It is a link to the memory of actual parameter array.
{
    a[1] = 99;
}

int main()
{
    //int arr[3];//all elements are garbage filled
    //int arr[3] = { };//all elements are set to 0
    //int arr[3] = {10};//first element 10 and rest 0
    //int arr[3] = {10,20};//first element 10 , second 20 and rest 0
    int arr[3] = {10,20,30};//elements 0,1,2 set to 10,20,30 respectively
    //int arr[3] = {1,2,3,4,5};//error or warning : excess values in initializer
    int i;
    
    printf("\n");
    for(i =0 ; i < 3; i++)
        printf(" %d ", arr[i]);
    
    fx(arr);//passing array as parameter to the function fx
    
    printf("\n");
    for(i =0 ; i < 3; i++)
        printf(" %d ", arr[i]);
    
                
                
    return 0;
}
