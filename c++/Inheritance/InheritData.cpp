//Inheritance of Data
//refer : Inheitance.txt
//see : InheritData.png

#include<iostream>

using namespace std;

class A
{
private :
  int x;
protected:
  int y;
public:
  int z;

  A();
  A(int,int,int);

  void display();
  int getX(); //accessor (getter)
};

A :: A()
{
  cout<<"\n A A()";
  x = 10;
  y = 20;
  z = 30;
}

A :: A(int q, int w , int e)
{
  cout<<"\n A A(int,int,int)";
  x = q;
  y = w;
  z = e;
}

void A :: display()
{
  cout<<"\n "<<x<<" "<<y<<" "<<z;
}

int A :: getX()
{
  return x;
}

class B : public A
{
protected:
  int sum;
public:
  B();
  B(int,int,int);

  void display();//redefine the inherited method (override)
};

B::B() // : A()
{
  cout<<"\n B B()";
  sum = getX()+y+z;
}

B::B(int p, int q, int r):A(p,q,r)
{
  cout<<"\n B B(int,int,int)";
  sum = getX()+y+z;
}


void B :: display()
{
  cout<<"\n"<<getX() <<" + "<< y <<" + "<<z <<" = "<<sum;
}

int main()
{
  B objB(1,2,3);
  objB.display();
  return 0;
}
