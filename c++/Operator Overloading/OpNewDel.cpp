//Operator Overloading
//new
//delete

#include<iostream>
#include<cstdlib>

using namespace std;

class Myclass
{
  int x, y;
public:
  Myclass();
  void increment();
  void display();
  ~Myclass();

  void operator delete(void *);
  void * operator new(size_t);

};

Myclass :: Myclass()
{
  cout<<"\n Myclass("<<this<<")";
  x = 1;
  y = 2;
}

void Myclass :: increment()
{
  x++;
  y++;
}

void Myclass :: display()
{
  cout<<"\n"<<x<<" "<<y;
}

Myclass :: ~Myclass()
{
  cout<<"\n ~Myclass("<<this<<")";

}


void * Myclass :: operator new(size_t qty)
{
  cout<<"\n in new ";
  void *p;
  p = malloc(qty);
  //optionally act on p
  cout<<p<<" ";
  return p;
}

void Myclass :: operator delete(void *p)
{
  cout<<"\n in delete";
  //optionally act on p
  cout<<p<<" ";
  free(p);
}

void fx1()
{//object declared
  Myclass m1;
  m1.increment();
  m1.display();
}


Myclass * fx2()
{//object allocated
  Myclass * p = new Myclass();
  p->increment();
  p->display();
  return p;
}

int main()
{
  fx1();
  Myclass * q = fx2();
  q->increment();
  q->display();

  delete q;//object deallocated
  return 0;
};

/*
Known that the operators:
 1) new
 2) delete
act on primary and secondary types,
both.

Still C++ allows overloading the
two for customized memory management.

In case an application wants to overload
either of the two operators, it has to
abide the following signatures:

void * operator new(size_t);
void operator delete(void *);


FYI:
Overload new and delete as 
1) Non member functions to support custom memory management for primary datatypes.
2) Member functions to support custom memory management for secondary datatypes.


*/
