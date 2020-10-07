import java.io.File;

class DirectoryParser
{
 static void parse(File f, String indent)
 {
   //fetch the contents of f and load in a String array
   String arr[] = f.list();

   File temp;

   //display the contents (list)
   for(String content : arr)
   {
    System.out.println(indent + content); 
    //in case recursion is reqd
    temp = new File(f, content);//f provides absolute path for the content
    if(temp.isDirectory())
     parse(temp, indent+" ");
   }//for
 }
 public static void main(String args[])
 {
  try
  {
    String dirName = args[0];
    File f = new File(dirName);

    //check whether the directory/file exists or not
    if(f.exists())
    {
     //check whether it is a file or a directory
     if(f.isDirectory())
     {
       parse(f, " ");
     }
     else
      System.out.println(dirName + " is not a directory");
    }
    else
      System.out.println(dirName + " doesnt exists");

  }
  catch(Exception ex)
  {
   System.out.println("Err: " + ex.getMessage());
  }
 } 
}