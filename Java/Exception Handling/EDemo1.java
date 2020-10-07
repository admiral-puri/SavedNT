//Demonstration of try, catch and finally
//refer : Exception Handling.txt
//see : ExceptionHandling.png

class EDemo1
{
 public static void main(String args[])
 {
  try
  {
   int a, b, c;
   //input 
   a = Integer.parseInt(args[0]);
   b = Integer.parseInt(args[1]); 

   //process
   c = a/b;

   //output
   System.out.println(a +" / " + b + " = " + c);
   
  }
  catch(NumberFormatException ex)
  {
   System.out.println("Invalid Data");
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Insufficent Data");
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
}//EDemo1


/*
class Integer is defined in the package 
java.lang, which is by default imported 
for every program.
Hence the class Integer can be directly 
used.

It defines a public and static method
parseInt() that accepts a String as a 
parameter, converts the String into an
int and returns (the int).

Example:
 x = Integer.parseInt("12");
 x is assigned 12


If the parameter String is not convertible 
into an int then the method raises 
NumberFormatException.

Example:
 x = Integer.parseInt("12a");
 RAISES NumberFormatException

If not handled the program terminates abnormally.


*/