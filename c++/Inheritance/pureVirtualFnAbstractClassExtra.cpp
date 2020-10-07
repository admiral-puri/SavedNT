//Demonstration of :
//pure virtual functions
//abstract class

//implement a system that
//uses one algorithm to process
//a category of objects


#include<iostream>
using namespace std;

class Animal
{
public:
  void fx();
  virtual string getType()=0;
  virtual int foodQty()=0;
  virtual string foodItem()=0;
};

void Animal :: fx()
{
  cout<<"\n push the "<< getType()<< " away";
}

class Lion : public Animal
{
public:
  int foodQty();
  string foodItem();
  string getType();
};

string Lion :: getType()
{
  return "Lion";
}

int Lion ::foodQty()
{
  //calculation
  return 20;
}
string Lion ::foodItem()
{
  //choice/routine/food plan
  return "flesh";
}


class Elephant : public Animal
{
public:
  string getType();
  int foodQty();
  string foodItem();
};


string Elephant:: getType()
{
  return "Elephant";
}

int Elephant::foodQty()
{
  //calculation
  return 200;
}
string Elephant ::foodItem()
{
  //choice/routine/food plan
  return "vegtables";
}

class Rabbit : public Animal
{
public:
  string getType();
  int foodQty();
  string foodItem();
};


string Rabbit:: getType()
{
  return "Rabbit";
}

int Rabbit::foodQty()
{
  //calculation
  return 2;
}
string Rabbit ::foodItem()
{
  //choice/routine/food plan
  return "carrots";
}

void feed(Animal *p)
{
  cout<<"\n----------------";
  cout<<"\n get the food truck near the cage ";
  p->fx();
  cout<<"\n open food gate ";
  cout<<"\n put in "<<p->foodQty()<<" units of "<< p->foodItem();
  cout<<"\n close the food gate";
  cout<<"\n----------------";
}

int main()
{
  Lion l;
  Elephant e;
  Rabbit r;

  feed(&l);
  feed(&e);
  feed(&r);

  return 0;
}
