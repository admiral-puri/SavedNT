/*
Fibonacci search technique is a method 
of searching a sorted array using a divide 
and conquer algorithm that narrows down 
possible locations with the aid of Fibonacci 
numbers.


Algorithm

Let the searched element be x.

The idea it to first find the smallest 
Fibonacci number that  is greater than 
or equal to length of given array. 

Let the found fibonacci number be fib (n’th fibonacci number). 
We use (n-2)’th Fibonacci number as index (If it is a valid index). 
Let (n-2)’th Fibonacci Number be i, 

Compare arr[i] with x 
if x is same, return i. 
Else if x is greater, recur for subarray after i, 
else recur for subarray before i.

*/

// C program for Fibonacci Search
#include <stdio.h>
 
//fibonacci numbers :
//0 1 1 2 3 5 8 13 21 34 55 ...

// to find minimum of two elements
int min(int x, int y) 
{ 
    if (x<=y)
        return x;
    return y; 
}
 

int fSearch(int arr[], int x, int n)
{
    int fibn2 = 0;   // first Fibonacci No.
    int fibn1 = 1;   // second Fibonacci No.
    int fibn = fibn2 + fibn1;  // n'th Fibonacci
 
    /* 
      fibn is going to store the smallest Fibonacci
      Number greater than or equal to n 
     */
    while (fibn < n)
    {
        fibn2 = fibn1;
        fibn1 = fibn;
        fibn  = fibn2 + fibn1;
    }
 
    int offset = -1;
 
    /* Compare arr[fin2] with x. 
      When fibn becomes 1, fibn2 becomes 0 */
    while (fibn > 1)
    {
        // Check if fibn2 is a valid location
        int i = min(offset+fibn2, n-1);
 
        /* If x is greater than the value at index fibn2,
           cut the subarray array from offset to i */
        if (arr[i] < x)
        {
            fibn  = fibn1;
            fibn1 = fibn2;
            fibn2 = fibn - fibn1;
            offset = i;
        }
 
        /* If arr[i] is greater than x ,
           cut the subarray after i+1  */
        else if (arr[i] > x)
        {
            fibn  = fibn2;
            fibn1 = fibn1 - fibn2;
            fibn2 = fibn - fibn1;
        }
        /* element found. return index */
        else 
            return i;
    }
 
    // comparing the last element with x 
    if(fibn1 && arr[offset+1] == x)
        return offset+1;
 
    // element not found. return -1 
    return -1;
}
 
int main(void)
{
    int indx;
    int arr[] = {10, 15, 25, 30, 41, 50, 80, 82, 85, 90, 91};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 901;
    
    indx = fSearch(arr, x, n);
    if(indx == -1)
        printf("\n %d not found ", x);
    else
        printf("Found at index: %d", indx);
    
    return 0;
}