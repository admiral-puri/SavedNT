import java.io.File;

class DeleteExtensionwise
{
 static void parse(File f, String ext)
 {
   //fetch the contents of f and load in a String array
   String arr[] = f.list();

   File temp;

   //display the contents (list)
   for(String content : arr)
   {
    temp = new File(f, content);//f provides absolute path for the content
    if(temp.isDirectory())
     parse(temp, ext);
    else if(temp.isFile())
     if(content.toLowerCase().endsWith(ext))
       temp.delete();//remove the file
   }//for
 }
 public static void main(String args[])
 {
  try
  {
    String dirName = args[0];
    String ext = args[1].toLowerCase();
    File f = new File(dirName);


    //check whether the directory/file exists or not
    if(f.exists())
    {
     //check whether it is a file or a directory
     if(f.isDirectory())
     {
       parse(f, ext);
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