//Program to demonstrate 2 dimensional (rectangular) array

import java.util.Random;

class TDim
{
 public static void main(String args[])
 {
  //2 dimensional array
  int mat[][] = new int[3][4];

  int i, j;
  Random r = new Random();

  //initialization    
  for(i =0 ; i < mat.length; i++)
   for(j =0 ; j < mat[i].length; j++)
     mat[i][j] = r.nextInt(100); //a random int value in range 0-99



  //exercise : swap mat[1] and mat[2]
  
  //display
  for(int x[] : mat)
  {
   System.out.println();
   for(int y : x)
    System.out.print(y + " ");
  }
  
 }//main
}//TDim