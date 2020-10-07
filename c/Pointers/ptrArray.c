//Program to demonstrate : Pointer to an Array
//See : ptrArray.png

#include<stdio.h>

int main()
{
    int arr[6] = {10,20,30,40,50,60};
    int *p;
    int i;
    
    //referenceing
    p = arr; //p = &arr[0];
    
    //dereferencing to add 100
    for(i =0; i < 6; i++)
        *(p+i) += 100;
    
    //display
    printf("\n");
    for(i =0; i < 6; i++)
    {
        //printf(" %d ", *(p+i));
        //printf(" %d ", *(i+p));//as a+b and b+a mean the same
        //printf(" %d ", *(arr+i));//as p = arr
        //printf(" %d ", *(i+arr));
        //printf(" %d ", arr[i]);
        //printf(" %d ", p[i]);//as p = arr, also internally system takes p[i] as *(p+i)
        printf(" %d ", i[p]);//converts to *(i+p)
        //printf(" %d ", i[arr]);
        
        
    }//for
    
    return 0;
}
/*
 Conclusion:
 Name of the array and pointer to the first element
 of the array can be used interchangeably.
 i.e. Both can be used as an array or a pointer being dereferenced.
 
 The difference between the two is that name of the
 array constantly represents the address of first element
 of the array whereas pointer being a variable can be reassigned
 another address.
 i.e. arr = arr1 is illegal
 but p = arr1 is allowed 
 */