//Program to demonstrate
//1) Arrays of Secondary Types
//2) Array Initializer

//Refer : ArraySecondaryTypes.txt
//See : ArraySecondaryTypes.png


//Program to demonstrate:
//Object Creation Process
//Constructors

#include<iostream>
#include<cstring>

using namespace std;

class Myclass
{
public://will discuss later

  //attributes
  int x,y;

  //object initializers
  Myclass() //Default Constructor
  {
    cout<<"\n Myclass()";
    x= 10;
    y = 20;
  }

  Myclass(int q, int w)//Parameterized Constructor
  {
    cout<<"\n Myclass(int,int)";
    x = q;
    y = w;
  }

  //operations
  void display()
  {
    cout<<"\n "<<x<<" "<<y;

  }

};


int main()
{
  //Array elements (objects) initialized by default constructor
  //Myclass arr[3]; 

  //Array initializer used to initialize the elements (objects) using specific constructors
  Myclass arr[3] = {Myclass(), Myclass(1,2), Myclass(11,22)};
  
  //possiblilty of application of algorithms
  int i;
  for(i =0; i < 3; i++)
    arr[i].display();

  return 0;
}
