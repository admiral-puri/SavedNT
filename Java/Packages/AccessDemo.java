//Program to study effect of various access specifiers
//on members of class.
//See : Access Specifiers 1.png
//See : Access Specifiers 2.png
//See : Derived and NonDerived class objects
//Refer: Access Specifiers

//import p1.Base;
//import p1.Derived;
//import p1.NonDerived;
//import p2.Derived1;
import p2.NonDerived1;


class AccessDemo
{
 public static void main(String args[])
 {
   //Base b = new Base();
   //b.display();

   //Derived d = new Derived();
   //d.display();

   //NonDerived nd = new NonDerived();
   //nd.display();

   //Derived1 d1 = new Derived1();
   //d1.display();

   NonDerived1 nd1 = new NonDerived1();
   nd1.display();

 }

}