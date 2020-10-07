//Program to demonstrate:
//class
//object
//this pointer
//Refer : classObjectThis.txt
//see : classObjectThis.png

#include <iostream>
using namespace std;

class Clock
{
public: //will discuss later
  int h,m,s;//member variables

  //member functions
  void setTime(int a, int b, int c)
  {
    h = a;//this->h = a;
    m = b;//this->m = b;
    s = c;//this->s = c;
  }

  //void displayTime(Clock *this )
  void displayTime()
  {
    cout<<"\n"<<h<<":"<<m<<":"<<s;
  }

};

int main()
{
  Clock c; //object
  //object use
  c.setTime(1,2,3);//setTime(&c,1,2,3);
  c.displayTime();//displayTime(&c);
  return 0;
}
