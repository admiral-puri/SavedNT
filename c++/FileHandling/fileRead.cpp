//Program to read data from a text file
//and output it on monitor
//see : fileRead.png
//see : File Handling.png

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
  //Open a file for reading

  //Create an object of ifstream.
  //Provide, fileName and mode as parameter to constructor.
  //If file exists then stream gets established otherwise not.
  //Hence, test.

  ifstream fin("e:\\a.txt", ios::in);//for input in text mode

  //test open state
  if(! fin.is_open())
  {
    cout<<"\n File open failed ";
    return 1;//exit failure
  }

  //file is open
  //read it

  int data;

  //get() is used to fetch one byte of data from the source.
  //ASCII value of the read byte is returned.
  //Internally maintained file read pointer is incremented to the next position.
  //If EOF is read, then -1 is returned.

  while((data = fin.get()) != -1)
    cout.put(data);

  //Close the file
  //Stream gets deallocated.
  //Data transfer activities cease.
  fin.close();

  return 0;
}
