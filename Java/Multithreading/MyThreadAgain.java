/*
package java.lang;

public class Thread implements Runnable
{
 Runnable ref;
 ...

 Thread()
 {
   ref = this;   
 }

 Thread(Runnable r)
 {
  ref =r ;
  ...
 }

 public void start()
 {
  ... thread activation code
  ref.run();
  ... dead state
 }

 //interface method 
 public void run()
 {
   //empty body
 }
}

*/

class MyThreadAgain implements Runnable
{
  Thread t;
  MyThreadAgain()
  {
    t = new Thread(this);
    t.start();
  }

  public void run()
  {
   int i;
   for(i =0 ; i < 1000; i++)
    System.out.print(" T ");
  }

  public static void main(String args[])
  {
    MyThreadAgain mt = new MyThreadAgain();

    int i;
    for(i =0 ; i < 1000; i++)
     System.out.print(" M ");

  }
}