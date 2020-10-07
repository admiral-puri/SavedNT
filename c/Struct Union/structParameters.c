//Program to demonstrate:
//struct object as parameter to function

/*
By default a struct object is passed by value.
To pass it by reference :
 1) Pass address of the struct object as actual parameter.
 2) Receive the address of the struct object in a struct pointer.
 3) Dereference the pointer to access the struct object.

 struct Pointer can be dereferenced in 2 ways
 1) Using operator : *
 2) Using operator : ->
 
 When * is used to dereference a struct pointer then
 usage is as follows :
      (*ptr).member 
 Here () are applied to raise the priority and . is applied for member access.
 
 When -> is used to dereference a struct pointer then
 usage is as follows :
      ptr->member 
 Here the infix dereferencing operator
 -> is a binary operator.
 It takes a pointer to a struct object
 on LHS and member of the struct object on its RHS.
 
*/

#include<stdio.h>

struct Person
{
  char name[20];
  int age;
  char gender;
};

typedef struct Person Person;

void scan(Person *ptr)
{
  printf("\n Enter Person Information ");
  printf("\n Name : ");
  scanf("%19s", (*ptr).name);
  printf("\n Age : ");
  scanf("%d", &ptr->age);
  printf("\n Gender(m/f) : ");
  fflush(stdin);
  scanf("%c", &ptr->gender);
}//scan

void print(Person a)//The formal parameter gets defined as a copy of the actual parameter
{
  printf("\n { %s %d %c }", a.name, a.age , a.gender);
}//print

int main()
{
  Person p;

  //scan
  scan(&p);//passing object as a parameter to a function by reference

  //display
  print(p);//passing object as a parameter to a function by value

  return 0;
}
