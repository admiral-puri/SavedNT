class Student
{
 String name;
 int rno;

 Student()
 {
   System.out.println("Student()");
   name = "Vikas";
   rno = 10;
 }

 Student(String q, int w)
 {
   System.out.println("Student(String,int)");
   name = q;
   rno = w;
 }

 void display()
 {
  System.out.println(rno + "," + name);
 }
}//Student

class CArray
{
 public static void main(String args[])
 {
  //syntax
  //datatype arr[] = new datatype[size];
  //int arr[] = new int[3];
  Student arr[] = new Student[3];
  //array elements are references of type Student
  //they are null by default
  //array is unusable
  //create objects and associate with array elements
  arr[0] = new Student("Manoj", 11);
  arr[1] = new Student();
  arr[2] = new Student("Anil", 1);


  //now use the array
  int i;
  for(i=0; i < arr.length; i++)
   arr[i].display();

  //bubble sort (rno wise) code here

  System.out.println("~~~~~~~~~~~~~~~");    
  for(Student x : arr)
   x.display();

 }//main
}//CArray
