 package rmiinterface;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ArithmeticInterface extends Remote 
{
    double add(double n1, double n2) throws RemoteException;
    double subtract(double n1, double n2) throws RemoteException;
    double multiply(double n1, double n2) throws RemoteException;
    double divide(double n1, double n2) throws RemoteException;
}
