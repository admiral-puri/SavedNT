//Program to compare:
//struct and union
//see union.png
//read the note below

#include<stdio.h>
#include<string.h>

struct SDemo
{
  int a;
  float b;
  char c[20];
};
typedef struct SDemo SDemo;

union UDemo
{
  int a;
  float b;
  char c[20];
};
typedef union UDemo UDemo;

int main()
{
  SDemo s;
  int i;
  UDemo u;

  printf("\n SIZE ");
  printf("\n struct object : %d ", sizeof(s));
  printf("\n union object : %d ", sizeof(u));


  printf("\n\n Allocation ");
  printf("\n struct object : %u, %u, %u ", &s.a, &s.b, s.c);
  printf("\n union object : %u, %u, %u ", &u.a, &u.b, u.c);

  printf("\n\n DATA ");
  s.a = 10;
  s.b = 3467.983;
  strcpy(s.c, "computer");

  u.a = 10;
  u.b = 3467.983;
  strcpy(u.c, "computer");

  printf("\n struct object : %d, %f, %s ", s.a, s.b, s.c);
  printf("\n union object : %d, %f, %s ", u.a, u.b, u.c);

  return 0;
}

/*
union
------
In C, a union allows definition of secondary datatypes.
It combines hetrogenous primary and secondary types to form a new composite datatype.
It is particularly used for representing real life entities.
Example : Generalized Linked List.

WRT the definition, syntax and purpose a 
union is similar to a struct.

But the two have following differences:
1) For a struct all the members have individual memory,
whereas for a union all the member have shared memory.

2) Hence all the members of a struct object can store data,
whereas only one member of a union object can store data at a time.

3) Also the size of a struct object is the sum of sizes of its members,
whereas the size of a union object is equal to the size of its largest sized member.

*/