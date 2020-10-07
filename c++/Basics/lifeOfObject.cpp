//Program to demonstrate :
//Life of an object
//Destructor

#include<iostream>
using namespace std;

class Myclass
{
public:
  Myclass();//constructor
  void fx1();//mem fn
  void fx2();//mem fn
  ~Myclass();//destructor
};

Myclass :: Myclass()//constructor
{
  cout<<"\n Life starts";
}
void Myclass :: fx1()//mem fn
{
  cout<<"\n Process 1 on object";
}

void Myclass ::fx2()//mem fn
{
  cout<<"\n Process 2 on object";
}

Myclass :: ~Myclass()//destructor
{
  cout<<"\n Life ends";
}

void f1()
{
  Myclass m;
  m.fx1();
  m.fx2();
}

void f2()
{
  Myclass obj;
  obj.fx1();
}


int main()
{
  cout<<"\n--------";
  f1();
  cout<<"\n--------";
  f2();
  cout<<"\n--------";

  return 0;
}
