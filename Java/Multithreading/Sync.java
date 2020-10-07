//Program to demonstrate:
//Sequential Access of a shared resource 
//by multiple threads
//using critical sections of code


//Refer : Multithreading.txt
//See : Sync.png

class Server //extends Object
{
 String data;
 
 synchronized void print(String s)
 {
  int i;
  for(i =0 ; i < 10; i++)
  {
   data = s.toLowerCase();
   System.out.println();
   System.out.print("{");
   System.out.print(data);
   System.out.print("}");
   System.out.println();
  }//for
 }//print

 /*synchronized */void display(String s)
 {
  int i;
  for(i =0 ; i < 10; i++)
  {
   data = s.toUpperCase();
   System.out.println();
   System.out.print("[");
   System.out.print(data);
   System.out.print("]");
   System.out.println();
  }//for
 }//display
 

}//Server


class Client extends Thread
{
 Server svr;
 String msg;

 Client(Server s, String str)
 {
   svr = s;
   msg = str;
   start();//thread activation
 } 

 public void run()
 {
  if(msg.equalsIgnoreCase("Hello")) 
  {
   synchronized(svr)
   {
    svr.display(msg);  
   }
  }
  else
   svr.print(msg);
 }
}

class Sync
{
 public static void main(String args[])
 {
  Server svr = new Server();
  Client c1 = new Client(svr, "hello"); 
  Client c2 = new Client(svr, "shared");  
  Client c3 = new Client(svr, "resource");


 }//main

}//Sync