//Basic C++ Program
//Demonstrating : main(), for, if , cout and cerr
//Refer : Streams.png, about_cin_cout_cerr.txt

#include<iostream>
using namespace std;

int main() //program starts here
{
    int i; //local variable
    for(i=0; i< 10; i++) //loop
    {
        if(i % 2 == 0)
            cout<<"\n Hello Student";
        else
            cerr<<"\n Hello C++";
    }

    return 0;
}
