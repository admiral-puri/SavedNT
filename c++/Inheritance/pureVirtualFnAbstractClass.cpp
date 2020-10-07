//Demonstration of :
//pure virtual functions
//abstract class

//Implement a system that
//uses one algorithm to process
//a category of objects


#include<iostream>
using namespace std;


class TimeTable
{
public:
  void period();
  virtual void practical()=0;
};

void TimeTable:: period()
{
  cout<<"\n Lets learn CO";
}


class Group1 : public TimeTable
{
public:
  void practical();
};

void Group1 :: practical()
{
  cout<<"\n Lets solve an OOP Assignment";
}

class Group2 : public TimeTable
{
public:
  void practical();
};

void Group2 :: practical()
{
  cout<<"\n Lets solve a DS Assignment";
}


void workForTheDay(TimeTable *p)
{
  cout<<"\n---------------";
  cout<<"\n Day begins ";
  p->period();
  p->practical();
  cout<<"\n Day ends ";
  cout<<"\n---------------";
}

int main()
{
  Group1 g1;
  Group2 g2;

  workForTheDay(&g1);
  workForTheDay(&g2);


  return 0;
}
