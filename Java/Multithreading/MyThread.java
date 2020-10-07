//Program to demonstrate multithreading
//Refer : Multithreading.txt
//See : Single-Multi Threaded Application.png


class MyThread extends Thread
{
 void lower()
 {
  int i;
  for(i =0; i < 26; i++)
    System.out.print("  "+ (char)(97+i)); 	
 }


 void task()
 {
  int i;
  for(i = 0; i< 100; i++)
   lower();  

 }

 //this is the method that:
 //* is executed by custom thread
 //* performs sub tasks concurrently
 //* is life cycle method for the thread
 public void run()
 {
  task();  
 }

 public static void main(String args[])
 {
  //Object of a class that extends Thread
  //is a custom thread.
  //It has the ability to perform sub tasks concurrently.
  MyThread mt = new MyThread();

  //Activate the custom thread
  mt.start();
  
  //activity for main thread 
  int i;
  for(i = 0; i< 1000; i++)
   System.out.print(" M"+i);

 }//main

}//MyThread