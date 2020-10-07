//Program to study : Object Creation Process
//Refer: Note Below
//See : Person.png


class Person
{
 //attributes(data members) 
 String name;
 int age;


 //non static initializer block
 {
   System.out.println("NSIB");
   age = 0;
   name = "baby";
 } 

 //constructor
 Person() //takes no parameters, is termed as "default constructor"
 {
   System.out.println("Person()");
   age = 10; //assigns a preset value
   name = "Vikas"; //assigns a preset value
 }

 Person(String nm, int ag)//parameterized constructor
 {
   System.out.println("Person(String, int)");
   age = ag; //assigns a parameter value
   name = nm; //assigns a parameter value

 }

 //operations (methods)
 void Person()
 {
  System.out.println("Java allows methods to have same name as of the class");
  System.out.println("Their return type plays a role in differntiation between a constructor and a method");
 }

 void display()
 {
   System.out.println("Name : " + name);
   System.out.println("Age : " + age);
 }

 //program begins here
 public static void main(String args[])
 {
   System.out.println("=================");
   Person p = new Person(); //Object of class Person
   System.out.println("=================");
   Person p1 = new Person("Manoj", 5); //Object of class Person
   System.out.println("=================");


   p.display();
   p1.display();
   p.Person();
 }
}//Person


/*
Object
---------
* Object is an instance of a class.
* It can store and process data. 
* In memory it is a composite block, made up of the non-static data members of the class.
* Its processing ability is defined by the non-static methods of the class.


Object Creation Process
-----------------------------
Object creation is a 3 step process, in Java.
* Memory allocation
* Execution of non static initializer block
* Execution of constructor


Memory Allocation
 In memory object is a composite block
 made up of the non-static data members
 of the class. 

Non static initializer block
 A non static initializer block is a block of code that belongs to the class.
 It has no signature.
 It is auto invoked to execute for every object created. 
 It is used to assign initial values to data members of the object.
 
Constructor
 A constructor is a special member of the class.
 It has same name as of the class and no return type specification.
 It is auto invoked to execute for every object created. 
 It is used to assign initial values to data members of the object.
 It can be classified as: 
  * Default
  * Parameterized
  The default constructor is parameterless and uses preset values to initialize the object members. 
  The parameterized constructor takes and uses parameter data to initialize the object members.

NOTE:
 A class can have multiple (default and parameterized)
 constructors to allow object initialization in multiple
 ways. 
 Such is feature is implementation of OOP concept: POLYMORPHISM

 It is termed as "Constructor Overloading". 

*/