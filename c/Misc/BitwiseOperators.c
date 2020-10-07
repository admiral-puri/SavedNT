//Program to study : Bitwise Operators
//Refer : The note below.
//See : BitwiseOperators.png

#include<stdio.h> 

void dec2Binary(unsigned int n)
{
    int arr[32] = {};//all elements set to 0
    int i;
    printf("\n%u : ", n);
    
    i = 31;//at the last position
    while(n >0)
    {
        arr[i] = n %2;//remainder
        i--;//31 to 0
        n = n /2;
    }

    for(i =0 ; i < 32; i++)
        printf("%d", arr[i]);
}


int main()
{
    unsigned int x,y,z;//32 bit value, all bits store data
    
    x = 19;
    //y = x << 2;
    //y = x >> 2;
    //y = ~x;
    
    //dec2Binary(x);
    //dec2Binary(y);
    x = 19;
    y = 5;        
    //z = x & y;
    //z = x | y;
    z = x ^ y;
    dec2Binary(x);
    dec2Binary(y);
    dec2Binary(z);
    
    return 0;
}//main

/*
Bitwise operators act on the binary digits of whole numbers.
C provides 6 bitwise operators.
1) Left shift : <<
2) Right shift : >>
3) Ones Complement : ~
4) Bitwise AND : &
5) Bitwise OR : |
6) Bitwise XOR : ^


1) Left shift : <<
Left shift is a binary bitwise operator.
Say 19 << 2
The operator would shift all the bits of 19 leftwards by 2 positions.
The leftmost 2 bits are lost.
The 2 blanks created at the right are autofilled with Zeros.
A number representing the generated bits is returned.

2) Right shift : >>
Right shift is a binary bitwise operator.
Say 19 >> 2
The operator would shift all the bits of 19 rightwards by 2 positions.
The rightmost 2 bits are lost.
The 2 blanks created at the left are autofilled with Zeros.
A number representing the generated bits is returned.


3) Ones Complement : ~
Ones Complement is a unary bitwise operator.
Say ~19
The operator would reverse all the bits of 19.
The Zero bits would become One and the One bits would become 0. 
A number representing the generated bits is returned.

4) Bitwise AND : &
Bitwise AND is a binary bitwise operator.
Say 19 & 5
The operator would AND MASK the bits of 19 and 5.
A number representing the generated bits is returned.

AND MASK Table
 1 & 1 = 1
 1 & 0 = 0
 0 & 1 = 0
 0 & 0 = 0

5) Bitwise OR : |
Bitwise OR is a binary bitwise operator.
Say 19 | 5
The operator would OR MASK the bits of 19 and 5.
A number representing the generated bits is returned.

OR MASK Table
 1 | 1 = 1
 1 | 0 = 1
 0 | 1 = 1
 0 | 0 = 0


6) Bitwise XOR : ^
Bitwise XOR is a binary bitwise operator.
Say 19 ^ 5
The operator would XOR MASK the bits of 19 and 5.
A number representing the generated bits is returned.

XOR MASK Table
 1 ^ 1 = 0
 1 ^ 0 = 1
 0 ^ 1 = 1
 0 ^ 0 = 0

*/