//Demonstration of :
//type compatibility
//runtime binding of virtual functions


#include<iostream>
using namespace std;


class A
{
public:
  void f1();
  virtual void f2();
};

void A :: f1()
{
  cout<<"\n A f1";
}

void A :: f2()
{
  cout<<"\n A f2";
}

class B : public A
{
 public:
   void f2();//overridden code
   void f3();//extended code
};


void B :: f2()
{
  cout<<"\n B f2 starts";
  f3();//extended code
  cout<<"\n B f2 ends";
}

void B :: f3()
{
  cout<<"\n B f3 ";
}


void testCompatibility(A *ptrA)
{
  cout<<"\n----------------";
  ptrA->f1();//inherited method
  ptrA->f2();//overridden method
  cout<<"\n----------------";
}

int main()
{
  A objA;
  B objB;

  testCompatibility(&objA);
  testCompatibility(&objB);

  return 0;
}
