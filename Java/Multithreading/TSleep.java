//Program to demonstrate Thread Sleep
//Refer : Multithreading.txt

class TSleep extends Thread
{
 TSleep()
 {
  start();
 }

 public void run()
 {
  int i;
  for( i = 0; i < 10; i++)
  {
   System.out.println("* "+  System.currentTimeMillis());

   try 
   {   
    Thread.sleep(1000);//1 second delay
   }
   catch(InterruptedException ex)
   {}

  } 

 }
 public static void main(String args[])
 {
  TSleep ts =  new TSleep();

 } 

}