//Program to demonstrate daemon and non daemon threads.
//Refer : Multithreading.txt
//See: DND_Threads.png

class DND_Threads extends Thread
{
 int flag;
 DND_Threads(int x)
 {
  flag = x;
  if(flag == 2)
   setDaemon(true);
  start();//thread activation
 }

 //executes concurrently
 public void run()
 {
   if(flag == 1)
     task1();
   else if(flag == 2)
     task2();
 }

 void task1()
 {
  int i;
  for(i =0 ; i < 1000; i++)
   System.out.print("D1 "); 

  System.out.println("\n Task1 Complete");
 }


 void task2()
 {

  int i;
  for(i =0 ; i < 5000; i++)
   System.out.print("D2 ");

  System.out.println("\n Task2 Complete");

 }

 public static void main(String args[])
 {
  //2 custom threads
  DND_Threads d1 = new DND_Threads(1);
  DND_Threads d2 = new DND_Threads(2);


  int i;
  for(i =0 ; i < 500; i++)
   System.out.print("M ");  

  System.out.println("\n Main Complete");


 }//main

}