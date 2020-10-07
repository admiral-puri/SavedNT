/*
Program to study : Variable arity methods

Arity of a method is the number of arguments it takes.
Ideally methods have a fixed arity.
But Java allows methods to have variable arity.
i.e. In Java methods, that can take variable number of arguments, can be defined.

Syntax:
 returnType fnName(DataType ... nm)
 { process }

A method as above can receive and process
variable arguments of specific (same) Datatype.

For a method to have variable arguments 
of any datatype set the formal parameter
datatype to Object.

Know that Object is a class (datatype) that 
can refer to any datatype in Java.
But when Object is used to refer to any
particular type then the processing possible
on that value gets restricted.


FYI
 If a method is defined to have variable arity then:
  * System collects the actual parameters and forms an array.
  * Array is sent as a parameter to the function.
  * The variable arity formal parameter is internally an array reference.
  * The variable arity formal parameter is processed like an array inside the method.

*/


class VArity
{

 static void add(double ... params)
 {
   double tot = 0;
   for(double x : params) 
    tot += x;
 
   System.out.println("Addition : " + tot);
 }
 
 static void fx(Object ... params)  
 {
  //process
  int i;

  System.out.println("=================");

  for(i =0; i < params.length; i++)
    System.out.print(params[i] + " ");

  System.out.println();
  System.out.println("=================");

 }

 static void max(int ... vargs)
 {
   int max;
   int i;
   if(vargs.length == 0)
    return;

   max = vargs[0];   
   for(i = 0; i < vargs.length; i++)
   {
    System.out.println(" * " + vargs[i]);
    if(vargs[i] > max)
      max = vargs[i];  
   }

   System.out.println("max : " + max); 
 }

 public static void main(String args[])
 {
   fx("hello");
   fx("hello", 1);
   fx("hello", "all");
   fx("hello", 1, 2, 3);
   fx();//Java allows an array to have min size : 0

   add();//Java allows an array to have min size : 0 
   add(1.5);
   add(1, 2.0);
   add(1.1, 2, 3.5);
   add(1, 2.2, 3.1, 4.05);

   int a, b, c, d, e, f;
   
   a = 100;
   b = 10; 
   c = 50;
   d = 90;
   e = 55;
   f = 200;

   max(a,b,c);
   max(a,b,e,f);
   max(a,b,c,d,e,f);
   max(c,e);
   
 }
}