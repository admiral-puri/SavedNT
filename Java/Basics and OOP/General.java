//A primary java program

class General
{
 //public: no restriction on access
 //static : accessible without object
 //void : no return value
 //main : preset name for program entry point
 //String args[] : command line argument array 

 public static void main(String args[])
 {
  int i;//local variable
  for(i =0 ; i < 10; i++)//loop
  {
    if(i%2 == 0)
     System.out.println("Hello Student"); //printf("Hello Student\n");
    else
     System.err.println("Hello Java");//fprintf(stderr, "Hello Java\n");
  }//for

 }//main

}//General