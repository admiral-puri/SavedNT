//Study of :
//* Life of Object
//* Garbage Collection Mechanism
//* finalize method (Destructor like method in Java)
 
//See : GCDemo.png
//Refer : Garbage Collection.txt

class MyObject //extends Object
{
  int arr[];
  String label;

  MyObject(int size, String s)
  {
    arr = new int[size];
    label = s;
  }
 
  void display()
  {
    System.out.println("For object " + label + " Array size : " + arr.length);
     
  }

  //override
  protected void finalize()
  {
   System.out.println("Object " + label + " about to deallocate");
  }
}

class GCDemo //extends Object
{
 public static void main(String args[])
 {
  MyObject o1 = new MyObject(1000, "A");
  MyObject o2 = new MyObject(100, "B");
  MyObject o3 = new MyObject(10000, "C");
  MyObject ref = o2;


  System.out.println("----- some use ----");
  o1.display();
  o2.display();
  o3.display();
  System.out.println("-------------------");

  o1 = null; //drop the reference
  o2 = null; //drop the reference
  o3 = null; //drop the reference


  System.gc(); //invoke garbage collection

  //delay
  try
  {
   Thread.sleep(5000);
  }
  catch(InterruptedException ex)
  {}

  System.out.println("Main over");
 }//main
}