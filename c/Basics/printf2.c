//Program to demonstrate : 
//printf used to output data stored in variables

//Refer : printf.txt
//See : Streams.png

#include<stdio.h>//to get the definition of printf and many other functions

int main()//program begins here
{
    int a;//an int variable
    a = 13;//set it to value 13
    //print it
    printf("\n a : %d", a);//output a in decimal form
    printf("\n a : %x", a);//output a in hexadecimal form
    printf("\n a : %X", a);//output a in HEXADECIMAL form
    printf("\n a : %o", a);//output a in octal form
    printf("\n a : %i", a);//output a in integer form
    
    
    return 0;//status representing successful completion
}

