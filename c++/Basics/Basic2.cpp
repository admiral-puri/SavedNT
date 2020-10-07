//Basic C++ Program
//Demonstrating : cout and cin
//Refer : Streams.png, about_cin_cout_cerr.txt

#include<iostream>
using namespace std;

int main()
{
 int q, w; //local variables

 cout<<"\n Enter a number : ";
 cin>>q;//5
 w = q*q*q;//125

/*
 cout<<"\n Cube of ";
 cout<<q;
 cout<<" is ";
 cout<<w;
*/

 //cascading insertion
 cout<<"\n Cube of "<< q <<" is "<< w;
 
 return 0;
}//main