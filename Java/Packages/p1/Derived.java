package p1;

public class Derived extends Base
{

 public Derived()
 {
  System.out.println("p1 Derived Derived()");
  //i++;
  j++;
  k++;
  l++;
 }

 public void display()
 {
  System.out.println("p1 Derived display()");
  System.out.println("private member i is not accessible to sub class");
  System.out.println("j : " + j);
  System.out.println("k : " + k);
  System.out.println("l : " + l);
  System.out.println("===================");
  super.display();
 }//display

}//Derived

