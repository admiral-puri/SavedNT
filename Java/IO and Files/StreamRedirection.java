/*
Stream Redirection allows a Java application
to change the source of standard input stream 
(System.in) and the target of standard output 
streams (System.out and System.err).

Hence the application can fetch data from or 
output data to customized sources / targets.

To redirect the standard stream the methods are:

System.setIn( object of InputStream refering to custom source)
System.setOut( object of PrintStream refering to custom target)
System.setErr( object of PrintStream refering to custom target)

*/

import java.io.*;

class StreamRedirection
{
 public static void main(String args[])
 {
  try
  {
   System.out.println("Stream Redirection Demo");
   System.out.println("System.out outputs to Monitor");
   System.out.println("... No Longer");
   //backup
   PrintStream temp = System.out;

   PrintStream ps = new PrintStream("d:\\out.txt");

   //redirect to a file
   System.setOut(ps);

   System.out.println("I am happy to write in a file");
   System.out.println("Smile");
   System.out.println("Smile");
   System.out.println("Smile");
   System.out.println("... but I miss the monitor");
   System.out.println("I am going back bye bye");

   //redirect back to monitor
   System.setOut(temp);

   ps.close();

   System.out.println("Hey Monitor, Good Evening");   
  }
  catch(IOException ex)
  {
   System.out.println(ex);
  }
 }//main
}//StreamRedirection