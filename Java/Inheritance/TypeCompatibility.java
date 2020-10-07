//Program to study : Type Compatibility (due to inheritance)

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
   System.out.println("B fx2() starts");
   fx3();//extended code
   System.out.println("B fx2() starts");

  }

  void fx3()
  {
   System.out.println("B fx3()");
  }

}//B


class X
{
 //type compatibilty:
 //reference of super class as formal parameter
 //can be used to refer to objects of its type 
 //of sub types
 void fx(A ref)
 {
   System.out.println("------fx starts------");
   ref.fx1(); 
   ref.fx2(); //dynamic binding 
   System.out.println("------fx ends--------");
 }

}

class TypeCompatibility
{
 public static void main(String args[])
 {
   A objA = new A();
   B objB = new B();

   X objX = new X();
   objX.fx(objA);//obj of super class as actual parameter
   objX.fx(objB);//obj of sub class as actual parameter
     
 }
}//InheritCode

