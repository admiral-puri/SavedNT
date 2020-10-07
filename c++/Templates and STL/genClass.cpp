/*
Generic Class
----------------
A generic class is a class objects
of which can store and process data
of multiple different types.

For a generic class, the data members
can be of generic type or any primary
or secondary type.

But all the functions of a generic
class must be generic functions.
*/

//Demonstration of :
//Generic Class

#include<iostream>
#define SIZE 5

using namespace std;

template <class X> class Stack
{
  //data members
  X data[SIZE];//generic container
  int top;//topmost element

public:
  //constructor
  Stack();

  //member functions
  void push(X); //add a val
  X pop();//remove a value
  void display();//view

};


template<class X> Stack<X> :: Stack()
{
  top = -1;//indicate empty state
}


template<class X> void Stack<X> :: push(X val)//add a value
{
  if(top< SIZE-1)
  {
    top++;//raise
    data[top] = val;//insert
  }
  else
    cout<<"\n Stack Overflow";
}


template <class X> X Stack<X> :: pop()//remove and return the topmost value
{
 X val = 0;//if X to represent a secondary type, then overload = to rcv 0 and set the data members to blank
 if(top > -1)
 {
  val = data[top];//fetch the value
  top--;//level reduces
 }
 else
  cout<<"\n Stack Empty";
 return val;
}

template <class X> void Stack<X> :: display()
{
  int i;
  for(i = top; i >=0; i--)
    cout<<"\n"<<data[i];
}

template<class Y> void menu(Y value)
{
  int ch;
  Y val;
  //Stack<int> intStk;
  Stack<Y> s;

  value = value;

  do
  {
    cout<<"\n 1. push ";
    cout<<"\n 2. pop ";
    cout<<"\n 3. display ";
    cout<<"\n 4. exit ";
    cout<<"\n choice : ";
    cin >> ch;

    switch(ch)
    {
      case 1://push
        cout<<"\n Enter the value to push : ";
        cin>> val;
        s.push(val);
        break;
      case 2://pop
        val = s.pop();
        cout<<"\n "<<val<<" removed";
        break;
      case 3:
        s.display();
        break;

      default:
        cout<<"\n Wrong choice ";
        break;

      case 4:
        break;
    }//switch

  }while(ch != 4);
}//menu


int main()
{
  int ch;

  cout<<"\n 1. int stack ";
  cout<<"\n 2. char stack ";
  cout<<"\n 3. double stack ";
  cout<<"\n choose : ";
  cin >> ch;

  if(ch == 1)
    menu(0);//an int
  else if(ch == 2)
    menu('a');//a char
  else if(ch == 3)
    menu(0.0);//a double
  else
    cout<<"\n Wrong choice ";


  return 0;
}
