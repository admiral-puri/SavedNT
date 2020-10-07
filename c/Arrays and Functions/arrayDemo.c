//Program to demonstrate Arrays
//Refer : Arrays.txt
//See : Arrays.png, arrayDemo.png

#include<stdio.h>
int main()
{
    int arr[6];//array declaration
    int i;
 
    //(input) scan an array   
    printf("\n Enter 6 numbers ");
    /*
    scanf("%d", &arr[0]);
    scanf("%d", &arr[1]);
    scanf("%d", &arr[2]);
    scanf("%d", &arr[3]);
    scanf("%d", &arr[4]);
    scanf("%d", &arr[5]);
    */        
    for(i=0; i < 6; i++)
        scanf("%d", &arr[i]);
    
    //(process) multiply all elements by 10
/*
    arr[0] = arr[0] * 10;
    arr[1] = arr[1] * 10;
    arr[2] = arr[2] * 10;
    arr[3] = arr[3] * 10;
    arr[4] = arr[4] * 10;
    arr[5] = arr[5] * 10;
*/
    for(i =0 ; i < 6; i++)
        arr[i] = arr[i] * 10;
    
    //(output) display an array
    /*
    printf(" %d ", arr[0]);
    printf(" %d ", arr[1]);
    printf(" %d ", arr[2]);
    printf(" %d ", arr[3]);
    printf(" %d ", arr[4]);
    printf(" %d ", arr[5]);
    */        

    printf("\n");
    for(i=0; i < 6; i++)
        printf(" %d ", arr[i]);
      
    return 0;
}