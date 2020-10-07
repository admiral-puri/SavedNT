//Program to demonstrate
//Passing object as parameter to a function
//* By Value 
//* By Reference

//Pass By Value : Same as covered in C
//Pass By Reference : see reference.txt, reference.png
//Run step by step and observe the output


#include<iostream>
using namespace std;

class Myclass
{
private:
  int x, y;
public:
  Myclass();
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

void fx1(Myclass obj)//Pass by Value
{
  obj.increment();
  obj.display();
}

void fx2(Myclass &ref)//Pass by Reference
{
  ref.increment();
  ref.display();
}


int main()
{
  Myclass m;//10 ,20
  cout<<"\n-------------";
  fx1(m);
  m.display();
  cout<<"\n-------------";
  fx2(m);
  m.display();
  cout<<"\n-------------";
  return 0;
}
