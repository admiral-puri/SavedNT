/*
Interface

As a class defines a secondary datatype so
does an interface.

An interface type cannot be instantiated, it
can only be used as a reference type.

Ideally an interface is used to implement 
run time polymorphism through lose coupling.
*/
interface IDemo
{
  void ofx();
}

class A implements IDemo
{
 //override
 public void ofx()
 {
   System.out.println("A ofx");
   extra();
 }

 void extra()
 {
  System.out.println("Extended code of A");
 }
}//A

class B implements IDemo
{
 //override
 public void ofx()
 {
   System.out.println("B ofx");
 }
}//B

class C implements IDemo
{
 //override
 public void ofx()
 {
   ofx1();
   System.out.println("C ofx");
   ofx2();
 }

 //extended code
 void ofx1()
 {
  System.out.println("--------------------");
 }


 void ofx2()
 {
  System.out.println("********************");
 }
}//C

class Imp
{
 void operation1()
 {
  System.out.println("This is operation 1");
 }

 //polymorphic
 void operation2(IDemo ref)
 {  
   System.out.println("Operation 2 starts");
   ref.ofx();
   System.out.println("Operation 2 ends");
 }

}

class LoseCoupling
{
 public static void main(String args[])
 {
   Imp objImp = new Imp();
   objImp.operation1();
   objImp.operation2(new A());
   objImp.operation2(new B());
   objImp.operation2(new C());
 }
}