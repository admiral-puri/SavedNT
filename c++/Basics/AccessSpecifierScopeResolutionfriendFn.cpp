//Program to demonstrate:
//Access Specifiers
//Scope Resolution Operator
//friend function

#include<iostream>

using namespace std;


class Myclass
{
private:
  int x,y; //access limited to current class only

public:

  //access spans across the program
  Myclass();
  Myclass(int,int);
  void display();
  //grant access of all members of this class to void fx
  friend void fx();
};

Myclass :: Myclass()
{
  cout<<"\n Myclass() ";
  x = 10;
  y = 20;
}

Myclass :: Myclass(int q, int w)
{
  cout<<"\n Myclass(int,int) ";
  x = q;
  y = w;
}

void Myclass ::display()
{
  cout<<"\n"<<x<<" "<<y;
}

void fx()
{
  Myclass m(11,22);
  int sum;
  sum = m.x + m.y;
  m.display();
  cout<<"\nAddition : "<<sum;
}

int main()
{
  fx();
  return 0;
}
