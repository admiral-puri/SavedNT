//Program to implement mergeSort

#include<stdio.h>
#define SIZE 30

void mergeSort(int arr[], int s)
{
 int s1, s2;
 int i, j, k;
 int arr1[SIZE], arr2[SIZE];
 int temp;

 //Split the array into 2 portions
 if(s%2==0)
  s1 = s2 = s/2;
 else
 {
  s1 = s/2 + 1;
  s2 = s/2;
 }


 //copy s1 elements in arr1
 for(i =0; i < s1; i++)
   arr1[i] = arr[i];

 //copy s2 elements in arr2
 for(i =0; i < s2; i++)
   arr2[i] = arr[i+s1];

 //check size of arr1 for merge
 if(s1 >2)
 {
  //recursion
  mergeSort(arr1, s1);
 }
 else if(s1 ==2)
 {
  //compare and arrange the 2 elements in ascending order
  if(arr1[0] > arr1[1])
  {//swap
    temp = arr1[0];
    arr1[0] = arr1[1];
    arr1[1] = temp;
  }
 }


 //check size of arr2 for merge
 if(s2 >2)
 {
  //recursion
  mergeSort(arr2, s2);
 }
 else if(s2 == 2)
 {
  //compare and arrange the 2 elements in ascending order
  if(arr2[0] > arr2[1])
  {//swap
    temp = arr2[0];
    arr2[0] = arr2[1];
    arr2[1] = temp;
  }

 }

 //merge

 i = 0;//index for arr1
 j = 0;//index for arr2
 k = 0;//index for arr3

 //until i < s1 and j < s2
 while(i < s1 && j < s2)
 {
  if(arr1[i] <= arr2[j])
  {//true: arr1[i] to copy into arr[k]
   arr[k] = arr1[i];
   i++;
   k++;
  }
  else
  {//false: arr2[j] to copy into arr[k]
   arr[k] = arr2[j];
   j++;
   k++;

  }

 }

 //either i > s1 or j > s2

 //copy the rest elements of arr1 in arr
 while(i < s1)
 {
  arr[k] = arr1[i];
  i++;
  k++;
 }

 //copy the rest elements of arr2 in arr
 while(j < s2)
 {
  arr[k] = arr2[j];
  j++;
  k++;
 }


}//merge

int main()
{
  int arr[] = {18,10,5,12,7,3,8,15,11};
  int i; //loop control

  printf("\n");
  for(i =0 ; i < 9; i++)
    printf(" %d ", arr[i]);

  mergeSort(arr, 9);

  printf("\n");
  for(i =0 ; i < 9; i++)
    printf(" %d ", arr[i]);


  return 0;
}


