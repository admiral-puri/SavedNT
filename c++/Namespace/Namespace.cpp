//Studying namespaces

#include<iostream>

using namespace std;

namespace My
{
  void fx()
  {
    cout<<"\n My fx()";
  }

  int x = 10;

  namespace NestedMy
  {
    int x = 100;
  }
}


namespace My
{
  void fx1()
  {
    cout<<"\n Mutliple namespaces with the same name will merge up ";
  }
}

int x = 1000;

void fx()
{
  cout<<"\n global fx()";
}


int main()
{
  cout<<"\n local x : "<<x;
  cout<<"\n global x : "<<::x;
  cout<<"\n My x : "<<My::x;
  cout<<"\n My NestedMy x : "<<My::NestedMy::x;

  cout<<"\n cout: "<<cout;

  fx();//global fx
  //or
  //::fx();

  My::fx();//My fx
  My::fx1();
  return 0;
}
