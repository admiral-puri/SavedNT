//Program to demonstrate
//Use of copy constructor
//to apply deep copy

//see DynArr Shallow Copy.png
//see DynArr Deep Copy.png


#include<iostream>
using namespace std;

class DynArr
{
private:
  int size;
  int *ptr;

public:
  DynArr();//default constructor
  DynArr(DynArr&);//copy constructor
  void increment();
  void display();
  ~DynArr();
};

DynArr :: DynArr()
{
  cout<<"\n DynArr()";
  size = 5;
  ptr = new int[size];
  int i;
  for(i =0 ; i< size; i++)
    ptr[i] = 11 * (i+1);
}

DynArr :: DynArr(DynArr &src)
{
  cout<<"\nDynArr(DynArr&)";
  size = src.size;
  //new memory allocation
  ptr = new int[size];
  //data copy
  int i;
  for(i =0; i< size; i++)
    ptr[i] = src.ptr[i];

}

void DynArr :: increment()
{
  int i;
  for(i =0 ; i < size; i++)
    ptr[i]++;
}


void DynArr :: display()
{
  cout<<"\n"<<ptr<<"\n";
  int i;
  for(i =0 ; i < size; i++)
    cout<<ptr[i]<<"  ";
}

DynArr :: ~DynArr()
{
  cout<<"\n ~DynArr("<<ptr<<")";
  //free the dynarr
  delete ptr;
}

void fx(DynArr obj)//object, as a parameter, is passed by value.
{
  obj.increment();
  obj.display();
}


int main()
{
  DynArr d;
  cout<<"\n-------------";
  fx(d);
  cout<<"\n-------------";
  d.display();
  return 0;
}
