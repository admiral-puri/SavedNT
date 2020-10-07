//Program to demonstrate
//copy constructor

#include<iostream>
using namespace std;

class Myclass
{
private:
  int x, y;
public:
  Myclass();//default constructor
  Myclass(Myclass &);//copy constructor
  void increment();
  void display();
  ~Myclass();
};

Myclass :: Myclass()
{
  cout<<"\n Myclass()";
  x = 10;//preset data assigned
  y = 20;//preset data assigned
}

Myclass :: Myclass(Myclass &src)
{
  cout<<"\nMyclass(Myclass&)";
  x = src.x;
  y = src.y;
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
  cout<<"\n ~Myclass()";
}

void fx(Myclass obj)//object, as a parameter, is passed by value.
{
  obj.increment();
  obj.display();
}


int main()
{
  Myclass m;//10 ,20
  cout<<"\n-------------";
  fx(m);
  m.display();
  cout<<"\n-------------";
  return 0;
}
