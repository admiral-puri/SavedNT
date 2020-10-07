/*
Generic Functions
---------------------
Generic functions are functions
that, using a common logic, can
process data of multiple different
types (primary and secondary).

In C++, generic functions are 
also called as "template functions".


Syntax:
  template<class X> returnType fnName(X Param, ...)
  {
    common logic on X
  }

Example:
  template<class X> void swap(X &n1, X &n2)
  {
    X temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
  }
  

 

In the syntax and the example, X
is defined as a generic type. It 
has the ability to represent every
primary and secondary type.

It is the one that makes the function
act on values for all possible types.
*/

//Demonstration of :
//Generic Functions

#include<iostream>
using namespace std;

template <class X> void display(X arr[], int s)
{
  int i;
  cout<<"\n";

  for(i =0; i < s; i++)
    cout<<arr[i]<<"  ";
}

template <class X> void interchange(X &val1, X &val2)
{
  X temp;
  temp = val1;
  val1 = val2;
  val2 = temp;
}

template <class X> void bubbleSort(X arr[], int s)
{
  int i, j;
  for(i = s-1; i > 0; i--)
  {
    for(j =0; j < i; j++)
    {
      if(arr[j] > arr[j+1])
      {
        interchange(arr[j], arr[j+1]);
      }
    }

  }//for(i
}

int main()
{
  int iarr[] = {4,5,1,10,8};
  char carr[] = {'q', 'd', 'a', 'g'};
  double darr[] = {1.102, 1.1, 1.101};

  display(iarr, 5);
  display(carr, 4);
  display(darr, 3);

  bubbleSort(iarr, 5);
  bubbleSort(carr, 4);
  bubbleSort(darr, 3);

  display(iarr, 5);
  display(carr, 4);
  display(darr, 3);

  return 0;
}
