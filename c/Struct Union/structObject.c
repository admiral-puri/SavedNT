//Program to demonstrate:
//1. Creation of custom datatype
//2. Using the custom datatype for object creation
//3. Working on the object

#include<stdio.h>

//compose a Person
//by combining various attributes

struct Person
{
  char name[20];
  int age;
  char gender;
};

int main()
{
  struct Person p;//p is an object of entity struct Person. It (p) has the attributes defined by struct Person

  //use p
  //scan
  printf("\n Enter Name of the Person ");
  scanf("%19s", p.name);
  printf("\n Enter Age of the Person ");
  scanf("%d", &p.age);
  printf("\n Enter Gender(m/f) of the Person ");
  fflush(stdin);
  scanf("%c", &p.gender);

  //display
  printf("\n { %s, %d, %c }", p.name, p.age, p.gender);

  return 0;
}
