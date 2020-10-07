/*
Encapsulation:
 Binding operations (code) and attributes (data) of an entity into one unit.

Class:
 In OOP, for implementing Encapsulation, a class is formed that is composed 
 of data members and methods.
 It (the class) represents an entity.
 For the system it is a secondary datatype that is usable through instantiation. 

Object : 
 Refer "Object and its life.txt" 

this:
 this is a System defined formal parameter for non static methods of the class.
 It is a reference of type current class.
 It is auto initialized with the reference to caller object of the method.
 It is auto applied to access the object data members in the method.
 It is a final (unmodifiable) reference.
 
*/


class Stack
{
 //data members
 int data[];
 int top;

 //methods

 //initialize the Stack
 void init()
 {
  init(5);
 } 

 void init(int x)
 {
   //memory allocation
   data = new int[x];     

   //initialization
   top = -1;//Empty
 }

 void push(int val)
 {
  if(top < data.length-1)
  {
   top++;
   data[top] = val;
  }
  else
   System.out.println("Stack Overflow");
 }

 int pop()
 {
  int val = 0;
  if(top > -1)
  {
   val = data[top];
   top--;
  }
  else
   System.out.println("Stack is Empty");

  return val;
 }

 void display()
 {
  int i;
  if(top > -1)
  {
   for(i = top; i >=0; i--)
    System.out.println(data[i]);
  }
  else
   System.out.println("Stack is Empty");

 }

 public static void main(String args[])
 {
  //Use the Stack
  Stack stk = new Stack();
  stk.init(5);

  stk.push(10);
  stk.push(20);
  stk.push(30);
  stk.push(40);
  stk.push(50);
  stk.push(60);

  System.out.println("Removed : "  + stk.pop());
  System.out.println("Removed : "  + stk.pop());

  stk.display();  
    
 }

}//Stack