//Program to demonstrate 2 dimensional (ragged) array

import java.util.Random;

class Ragged
{
 public static void main(String args[])
 {
  //2 dimensional ragged array
  int mat[][] = new int[3][];

  //create cols per row
  mat[0] = new int[4];
  mat[1] = new int[2];
  mat[2] = new int[3];

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
}//Ragged