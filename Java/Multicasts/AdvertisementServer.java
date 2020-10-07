import java.net.*;
import java.util.*;

class AdvertisementServer implements Runnable
{
 MulticastSocket mSkt;

 AdvertisementServer() throws Exception
 {
   //open a multicast socket on this machine
   //it would bind to any available port.
   mSkt = new MulticastSocket();

   Thread t = new Thread(this);
   t.start();
 }

 public void run()
 {
  try
  {
   LinkedList<String> listAdvt= getAllAdvertisements();
   DatagramPacket dp;
 
   InetAddress vhIP = InetAddress.getByName("224.5.6.7");//class D IP
   int vhPort = 4567;

   for(String la : listAdvt)//for each loop
   {
    System.out.println("Sending : " + la);
    dp = new DatagramPacket(la.getBytes(), la.length(), vhIP, vhPort); 
    mSkt.send(dp);
    try
    {
      Thread.sleep(1000);
    }
    catch(Exception ex) {}
   } 
   mSkt.close();
  }
  catch(Exception ex)
  {
   System.out.println(ex);
  }
 }//run

 LinkedList<String> getAllAdvertisements()
 {
  LinkedList<String> ls = new LinkedList<String>();
  ls.add("Tayari Jeet Ki - AdvancedJava");
  ls.add("Zindagi Ke Saath Bhi, Zindagi Ke Baad Bhi - AdvancedJava");
  ls.add("Taller Stronger Sharper- AdvancedJava");
  ls.add("Learn And Implement- AdvancedJava");
  ls.add("DONE");
  return ls;
 }

 public static void main(String args[])
 {
  try
  {
   new AdvertisementServer();
  }
  catch(Exception ex)
  {
   System.out.println(ex);
  }
 }//main
}//AdvertisementServer 