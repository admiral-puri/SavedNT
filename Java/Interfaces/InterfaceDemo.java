interface Client
{
 String fx();
}


class Service
{
  void serve(Client ref)
  {

   String data = ref.fx();
   System.out.println();
   System.out.print("{ ");
   System.out.print(data);
   System.out.println(" }");
  }

}



class A implements Client
{
 public String fx()
 {
  return "HELLO FROM A";
 }

 //has other methods 
}

class B implements Client
{
 public String fx()
 {
  return "I m B";
 }

 //has other methods 
}

class C implements Client
{
 public String fx()
 {
  return "World copies C";
 }

 //has other methods 
 
}


class InterfaceDemo
{
 public static void main(String args[])
 {
  Service svc = new Service();
  A objA = new A();
  B objB = new B();
  C objC = new C();

  svc.serve(objA);
  svc.serve(objB);
  svc.serve(objC);


 }
}