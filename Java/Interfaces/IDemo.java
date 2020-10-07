//Program to demonstrate interfaces

interface iface1
{
 //public, static and final by default
 double PI = 3.14;

 
 //public and abstract by default
 void afx1();


 //public by default 
 default void dfx()
 {
  System.out.println("A default method of an interface can have a body");
  System.out.println("It may or may not be overridden by the implementing class");
  System.out.println("It is usable through the object of the implementing class object");
 }


 //public by default 
 static void sfx()
 {
  System.out.println("A static method of an interface can have a body");
  System.out.println("It is not overridden by the implementing class");
  System.out.println("It is usable in the implementing class through the interface reference");
 }

}//iface1


interface iface2
{
 void afx2();
}


interface ciface extends iface1, iface2
{
 void afx3();
}


class IDemo implements ciface
{
 public void afx1()
 {
  System.out.println("Definition of afx1() by IDemo");
 }

 public void afx2()
 {
  System.out.println("Definition of afx2() by IDemo");
 }

 public void afx3()
 {
  System.out.println("Definition of afx3() by IDemo");
 }

 public void fx()
 {
  System.out.println("Definition of other methods by IDemo");
 }

 public static void main(String args[])
 {
   //demo of type compatibility
   ciface ref = new IDemo();

   ref.afx1();
   ref.afx2();
   ref.afx3();
   ref.dfx();
   iface1.sfx();
 } 

}//IDemo