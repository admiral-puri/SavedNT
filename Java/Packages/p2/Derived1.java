package p2;
import p1.Base;

public class Derived1 extends Base
{

 public Derived1()
 {
  System.out.println("p2 Derived1 Derived1()");
  //i++;
  //j++;
  k++;
  l++;
 }

 public void display()
 {
  System.out.println("p2 Derived1 display()");
  System.out.println("private member i is not accessible to sub class of other package");
  System.out.println("no access specified member j is not accessible to sub class of other package");
  System.out.println("k : " + k);
  System.out.println("l : " + l);
  System.out.println("===================");
  super.display();
 }//display

}//Derived1

