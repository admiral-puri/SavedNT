//Program to test w/r of values of
//primitive types to/from the file.

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
  char fname[30] = "e:/primData.txt";
  //open the file for i/o

  fstream fio(fname, ios::in|ios::out|ios::binary|ios::trunc);

  //test open state
  if(!fio.is_open())
  {
    cerr<<"\n File Open Failed ";
    return 1;
  }

  //file is open
  //write the data

  int i1,i2;
  bool b1,b2;
  double d1,d2;
  char c1,c2;


  i1 = 123456;
  b1 = true;
  d1 = 345.678;
  c1 = 'q';

  //write the primitive values in the file
  fio<<i1<<"\n";
  fio<<b1<<"\n";
  fio<<d1<<"\n";
  fio<<c1<<"\n";

  //position the file read pointer at BOF
  fio.seekg(0, ios::beg);

  //read back the primitive values
  fio`i2;
  fio>>b2;
  fio>>d2;
  fio>>c2;

  //close the file
  fio.close();

  //proof
  cout<<"\n"<<i1<<"\t"<<i2;
  cout<<"\n"<<b1<<"\t"<<b2;
  cout<<"\n"<<d1<<"\t"<<d2;
  cout<<"\n"<<c1<<"\t"<<c2;


  return 0;
}
