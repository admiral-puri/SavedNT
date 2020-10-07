/*
 Singleton class is a class that
 can be instantiated once. 
 
 To make a class singleton:
  1) Hide its constructors
  2) Provide a factory method that creates only one object and returns the same everytime.

*/


class Singleton
{
  //non static data members
  int x, y; 

  //static data member  
  //(It gets allocated once and on first use of the class) 
  private static Singleton ref;


  //static initializer block
  //(It auto runs on first use of the class)     
  static
  {
    ref = null;
  }

  private Singleton() 
  {
   System.out.println("Singleton()");
   x = 10;
   y = 20;
  }
 
  void increment()
  {
   x++;
   y++; 
  } 

  void display()
  {
   System.out.println(x + "  " + y);
  }

  //factory method
  //accessible without object

  static Singleton getInstance()
  {
    System.out.println("In getInstance");
    if(ref == null)
      ref = new Singleton();

    return ref;
  }
  
}//Singleton


class UseSingleton
{
 public static void main(String args[])
 {
   //Singleton s1 = new Singleton();
   //Singleton s2 = new Singleton();

   Singleton s1, s2;

   s1 = Singleton.getInstance();
   s2 = Singleton.getInstance();


   s1.increment();
   s2.display();	
  
   if(s1 == s2)
    System.out.println("Two references refer to the same object");
   else
    System.out.println("Singleton failed");
 } 
}