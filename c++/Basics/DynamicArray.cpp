//Program to demonstrate
//Dynamic Array

#include<iostream>
using namespace std;

int * createArray(int size)
{
  int *p;
  p = new int[size];
  return p;
}

void scan(int *p, int size)
{
  int i;
  cout<<"\n Enter "<<size<<" numbers : ";
  for(i =0 ; i < size; i++)
    cin>>p[i];

}

int addition(int *p, int size)
{
  int sum =0 ;
  int i;
  for(i =0; i< size; i++)
    sum += p[i];
  return sum;
}

void display(int *p, int s)
{
  int i;
  cout<<"\n";
  for(i =0 ; i < s; i++)
    cout<<p[i]<<"  ";
}

void deallocate(int *p)
{
  delete p;
}

int main()
{
  int x;
  int * ptr;
  int tot;
  cout<<"\n Enter size of the array : ";
  cin>>x;
  ptr = createArray(x);
  scan(ptr, x);
  display(ptr,x);
  tot= addition(ptr,x);
  cout<<"\n Addition : "<<tot;
  deallocate(ptr);
  //here after ptr should not dereferenced
  return 0;
}
