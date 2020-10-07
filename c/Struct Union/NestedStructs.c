/*
Program to demonstrate:
1. Nesting of structs
2. struct object initializer

Nested Structs
-------------------
 C allows nesting of structs.
 It is all about creating a struct object as a member of another struct.  
 
 FYI : 
 * A struct cannot have an object of its own type in its definition. 
 * But can have a pointer of its own type in its definition.

struct Object Initializer
----------------------------
A struct object initializer can be used to assign
default values to a struct object while creation
(declaration).

The initializer takes the form as of the array initializer.

System expects zero to all values specifed in the initializer.

The values must be specified in the same order as the order of declartion of members inside the struct.

*/

#include<stdio.h>

struct Address
{
  int plotNo;
  char location[20];
  char city[20];
};
typedef struct Address Address;

struct Person
{
  char name[20];
  int age;
  char gender;
  Address adrs;//nesting structs
};
typedef struct Person Person;


void print(Person a)//The formal parameter gets defined as a copy of the actual parameter
{
  printf("\n { %s %d %c { %d, %s, %s}}", a.name, a.age , a.gender,a.adrs.plotNo, a.adrs.location, a.adrs.city);
}//print

int main()
{
  //declare and initialize the object
  Person p = {"Vikas", 5, 'm', {12, "Vishrantwadi", "Pune"}};

  //display
  print(p);//passing object as a parameter to a function by value

  return 0;
}
