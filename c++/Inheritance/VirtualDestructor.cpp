//Demonstration of :
//Virtual Destructor

#include<iostream>
using namespace std;

class A
{
public:
  A();
  void fx();
  virtual ~A();
};

A:: A()
{
  cout<<"\n A A() ";
}

void A :: fx()
{
  cout<<"\n A fx()";
}

A :: ~A()
{
  cout<<"\n A ~A()";
}


class B : public A
{
public:
  B();
  void fx();
  ~B();
};
void B::fx()
{
  cout<<"j";
}
B :: B()
{
  cout<<"\n B B() ";
}

B :: ~B()
{
  cout<<"\n B ~B() ";
}

void test()
{
  B A;
  A.fx();
  //delete ptrA;
}

int main()
{
  cout<<"\n ------ ";
  test();
  cout<<"\n ------ ";

  return 0;
}
