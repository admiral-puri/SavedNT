//Program to copy a file
//see : fileCopy.png
//see : File Handling.png

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
  char src[20] = "e:/success.png";//may change it
  char trgt[20] = "e:/a.png";//may change it

  //Open src file for reading

  //file must exist for opening
  ifstream fin(src, ios::in | ios::binary);//for input in binary mode

  //file will be created or overwritten
  ofstream fout(trgt, ios::out | ios::binary);//for output in binary mode

  //test open state
  if(! (fin.is_open() && fout.is_open()))
  {
    cout<<"\n File open failed ";
    return 1;//exit failure
  }

  //file is open
  //copy it

  int data;

  while((data = fin.get()) != -1)
    fout.put(data);

  //Close the file
  //Stream gets deallocated.
  //Data transfer activities cease.

  fout.close();
  fin.close();

  cout<<"\n File Copied";
  return 0;
}
