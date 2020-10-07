import java.io.*;

class FCopy
{
 public static void main(String args[])
 {
  try
  {
    String fn1 = args[0];//src file
    String fn2 = args[1];//trgt file

    //open fn1 for reading in binary mode, file must exist or an execption would raise.
    FileInputStream fin = new FileInputStream(fn1);
	    
    //open fn3 for writing in binary mode, file will be created or overwritten.
    FileOutputStream fout = new FileOutputStream(fn2);

    //copy
    int n, cnt = 0;
    byte arr[] = new byte[1024];

    //while((n = fin.read())!= -1)
    //{
    //  fout.write(n);
    //  cnt++;
    //}

    while((n = fin.read(arr))!= -1)
    {
      fout.write(arr, 0, n);
      cnt++;
    }

    fout.flush();

    //close the streams
    fout.close();
    fin.close();	
  
    System.out.printf("File Copied in %d cycles", cnt);
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage: java FCopy <Src> <Trgt>");
  }
  catch(IOException ex)
  {
   System.out.println("Err: " + ex.getMessage());
  }

 }//main
}//FCopy