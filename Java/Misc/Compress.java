import java.util.zip.*;
import java.io.*;

class Compress
{

 static boolean compressIt(String folder, String target)
 {
  try
  {
   File f, temp;
   f = new File(folder);

   //target file:
   FileOutputStream fout = new FileOutputStream(target);
   //Compressor
   ZipOutputStream zout = new ZipOutputStream(fout);
   ZipEntry ze;
   FileInputStream fin;
   byte arr[] = new byte[2048];
   int n;

   String contents[] = f.list();
   for(String s : contents)
   {
     temp = new File(f, s);
     if(temp.isFile())
     {
       //make zip entry
       ze = new ZipEntry(s);
       //Associate it with the compressor
       zout.putNextEntry(ze);

       fin = new FileInputStream(temp);
       //read the file
       while((n = fin.read(arr)) != -1)
        //write into the compressor
        zout.write(arr,0,n);

       //close the zip entry
       zout.closeEntry();
       fin.close();       
     }//if
   }//for

   //Close
   zout.close();
   fout.close();
   return true;
  }
  catch(Exception ex)
  {
   return false;
  }
 }
 public static void main(String args[])
 {
  try
  {
    String folder = args[0];
    String target = args[1];
    File f = new File(folder);
    if(!f.exists())
    {
      System.out.println(folder + " doesnt exists");
      System.exit(0);  
    }
    if(!f.isDirectory())
    {
      System.out.println(folder + " is not a directory");
      System.exit(0);  
    }
    //folder exists and is a directory	
    if(compressIt(folder, target))
      System.out.println("SUCCESS");
    else
      System.out.println("FAILURE");
    
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
    System.out.println("Usage: Compress <DirectoryToCompress> <Target>");
  }
 }
}

