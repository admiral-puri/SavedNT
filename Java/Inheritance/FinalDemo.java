/*
final statement


Java allows application of final statement to :
* variables, arrays, references, ... data members.
* methods
* classes


When local or member level variable or array, etc
is declared as final then it can be assigned once
only. Next it can used as read only.

When a method is declared as final then it cannot
be overridden.

When a class is declared as final then it cannot be
extended (inherited).

*/


//final class cannot be inherited
/*final*/ class A 
{

 //final data members
 //A non static final data member must be assigned
 //once and that to only in a non static initializer
 //block or in a constructor, but not in both.
 //It cannot be assigned in a method. 
 final int q;

 //A static final data member must be assigned
 //once and that to only in a static initializer block.
 //It cannot be assigned in any method or in constructor. 
 final static int w;

 static
 {
  w = 99; //one assignment, valid. 
 }


 A()
 {
  q = 10;
 }

 A(int x)
 {
  q = x;
 }

 final void fx()
 {
   System.out.println("fx of A is a final method, it cannot be overridden");
   System.out.println("q : " + q);
   System.out.println("w : " + w );
 }
}

class B extends A
{
//final methods cannot be overridden
/*
 void fx()
 {
   System.out.println("fx of B");
 }
*/
}

class FinalDemo
{
 public static void main(String args[])
 {
   
   final A objA1 ;
   objA1 = new A();//assign once, not necessary that it is to be assigned along with declaration
   
   A objA2 = new A(100);

   objA1.fx();
   objA2.fx();

 }
}