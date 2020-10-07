import java.io.File;
import java.awt.*;
class RootDrives
{
 public static void main(String args[])
 {
  File allDrives[] = File.listRoots();

  for(File current: allDrives)
  {
   System.out.println(current.getAbsolutePath());
   System.out.println("  -> Free Space :" + current.getFreeSpace());
   System.out.println("  -> Usable Space :" + current.getUsableSpace());
   System.out.println("  -> Total Space :" + current.getTotalSpace());

  }//for

  //Beep
  Toolkit.getDefaultToolkit().beep();  

 }//main
}//RootDrives