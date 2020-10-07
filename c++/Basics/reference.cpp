//Program to study "References"
//refer : reference.txt
//See : reference.png


#include<iostream>
using namespace std;


void fx1(int y)//pass by value
{
  cout<<"\n in fx1, y = "<<y<<"  "<< &y;
  y++;
  cout<<"\n in fx1, y = "<<y<<"  "<< &y;
}

void fx2(int &q)//pass by reference
{
  cout<<"\n in fx2, q = "<<q<<"  "<< &q;
  q++;
  cout<<"\n in fx2, q = "<<q<<"  "<< &q;

}

int main()
{
  int x;
  x = 10;
  cout<<"\n in main, x = "<<x<<"  "<< &x;
  fx1(x);
  cout<<"\n in main, x = "<<x<<"  "<< &x;
  fx2(x);
  cout<<"\n in main, x = "<<x<<"  "<< &x;

  //stand alone reference
  ostream &vout = cout;
  vout<<"\n Use References in C++";


  return 0;
}
