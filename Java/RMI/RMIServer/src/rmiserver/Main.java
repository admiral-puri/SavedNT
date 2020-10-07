package rmiserver;
import java.rmi.*;
import java.rmi.registry.*;
public class Main 
{
    public static void main(String[] args) 
    {
        try
        {
            //Activate the Java's RMI Registry : naming facility
            LocateRegistry.createRegistry(1099);
            
            ArithmeticServer as = new ArithmeticServer();
            Naming.rebind("rmi://127.0.0.1:1099/math", as);
            
            System.out.println("Server waiting for remote calls ....");
        }
        catch(Exception ex)
        {
            System.out.println("Err: "+ ex);
        }
    }
}
