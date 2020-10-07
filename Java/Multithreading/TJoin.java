  //Thread Join
//Refer: Multithreading.txt
//See: TJoin.png

class TJoin implements Runnable
{
 Thread t1; 
 Thread t2;

 TJoin()
 {
   t1= new Thread(this);
   t2= new Thread(this);
   t1.start();
   t2.start();
 }

 public void run()
 {
  if(Thread.currentThread().equals(t1))
   fx1();
  else if(Thread.currentThread().equals(t2))
   fx2();
 }

 void fx1()
 {
  int i;
  for(i =0 ; i < 1000; i++)
  {
   System.out.print("1");
   if(i == 200)
   {
    //current thread suspends execution until other thread completes
    try
    {
     System.out.println("\n Before Join");
     t2.join();
     System.out.println("\n After Join");
    }
    catch(InterruptedException ex)
    {}
   }
  }//for
  System.out.println("fx1 ends");
 }


 void fx2()
 {
  int i;
  for(i =0 ; i < 1000; i++)
   System.out.print("2");


  System.out.println("fx2 ends");
 }

 public static void main(String args[])
 {
  TJoin tj = new TJoin();
  
 }
}//TJoin