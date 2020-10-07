package p2;

import p1.Base;

public class NonDerived1 
{
 Base ref;

 public NonDerived1()
 {
  System.out.println("p2 NonDerived1 NonDerived1()");
  ref = new Base();
  //ref.i++;
  //ref.j++;
  //ref.k++;
  ref.l++;
 }

 public void display()
 {
  System.out.println("p2 NonDerived1 display()");
  System.out.println("private member ref.i is not accessible to non sub class of other package");
  System.out.println("no access specified member ref.j is not accessible to non sub class of other package");
  System.out.println("protected member ref.k is not accessible to non sub class of other package");
  System.out.println("ref.l : " + ref.l);
  System.out.println("===================");
  ref.display();
 }//display

}//NonDerived1

