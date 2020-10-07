/*
Anonymous classes

Java allows creation and use of anonymous classes 
that are no named inner classes for which only one 
object is created.

The anonymous inner classes are ideally used for 
having an object with certain “extras" (attributes 
and operations) over an existing classes or interfaces, 
without formally inheriting or implementing them.
*/

interface I
{
  void ifx();
}

class C
{
  void cfx()
  {
    System.out.println("C : cfx()");
  }
}


class Regular extends C implements I
{
  void regularfx()
  {
    System.out.println("Regular : regularfx()");
  }

  //compulsory override
  public void ifx()
  {
    System.out.println("Regular : ifx()");
  }

  //optional override
  public void cfx()
  {
    System.out.println("Regular : cfx()");
  }
}


class AnonymousClassStudy
{
 
 public static void main(String args[])
 {
   Regular r = new Regular();
   r.regularfx();
   r.ifx();
   r.cfx();

   //Here are anonymous classes to inherit C and override cfx
   new C(){
     void more()
     {
       System.out.println("Anonymous: C_more()");
     }
    
     public void cfx()
     {
       System.out.println("Anonymous: cfx()");
       more();
     }
   }.cfx();

   //Here are anonymous classes to implement I and override ifx
   new I()
   {
     void more()
     {
       System.out.println("Anonymous: I_more()");
     }
    
     public void ifx()
     {
       System.out.println("Anonymous: ifx()");
       more();
     }
   }.ifx();
  
 }//main
}