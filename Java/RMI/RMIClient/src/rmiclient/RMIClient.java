package rmiclient;
import java.rmi.*;
import rmiinterface.ArithmeticInterface;
public class RMIClient 
{

    public static void main(String[] args) 
    {
        try
        {
            System.out.println("Hi i am the rmi client");
            System.out.println("i do lot of work");
            System.out.println("for arithmetic i rely on other machine");
            Remote r = Naming.lookup("rmi://127.0.0.1:1099/math");
            ArithmeticInterface ai = (ArithmeticInterface) r;
            
            System.out.println("20 + 7.1 = " + ai.add(20, 7.1));
            System.out.println("20 - 7.1 = " + ai.subtract(20, 7.1));
            System.out.println("20 * 7.1 = " + ai.multiply(20, 7.1));
            System.out.println("20 / 7.1 = " + ai.divide(20, 7.1));
            
            System.out.println("... more to come");
            System.out.println("by then practice this much");
            
        }
        catch(Exception ex)
        {
            System.out.println(ex);
        }
    }    
}
