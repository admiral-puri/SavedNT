import java.io.*;

class FRead
{
 public static void main(String args[])
 {
  try
  {
    String fileName = args[0];

    //open this file for reading in text mode
    //If file exists, an input stream would be established
    //Otherwise IOException would be raised.
    FileReader fr = new FileReader(fileName); 

    //read char by char
    int x;
    int cnt = 0;

    while((x = fr.read()) != -1)
    {
      System.out.write(x);
      cnt++;
    }
    System.out.flush();//all buffered data is transferred to the target device 
    
    //close the stream
    fr.close();

    System.out.println("\n FILE READ IN "+ cnt + " cycles");
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage: java FRead <fileName>");
  }
  catch(IOException ex)
  {
   System.out.println("Error: " + ex.getMessage());
  }
 }//main
}//FRead