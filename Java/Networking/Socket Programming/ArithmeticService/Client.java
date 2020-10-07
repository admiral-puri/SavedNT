import java.io.*;
import java.net.*;

class Client
{
 Socket skt; 

 Client(String ip, int port) throws Exception
 {
  //request a connection
  skt = new Socket(ip, port);
  
 }

 static double getDouble()
 {
  try
  {
   //fflush(stdin);
   System.in.skip(System.in.available());
   
   byte arr[] =new byte[50];
   int n;
   n = System.in.read(arr);

   return Double.parseDouble(new String(arr, 0, n-2));

  }
  catch(Exception ex)
  {
    return 0;
  }
 }

 static int getInt()
 {
   return (int) getDouble();
 }

 void io() throws Exception 
 {
   double d1,d2, d3;
   int ch;
   InputStream in = skt.getInputStream();
   OutputStream out = skt.getOutputStream();

   DataInputStream din = new DataInputStream(in);
   DataOutputStream dout = new DataOutputStream(out);

   System.out.println("Enter a number : ");
   d1 = getDouble();

   System.out.println("Enter another number : ");
   d2 = getDouble();

   System.out.println("1. Addition ");
   System.out.println("2. Subtraction ");
   System.out.println("3. Multiplication ");
   System.out.println("4. Division ");
   System.out.println("Enter choice ");
   ch = getInt();
   System.out.println(ch);
   if(ch < 1 || ch > 4)
    System.out.println("Wrong Choice ");
   else
   {
     dout.writeDouble(d1);
     dout.writeDouble(d2);
     dout.writeInt(ch);
     d3 = din.readDouble();     
     
     System.out.println("Answer : " + d3); 
   }   

 }

 void close() throws Exception
 {
   skt.close();
 }

 public static void main(String args[])
 {
  try
  {
   Client clnt = new Client("127.0.0.1", 9090);
   clnt.io();
   clnt.close();
  }
  catch(Exception ex)
  {
   System.out.println(ex);
  }
 }
}