/*
Program to study : Short Circuit Behaviour

From the knowledge of Truth Tables, it is realized that
1) When LHS of Logical And is False then the result will be False
2) When LHS of Logical Or is True then the result will be True.

C allows systems to conclude the result without solving
the RHS criteria in above cases.
Such a behaviour is termed as short circuit.

See : ShortCircuit.png
*/
#include<stdio.h>

int main()//program begins here
{
    int x, y,z;
    x = 0;
    y = 10;
    
    //z = x++ && --y;
    z = ++x || y--;
    
    printf("\n %d %d %d",x,y,z);

    return 0;//status representing successful completion
}

