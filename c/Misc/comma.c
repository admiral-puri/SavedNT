#include<stdio.h> 
/*
 comma 
--------
 comma (,) has 2 uses in C.
 1) Separator
 2) Operator 
 
 It acts as a separator when used in declarations, 
 function and macro parameters and in enums.
 
 When used along with expressions, it acts as an operator.

 As an operator comma clubs multiple expressions together. 
 It makes the system solve every expression and return the value of last expression.
 The expressions resolve in left to right sequence and the value of rightmost expression is returned.

 Comma as an operator has the least priority. 

 */
int main()
{
    //syntax error 
    //int x = 10, 20, 30;
    //because the above is a declaration statement
    //where comma must act as a separator but
    //it is made to act as an operator. 
    
    int x,y,z,q; //comma acts as separator
    x = 10,20,30;//comma acts as operator
    printf("\n x : %d ", x);//x is 10 because = is more prior than ,
    
    x = (10,20,30);
    printf("\n x : %d ", x);//x is 30 because , returns the value of last expression
    
    
    y = 10;
    z = 15;
    q = (x =y++,++z,y+z);
    
    printf("\n x : %d ", x);//10
    printf("\n y : %d ", y);//11
    printf("\n z : %d ", z);//16
    printf("\n q : %d ", q);//27
    
    return 0;
}//main
