package rmiserver;

import java.rmi.*;
import java.rmi.server.*;
import rmiinterface.ArithmeticInterface;

public class ArithmeticServer extends UnicastRemoteObject implements ArithmeticInterface
{
    ArithmeticServer() throws RemoteException
    {
        super();
    }
            
    public double add(double n1, double n2) throws RemoteException 
    {
        System.out.println("add(" + n1 + "," + n2+ ")");
        return n1 + n2;
    }

    public double subtract(double n1, double n2) throws RemoteException 
    {
        System.out.println("subtract(" + n1 + "," + n2+ ")");
        return n1 - n2;        
    }

    public double multiply(double n1, double n2) throws RemoteException 
    {
        System.out.println("multiply(" + n1 + "," + n2+ ")");
        return n1 * n2;        
        
    }

    public double divide(double n1, double n2) throws RemoteException 
    {
        System.out.println("divide(" + n1 + "," + n2+ ")");
        return n1 / n2;        
    }

    /*
    
    void fx()
    {
        //other methods
    }
    */
    
}
