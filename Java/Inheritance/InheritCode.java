//Program to study inheritance of code

class A
{
 //methods
 void fx1()
 {
  System.out.println("A fx1()");
 }
 
 void fx2()
 {
  System.out.println("A fx2()");
 }
}//A

class B extends A	
{
  //redefine and inherited non static method (maintain signature)
  //i.e. override
  void fx2()
  {
   System.out.println("B fx2()");
  }

  void fx3()
  {
   System.out.println("B fx3()");
  }

}//B


class InheritCode
{
 public static void main(String args[])
 {
   //object of derived class

   B objB = new B();
   objB.fx1();//inherited code
   objB.fx2();//overridden code
   objB.fx3();//extended code
  
 }
}//InheritCode

