//Study of Single Dimensional Array
//Refer : SDim.png

import java.util.Random;

class SDim
{
 public static void main(String args[]) 
 {
  //C: int arr[4];
  //Java:
  int arr[] = new int[4];
  int i;


  //content check
  for(i=0; i<arr.length; i++)  
    System.out.print(arr[i] + " ");
  System.out.println(); 


  //fill the array with random numbers
  Random r = new Random();
  for(i =0; i < arr.length; i++)
   arr[i] = r.nextInt(100);//generate a random int in range 0-99   

  //content check

  //for(i=0; i<arr.length; i++)  
  //  System.out.print(arr[i] + " ");
  //System.out.println(); 

  for(int x : arr) //foreach loop   
    System.out.print(x + " ");
  System.out.println(); 


 }//main
}//SDim