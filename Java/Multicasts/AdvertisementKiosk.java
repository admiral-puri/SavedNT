import java.net.*;

class AdvertisementKiosk
{
 MulticastSocket mSkt;

 AdvertisementKiosk(String ip, int port) throws Exception
 {
   //Open a multicastsocket on this machine
   //bind it to the specific port
   mSkt = new MulticastSocket(port);

   //Register with the virtual host for receiption of multcasts
   InetAddress vhIp = InetAddress.getByName(ip);
   mSkt.joinGroup(vhIp);
 }

 void receive()
 {
  try
  {
    boolean flag  = true;
    String str;
    DatagramPacket dp;
    byte buff[] = new byte[1024];

    while(flag)
    {
     dp = new DatagramPacket(buff, buff.length);
     mSkt.receive(dp);//blocks
     str = new String(dp.getData(), 0, dp.getLength());
     if(str.equalsIgnoreCase("Done"))
       flag= false;
     else
       System.out.println(str);
    }//while
    mSkt.close();
  }
  catch(Exception ex) 
  {
   System.out.println(ex);
  }
 }

 public static void main(String args[])
 {
  try
  {
   AdvertisementKiosk ak = new AdvertisementKiosk("224.5.6.7", 4567);
   ak.receive();
  }
  catch(Exception ex)
  {
   System.out.println(ex);
  }
 }//main
}