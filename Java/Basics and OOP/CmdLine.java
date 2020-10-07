//Study of command line arguments.
//Refer : Command Line Arguments.png
/*
Command Line Arguments

Command Line arguments are the parameters
passed from the DOS/LINUX shell to the main
method of the Java program.

System fetches the command line arguments,
creates a String array of the same and passes
the array reference to the main method.

The main method declares a String array reference 
as a formal parameter to receive the command line 
argument array.

Program code can access the command line arguments
through the array reference.
*/


class CmdLine
{
 public static void main(String args[])
 {
  //use the command line arguments
  
  System.out.println("Number of command line arguments are : " + args.length);
  for(String x : args)
   System.out.println(x);

  //int i;
  //for(i =0 ; i < args.length; i++)
  // System.out.println(args[i]);

 }//main

}//CmdLine

//FYI : When user doesnt pass any command line arguments
//still system creates an array of size zero and passes
//to the main method of the java application

