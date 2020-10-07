/*
Inheritance of data

Refer: Inheritance.txt
See: InheritData.png
*/

class A
{
 //non static data members
 int x, y;

 //non static initializer block
 {
   System.out.println("NSIB of A"); 
 } 


 A()
 {
  System.out.println("A()");
  x = 10;//preset data
  y = 20;//preset data
 }

 A(int q, int w)
 {
  System.out.println("A(int,int)");
  x = q;//parameterized data
  y = w;//parameterized data
 }

 void display()
 {
  System.out.println(x + " " + y);
 }
 
}//A

class B extends A
{
 //non static data member
 int z;

 //non static initializer block
 {
   System.out.println("NSIB of B"); 
 } 


 B()//:A()
 {
  //super();
  System.out.println("B()");
  z = x+y;  
 }

 B(int q, int w)//:A(q,w)
 {
  //must be the first statement in the constructor of sub class
  super(q, w); //passing parameters to A(int,int)
  System.out.println("B(int,int)");
  z = x+y;  
 }

 //override
 void display()
 {
  System.out.println(x + " + " + y + " = " + z);
 }
}//B

class InheritData
{
 public static void main(String args[])
 {

  //Create an object of the sub class
  //(application of inheritance of data)
  
  //B objB = new B();
  B objB = new B(1,2);
  objB.display();
 }
}