//Program to demonstrate:
//1. Creation of array of custom datatype for object creation
//2. Work on the array

#include<stdio.h>

struct Person
{
  char name[20];
  int age;
  char gender;
};

void scan(struct Person a[], int s)
{
  int i;
  for(i =0; i < s; i++)
  {
    printf("\n Enter Information for Person %d ", i+1);
    printf("\n Name : ");
    scanf("%19s", a[i].name);
    printf("\n Age : ");
    scanf("%d", &a[i].age);
    printf("\n Gender(m/f) : ");
    fflush(stdin);
    scanf("%c", &a[i].gender);

  }//for
}//scan

void print(struct Person a[], int s)
{
  int i;
  for(i =0; i < s; i++)
  {
    printf("\n { %s %d %c }", a[i].name, a[i].age , a[i].gender);
  }//for
}//print

int main()
{
  struct Person arr[3];

  //scan
  scan(arr, 3);

  //display
  print(arr, 3);
  return 0;
}
