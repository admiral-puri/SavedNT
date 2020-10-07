//Operator Overloading

#include<iostream>
using namespace std;

class Time
{
private:
  int h,m,s;
public:
  Time();
  Time(int,int,int);
  void display();
  Time operator +(Time &);
  Time operator -(Time &x);
  bool operator ==(Time &);
  friend Time& operator ++(Time &t)
  {
      t.h++;
      t.m++;
      t.s++;
  }//pre increment
  Time operator ++(int);//post increment

  Time operator + (int );

  int operator [](int );
  Time* operator ->();
  void operator ()(int, int , int );
  Time & operator ()(Time &);
  Time& operator =(int);

//conversion functions
  operator int();
  operator double();

//friend function
  friend Time operator + (int x, Time &r);
  friend ostream& operator <<(ostream &o, Time &r);
  friend istream& operator >>(istream &in, Time &r);

};


Time:: Time()
{
  h = m = s = 0;
}

Time:: Time(int a, int b, int c)
{
  h = a;
  m = b ;
  s = c;
}

void Time :: display()
{
  cout<<"\n"<<h<<":"<<m<<":"<<s;
}

Time Time :: operator +(Time &x)
{
  Time temp;
  temp.h = h + x.h;
  temp.m = m + x.m;
  temp.s = s + x.s;

  return temp;
}

Time Time :: operator -(Time &x)
{
  Time temp;
  temp.h = h - x.h;
  temp.m = m - x.m;
  temp.s = s - x.s;

  return temp;
}

bool Time :: operator ==(Time &x)
{
  return (h==x.h && m==x.m && s==x.s);
}

//t1++0
Time Time :: operator ++(int a)//post increment
{
  //to avoid the waring : a is assigned a value that is never used
  a = a;

  Time copy;
  copy.h = h;
  copy.m = m;
  copy.s = s;

  //increment the operand
  h++;
  m++;
  s++;

  //return the original value
  return copy;
}

//++t1
/*Time& Time :: operator ++()//pre increment
{
  //increment the operand
  h++;
  m++;
  s++;

  //return the increment value

  return *this;
}*/

Time Time :: operator + (int x)
{
  Time temp;
  temp.h = h + x;
  temp.m = m + x;
  temp.s = s + x;

  return temp;
}

Time operator +(int x, Time &r)
{
  Time temp;
  temp.h = x+ r.h;
  temp.m = x+ r.m;
  temp.s = x+ r.s;

  return temp;
}

ostream& operator <<(ostream &o, Time &r)
{
  o<<r.h<<":"<<r.m<<":"<<r.s;
  return o;
}

istream& operator >>(istream &in, Time &r)
{
  cout<<"\n Enter Hours : ";
  in>>r.h;
  cout<<"\n Enter Minutes : ";
  in>>r.m;
  cout<<"\n Enter Seconds : ";
  in>>r.s;

  return in;
}

//t1 = 5
Time& Time :: operator =(int x)
{
    h = m = s = x;
    return *this;//returning the caller object for cascading support
}

//t1[0]
int Time :: operator [](int i)
{
    if(i == 0)
      return h;
    else if(i == 1)
      return m;
    else if(i == 2)
      return s;
    else
    {
      cout<<"\n Invalid Index ";
      return 0;
    }
}

//t1->display()
Time* Time :: operator ->()
{
    h++;//any logic
    return this;
}

//t1(10,11,12)
void Time :: operator ()(int x, int y, int z )
{
  h = x;
  m = y;
  s = z;
}

//t1(t2)
Time & Time :: operator ()(Time &r)
{
  h = r.h;
  m = r.m;
  s = r.s;
  return r;
}

//x = t1;
Time :: operator int()
{//time in seconds
 return h*60*60 + m*60 +s;
}

//d = t1
Time :: operator double()
{//time in hours
 return h + m/60.0 + s/3600.0;
}


int main()
{
  Time t1(10,20,30);
  Time t2(1,2,3);
  Time t3;

  cout<<t1[1];

  t1 = 7;
  t1->display();

  t1(6,7,8);
  t3(t1);

  int q;
  double w;
  q = t1;
  w = t3;

  cout<<"\n t1 : "<<t1;
  cout<<"\n t3 : "<<t3;
  cout<<"\n q : "<<q;
  cout<<"\n w : "<<w;

  //cin>>t1>>t2;

  //t3 = t1 + 5;
  //cout<<t1<<t3;

  //t3 = 5 +t2;
  //cout<<t2<<t3;

  //t3 = t1 + t2;
  //t3 = t1 - t2;

  //t1.display();
  //t2.display();
  //t3.display();

  //if(t1 == t2)
  //  cout<<"\n Equal Objects";
  //else
  //  cout<<"\n Not Equal Objects";

  t3 = t1++; // t3 = t1++0;
  t1.display();
  t3.display();

  t3 = ++t1;
  t1.display();
  t3.display();

  return 0;
}

/*
C++ supports application of
operators on variables of
primary types.

But for application on objects
of secondary types, the system
has a small (following) set of
operators.

Operators that can act on
secondary types:
{=,.,&,sizeof,new,delete}

C++ allows definition of
operator functions that provide
the action of operator on
the objects of secondary types.

After which the operator can
be applied on the objects of
secondary types.


Operator Overloading
-----------------------
Operator overloading is defining
operator functions that provide
action of an operator on the
objects of secondary types.

Learn By Case Study:


1) t1 + t2
----------------
The above expression looks
like an addition statement,
but for the system it is a
call to an operator function.

For the call :
 t1 acts as the caller object.
 + is the operator function.
 t2 is the actual parameter.

2) t1 - t2
--------------
On the same line as of case 1)

3) t1 == t2
--------------
The above expression looks
like a comparison statement,
but for the system it is a
call to an operator function.

For the call :
 t1 acts as the caller object.
 == is the operator function.
 t2 is the actual parameter.

4 and 5) t1++  and ++t1
---------------------------
The above expressions look
like increment statements,
but for the system they are
calls to operator functions.

For the call t1++ :
 t1 acts as the caller object.
 ++ is the operator function.

For the call ++t1 :
 t1 acts as the caller object.
 ++ is the operator function.

By implementation it is known
that the two definitions (pre
and post increment) take the
same signature.

System doesn't allow multiple
functions to have the same
signature.

This issue was identified by
the developers of C++ and a
compiler fix was introduced.

"Post increment to be used
as unary operator but defined
as binary operator.
Internally compiler will pass
a parameter to it and that the
definition of post increment
would catch the parameter
but may ignore it ahead."

6) t1 + 5
----------------
The above expression looks
like an addition statement,
but for the system it is a
call to an operator function.

For the call :
 t1 acts as the caller object.
 + is the operator function.
 5 is the actual parameter.

7) 5 + t1
----------------
The above expression looks
like an addition statement,
but for the system it is a
call to an operator function.

Here 5 (an int), being on the
LHS of the operator, tends to be
the caller object for the
operator function.

But known that the type of
the function and caller object
must be the same.

And that is not same for
this case.

So it is concluded that for
the statement a valid caller
object is not available.

Hence it is decided to invoke
the operator function without
any caller object.

So the operator function is
to be overloaded as a non
member function.

For the call :
 + is the operator function.
 5 is the first actual parameter.
 t1 is the second actual parameter.

8) cout << t1
----------------
The above expression looks
like a output to display device
statement, but for the system
it is a call to an operator
function.

Here cout (an ostream object),
being on the LHS of the operator,
tends to be the caller object
for the operator function.

But known that the type of
the function and caller object
must be the same.

And that is not same for
this case.

So it is concluded that for
the statement a valid caller
object is not available.

Hence it is decided to invoke
the operator function without
any caller object.

So the operator function is
to be overloaded as a non
member function.

For the call :
 << is the operator function.
 cout is the first actual parameter.
 t1 is the second actual parameter.

9) cin>>t1
-------------
On the same line as of case 8)

10) and 11) see : OpNewDel.cpp
------------------------------------

12) t1[indx]
----------------
The above expression looks
like an array usage statement,
but t1 being declared as an
object (and not as an array),
for the system it is a call
to an operator function.

For the call :
 t1 acts as the caller object.
 [] is the operator function.
 indx is the actual parameter.

13) : t1->display()
Operator -> (infix dereferencing) is applied on one Time object and one member of the Time class.
Certain restrictions apply for overloading of the operator ->
1) It is a unary operator, i.e. it acts on one operand and it is the caller object.
2) Its return type must be Time * (It should return address of a Time object).
3) It can only be overloaded as a member function.

Developer is free to put up any logic against its invokation.
Refer the implementation.

14) : t1(1,2,3) and t1(t2)
Here operator () is applied on 1 Time object and arbitrary parameters.
For the user it seems a function call.
But for the C++ system, it is call to operator ()
with arbitrary set of parameters.

System treats:
 t1 as the caller object
 () as the operator function
 parameters as parameters.

15) t1 = 5
-------------
The above expression looks
like an assignment statement,
but for the system it is a
call to an operator function.

For the call :
 t1 acts as the caller object.
 = is the operator function.
 5 is the actual parameter.


16) x = t1
Here operator = is applied on 1 int and 1 Time object
For the user it is an assignment expression
but for the C++ system it is a case of
type-conversion of Time object into int.

System doesn't treat the expression as
a case of operator call because:
1) On the LHS of the operator there is an int,
which cannot act as the caller object.
2) Operator = cannot be overloaded as a
non member function.

Type Conversion / Conversion Functions :
is defining operator functions that
convert object of a secondary type
into a value of a primary type.

Type Conversion function take special
signature:
 operator <primary type>()
 {
    conversion logic
    return value primary type
 }
 Refer : 2 examples

--------------------------------------------
Operator Overloading Rules and Restrictions
--------------------------------------------
There are some rules and restrictions that
apply to operator overloading.

* New operators cannot be defined using operator overloading.
* Precedence/Associativity of an operator cannot be altered.
* Number of operands that an operator takes cannot be changed,
  except for the operator ().
* Operator functions cannot have default arguments.
* These operators cannot be overloaded :-
  . :: .* ?
* There are some restrictions that apply to
  friend operator functions.
  You cannot overload the
  = () [] –> operators
  by using a non member function.


*/
