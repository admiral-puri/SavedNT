//Program implementing Exception Handling
//Refer : ExceptionHandling.txt
//See : ExceptionHandling.png

/*
Create a class named Television that has
Data members
   model number
   screen size
   price.
Functions
   overloaded insertion operator
   overloaded extraction operator.

If more than four digits are entered for the model number
If the screen size is smaller than 12 or greater than 70
If the price is negative or over Rs. 5000
Then throw an integer.

Write a main() function that
1) instantiates a television object
2) allows user to enter data
3) displays the data members.

If an exception is caught, replace all the data member
values with zero values.
*/

#include<iostream>

using namespace std;

class Television
{
private:
   int model_number;
   int screen_size;
   int price;
public:
  void reset();
  friend void operator >>(istream &in, Television &t);
  friend void operator <<(ostream &out, Television &t);
};

void Television :: reset()
{
  model_number = 0;
  screen_size = 0;
  price = 0;
}

void operator >>(istream &in, Television &t)
{
  cout<<"\n Enter model number : ";
  in>>t.model_number;
  if(t.model_number > 9999)
    throw 1;//runtime error (exception)

  cout<<"\n Enter screen size : ";
  in>>t.screen_size;
  if(t.screen_size < 12 || t.screen_size > 70)
    throw 2;

  cout<<"\n Enter price : ";
  in>>t.price;
  if(t.price < 0 || t.price> 5000)
    throw 3;
}

void operator <<(ostream &out, Television &t)
{
  out<<"\n Model Number : "<<t.model_number;
  out<<"\n Screen Size : "<<t.screen_size;
  out<<"\n Price : Rs. "<<t.price;
}

int main()
{
  Television tv;

  try
  {
    cin>>tv;
    cout<<tv;
  }
  catch(int err_num)
  {
    switch(err_num)
    {
      case 1:
        cout<<"\n Invalid Model Number";
        break;

      case 2:
        cout<<"\n Invalid Screen Size";
        break;

      case 3:
        cout<<"\n Invalid Price";
        break;

    }//switch
    tv.reset();
    cout<<tv;
  }//catch


  return 0;
}
