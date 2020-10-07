//Demonstration of : Stack

#include<iostream>
#define SIZE 5

using namespace std;

class Stack
{
  //data members
  int data[SIZE];//container
  int top;//topmost element

public:
  //constructor
  Stack();

  //member functions
  void push(int); //add a val
  int pop();//remove a value
  void display();//view

};


Stack :: Stack()
{
  top = -1;//indicate empty state
}

void Stack :: push(int val)//add a value
{
  if(top< SIZE-1)
  {
    top++;//raise
    data[top] = val;//insert
  }
  else
    cout<<"\n Stack Overflow";
}


int Stack :: pop()//remove and return the topmost value
{
 int val = 0;
 if(top > -1)
 {
  val = data[top];//fetch the value
  top--;//level reduces
 }
 else
  cout<<"\n Stack Empty";
 return val;
}

void Stack :: display()
{
  int i;
  for(i = top; i >=0; i--)
    cout<<"\n"<<data[i];
}

void menu()
{
  int ch;
  int val;
  Stack s;

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
  menu();

  return 0;
}
