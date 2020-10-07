import java.io.*;

//Reading and Writing Data of Primitive Types
class RAFDemo1
{
 public static void main(String args[])
 {
  try
  {
    int a1 = 2344;
    boolean b1 = true;
    double c1 = 34.567;
    String d1 = "this is a sample sentence";
   
    int a2;
    boolean b2;
    double c2;
    String d2 = "to do";

    String fileName = "d:\\data.txt";
    String mode = "rw";
    //open the file in given mode
    RandomAccessFile raf = new RandomAccessFile(fileName, mode);

    //write the primitive values
    raf.writeInt(a1);
    raf.writeBoolean(b1);
    raf.writeDouble(c1);
    raf.writeUTF(d1);
    
    //rewind the file pointer for reading back
    raf.seek(0);//wrt bof
 
    a2 = raf.readInt();
    b2 = raf.readBoolean();
    c2 = raf.readDouble();
    d2 = raf.readUTF();
  
    System.out.println(a1 + "  " + a2);     
    System.out.println(b1 + "  " + b2);     
    System.out.println(c1 + "  " + c2);     
    System.out.println(d1 + "  " + d2);     


    //close the file
    raf.close();   
  }
  catch(Exception ex)
  {
    System.out.println(ex);
  }
 }//main
}//RAFDemo1