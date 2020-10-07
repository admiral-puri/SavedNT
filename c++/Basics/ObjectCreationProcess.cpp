//Program to demonstrate:
//Object Creation Process
//Constructor
//Constructor Overloading

#include<iostream>
#include<cstring>

using namespace std;

class Person
{
public://will discuss later

  //attributes
  char name[20];
  int age;

  //object initializers

  Person() //Default Constructor
  {
    cout<<"\n Person()";
    age = 0;//default value
    strcpy(name,"baby");//default value
  }

  Person(int a, char nm[])//Parameterized Constructor
  {
    cout<<"\n Person(int,char[])";
    age = a;//parameter value
    strcpy(name, nm);//parameter value
  }

  //operations
  void display()
  {
    cout<<"\n Name : "<<name;
    cout<<"\n Age : "<<age;

  }

};


int main()
{
  cout<<"\n --------";
  Person p; //object of class Person
  cout<<"\n --------";
  Person p1(10, "Vikas"); //object of class Person
  cout<<"\n --------";

  p.display();
  p1.display();
  return 0;
}
