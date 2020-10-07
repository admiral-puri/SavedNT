import java.net.*;
import java.io.*;

class Server implements Runnable
{
 ServerSocket port;
 boolean flag;
 Thread t;

 Server(int portNo) throws Exception
 {
  //open a port
  port = new ServerSocket(portNo);

  //create a thread for accepting client connections
  flag = true;
  t = new Thread(this);
  t.start(); //activate the thread
 }

 public void run()
 {
   while(flag)
   {
    acceptConnection();
   }

   //flag == false
   try
   {
    //server down
    port.close();
   }
   catch(Exception ex)
   {
    System.out.println(ex);
   }
 }//run

 void acceptConnection()
 {
  try
  {
   //port.accept() will:
   //1) Block the current thread until connection request is received.
   //2) On request, form the connection.
   //3) Return a Socket object that refers to the client connection
   System.out.println("Waiting for client connection ...");
   Socket s = port.accept();
   System.out.println("... got a client connection, processing it now!!!");
   //create a thread for client i/o  
   new ClientProcessor(s);
  }
  catch(Exception ex)
  {
   System.out.println(ex);
  }

 }//acceptConnection  


 public static void main(String args[])
 {
  try
  {
   Server svr = new Server(9090);
   //...
  }
  catch(Exception ex)
  {
   System.out.println(ex);
  }
 }
}//Server

//Processor
class ClientProcessor extends Thread
{
  Socket skt;

  ClientProcessor(Socket s)
  {
   skt = s;
   start(); //activate this thread
  }

  public void run()
  {
   try
   {
    //fetch the socket streams
    InputStream in = skt.getInputStream();
    OutputStream out = skt.getOutputStream();

    //in and out allows i/o of bytes only
    //to work with Java datatype wrap them
    //using DataInputStream and DataOutputStream
    //respectively
  
    DataInputStream din = new DataInputStream(in);
    DataOutputStream dout = new DataOutputStream(out);

    double a, b, c;
    int ch;
   
    a = din.readDouble();
    b = din.readDouble();
    ch = din.readInt();
    switch(ch)
    {
      case 1: //addition
       c = ArithmeticService.add(a,b);
       break;
      case 2: //subtraction
       c = ArithmeticService.subtract(a,b);
       break;
      case 3: //multiplication
       c = ArithmeticService.multiply(a,b);
       break;
      case 4: //division
       c = ArithmeticService.divide(a,b);
       break; 
      default:
       c = 0;
    }//switch 

    dout.writeDouble(c);
 
    dout.close();
    din.close();     
    skt.close();
   }
   catch(Exception ex)
   {
    System.out.println(ex );
   }
  }//run
}

//Service
class ArithmeticService
{
 static double add(double n1, double n2)
 {
  double ans;
  ans = n1 + n2;
  return ans;
 }

 static double subtract(double n1, double n2)
 {
  double ans;
  ans = n1 - n2;
  return ans;
 }

 static double multiply(double n1, double n2)
 {
  double ans;
  ans = n1 * n2;
  return ans;
 }

 static double divide(double n1, double n2)
 {
  double ans;
  ans = n1 / n2;
  return ans;
 }
  
}//ArithmeticService