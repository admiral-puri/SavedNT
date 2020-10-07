//Program to demonstrate 2 task performed
//concurrently by 2 custom thread

class ThreeThreads extends Thread
{
 int flag;

 ThreeThreads(int x)
 {
  flag = x;
  start(); //activate the thread
 }

 void lower()
 {
  int i;
  for(i =0 ; i < 26; i++)
   System.out.print(" " + (char)(97+i));
 }


 void upper()
 {
  int i;
  for(i =0 ; i < 26; i++)
   System.out.print(" " + (char)(65+i));
 }

 void task1()
 {
  int i;
  for(i =0; i < 100; i++)
   lower();

 }

 void task2()
 {
  int i;
  for(i =0; i < 100; i++)
   upper();

 }

 public void run()
 {
  if(flag == 1)
   task1();
  else if(flag ==2)
   task2();
 }

 public static void main(String args[])
 {
  ThreeThreads t1 = new ThreeThreads(1);
  ThreeThreads t2 = new ThreeThreads(2);

  int i;
  for(i =0; i < 1000; i++)
   System.out.print(" M"+i);

 }//main

}//ThreeThreads