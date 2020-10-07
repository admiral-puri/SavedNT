//Hybrid Inheritance : Ambiguity issue
//Resolution 3 (Virtual Base Class)
//Refer : VirtualBaseClass.png

#include<iostream>

using namespace std;

class A
{
protected:
  int x;

  A();
  A(int);
  void display();
  ~A();
};

A :: A()
{
  cout<<"\n A A()";
  x = 10;
}

A :: A(int p)
{
  cout<<"\n A A(int)";
  x = p;
}

void A :: display()
{
  cout<<"\n (A) "<<x;
}

A :: ~A()
{
  cout<<"\n ~A()";
}

class B : virtual public A
{
protected:
  int y;
public:
  B();
  B(int);
  B(int,int);

  void display();
  ~B();
};

B::B() // : A()
{
  cout<<"\n B B()";
  y= 20;
}

B::B(int p) // : A()
{
  cout<<"\n B B(int)";
  y= p;
}

B::B(int p, int q) :A(p)
{
  cout<<"\n B B(int,int)";
  y = q;
}


void B :: display()
{
  cout<<"\n (B) "<<x <<" "<< y ;
}

B :: ~B()
{
  cout<<"\n ~B()";
}


class C : virtual public A
{
protected:
  int z;
public:
  C();
  C(int);
  C(int,int);

  void display();
  ~C();
};

C::C() // : A()
{
  cout<<"\n C C()";
  z= 30;
}

C::C(int p) // : A()
{
  cout<<"\n C C(int)";
  z= p;
}

C::C(int p, int q) :A(p)
{
  cout<<"\n C C(int,int)";
  z = q;
}


void C :: display()
{
  cout<<"\n (C) "<<x <<" "<< z;
}

C :: ~C()
{
  cout<<"\n ~C()";
}


//hybrid inheritance
class D : public B, public C
{
protected:
  int sum;
public:
  D();
  D(int,int,int);

  void display();
  ~D();
};

D :: D()
{
  cout<<"\n D D()";
  sum = x + y + z;//no ambiguity
}

D :: D(int p, int q, int r): A(p), B(q), C(r)
{
  cout<<"\n D D(int,int,int)";
  sum = x + y + z;//no ambiguity resolution
}


//override to resolve ambiguity for the use of display
void D :: display()
{
  cout<<"\n D Display";
  cout<<"\n"<<x<<" + "<<y <<" + "<< z<<" = "<<sum;
}

D :: ~D()
{
  cout<<"\n D ~D()";
}

int main()
{
  //C objC;
  //D objD;
  D objD(1,2,3);
  objD.display();
  return 0;
}
