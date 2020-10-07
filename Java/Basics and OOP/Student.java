//Study of arrays of Secondary Types
//See : Array_SecondaryType.png
//Refer : Note Below

class Student
{
 //data memebers
 int rno;
 String name;


 //Constructor
 Student()
 {
  System.out.println("Stdent()");
  rno = 60;
  name = "XYZ";

 }

 Student(int r, String n)
 {
  System.out.println("Stdent(int, String)");
  rno = r;
  name = n;

 }

 void display()
 {
  System.out.println(name + "  " + rno);
 }

 public static void main(String args[])
 {
  //Student array (reference array)

  Student arr[] = new Student[3];
  //initialize the elements with objects
  //so that the array can be used

  arr[0] = new Student(1, "Vikas");
  arr[1] = new Student();
  arr[2] = new Student(12, "Anil");


  //use
  //int i;
  //for(i =0 ; i < arr.length; i++)
  // arr[i].display();

  for(Student s : arr)  
   s.display();  
 

 }//main


}//Student


/*
An array is a collection of homogenous data.

Java allows declaration of arrays of primary 
and secondary types.

Syntax:
 datatype arr[] = new datatype[size]

Example
 int arr[] = new int[3];
 Student arr[] = new Student[3];

FYI:
 When an array is of primary type then the 
 array elements are values of that type.

 When an array is of secondary type then
 the array elements are references (and not
 objects) of secondary types.

 It is required to explicitly create objects
 of the secondary type and associate them with
 the array elements (that are references).

FYI:
 If objects of a class are grouped in an array, 
 then group processing and application of 
 algorithms becomes possible.

*/