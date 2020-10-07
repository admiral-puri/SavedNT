//Program to study
//static data members
//static initializer blocks
//static methods

//refer : Class Initialization.png

class Marketing
{

 //A static initializer block is a block of code that belongs to the class and is captioned as static.
 //It auto executes on first use of the class.
 //It is used to initialize the static data member of the class
 //or to perform a task that is to be done on first use of the class.
 static
 {
  System.out.println("In SIB of Marketing");
 }

 //This method is static
 //static makes the method accessible without any caller object.
 //It doesnt has "this" pointer.
 //It cannot access non static members of the class
 //It can direct access the static members of the class
 //It is invoked using the class reference.
 //The static methods are "stateless"
 static void schemes()
 {
  System.out.println("Offer 1 ....");
  System.out.println("Offer 2 ....");
  System.out.println("Offer 3 ....");
 }
}

class FixedDeposit
{
 int accountNumber;
 double principal;
 double term;
 String accountHolder;

 //This is a static data member.
 //It is allocated once for the class.
 //It is "not" a data member for objects of the class.
 //Its life is equal to the life of the class.
 //It is accessible through class reference.
 static double roi;

 static
 {
  System.out.println("In SIB of Fixed Deposit");
  roi = 4.5;
 }

 FixedDeposit(int an, double p, double t, String ah)
 {
  System.out.println("FixedDeposit(parameterized)");
  accountNumber = an;
  term = t;
  principal = p;
  accountHolder = ah;
 }

 static double getInterest(FixedDeposit obj)
 {
  double interest;
  interest = obj.principal * obj.term * roi / 100;
  return interest;
 }

 void display()
 {
  System.out.println("Account Number : " + accountNumber);//this.accountNumber
  System.out.println("Account Holder : " + accountHolder);//this.accountHolder
  System.out.println("Principal Amount : " + principal);//this.principal
  System.out.println("Term : " + term);//this.term
  System.out.println("ROI : " + roi);//FixedDeposit.roi
  double interest = getInterest(this);
  System.out.println("Interest : " + interest);
  
 }
}

class StaticDemo
{

 static
 {
  System.out.println("In SIB of StaticDemo");
 }

 public static void main(String args[])//prg starts here
 {
   System.out.println("in main");
   Marketing.schemes();
   FixedDeposit fd1 = new FixedDeposit(1, 1000, 3, "Ajay");
   FixedDeposit fd2 = new FixedDeposit(2, 1005, 2, "Anil");
 
   fd1.display();
   fd2.display();

 }
}