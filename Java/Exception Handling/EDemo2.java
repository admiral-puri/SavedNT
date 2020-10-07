//Demonstration of throws and nested try blocks
//refer : Exception Handling.txt
//see : NestedTry.png

class EDemo2
{
 int a, b, c;

 void init(String arr[]) throws NumberFormatException, ArrayIndexOutOfBoundsException
 {
  //input 
  a = Integer.parseInt(arr[0]);
  b = Integer.parseInt(arr[1]); 

 }//init


 void process() throws ArithmeticException
 {
  //process
   c = a/b;

 }

 void display()
 {
  //output
   System.out.println(a +" / " + b + " = " + c);
 
 }
 
 public static void main(String args[])
 {
  try
  {
   EDemo2 ed2 = new EDemo2();

   try
   {
    ed2.init(args);
   }
   catch(ArrayIndexOutOfBoundsException ex)
   {
    System.out.println("Insufficent Data");
    System.out.println("Acting on default values 10,2");
    ed2.a = 10;
    ed2.b = 2;
   }
 
   ed2.process();
   ed2.display();
  }
  catch(NumberFormatException ex)
  {
   System.out.println("Invalid Data");
  }
  catch(ArithmeticException ex)
  {
   System.out.println("Infinity");
  }
  finally
  {
   System.out.println("IN FINALLY");
  }
  
  System.out.println("Program Ends");
 }//main

}//EDemo2

