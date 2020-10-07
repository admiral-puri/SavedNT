//Study of abstract classes and methods
//A demo application
//Refer : Inheritance.txt
//See: AbstractDemo.png
//See: Inheritance.png

import java.util.Random;

abstract class Card
{
 String cardHolder;
 static Random rnd;
 
 static
 {
   rnd= new Random();
 }

 
 Card(String x)
 {
  System.out.println("Card(String)");
  cardHolder = x;
 }

 String getName()
 {
  return cardHolder;
 }

 int getOTP()
 {
   int x= 1000+ rnd.nextInt(9000) ; //1000 to 9999
   return x;
 }

 abstract boolean transaction(int x);
}


class DebitCard extends Card
{


 DebitCard(String nm)
 {
  super(nm);
 }

 boolean transaction(int x)
 {
  if(x <=0)
   return false;

  System.out.println("Check account balance");
  System.out.println("Submitting otp : " + getOTP());

  System.out.println("If balanace is > " + x + " then release the amount otherwise error");
  return true;

 }

}

class CreditCard extends Card
{
 CreditCard(String nm)
 {
  super(nm);
 }
 
 boolean transaction(int x)
 {
  if(x <=0)
   return false;

  System.out.println("Check credit limit");
  System.out.println("Submitting otp : " + getOTP());
  System.out.println("If limit is > " + x + " then release the amount otherwise error");
  System.out.println("If its Saturday and " + x + " > 500 and party is irctc then cash back = 100");
  
  return true;

 }

}


class IRCTC
{
 void bookTicket(String from , String to, Card c)
 {
  System.out.println(c.getName() + " Going from " + from + " to " + to);
  System.out.println("Tickets Available");
  System.out.println("Performing transaction ");
  int amt = 1234;//say
  if(c.transaction(amt))
   System.out.println("Tickets Booked");
  else
   System.out.println("Tickets Not Booked due to transaction failure");
  
 }
}


class AbstractDemo
{
 public static void main(String args[])
 {
  IRCTC obj = new IRCTC();
  System.out.println("=================");
  obj.bookTicket("Pune", "Mumbai", new DebitCard("Vishal"));
  System.out.println("=================");
  obj.bookTicket("Pune", "Delhi", new CreditCard("Avinash"));
  System.out.println("=================");

 }
}