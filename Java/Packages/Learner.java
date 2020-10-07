//get the access of all public classes and interfaces of the package study
import study.*;

class Learner
{
 public static void main(String args[])
 {
  C objC = new C();
  CPP objCPP = new CPP();
  HTML objHTML = new HTML();

  System.out.println("--------");
  objC.aboutC();
  System.out.println("--------");
  objCPP.aboutCPP();
  System.out.println("--------");
  objHTML.aboutHTML();
  System.out.println("--------");
 }
}