//C program to study division operators.
/*
 C provides 2 operators that perform division.
 1) / (divide)
 2) % (modulus)
 
 Both perform division.
 / returns the quotient of division.
 % returns the remainder of division.
 
 Remainder is produced only for whole numbers (int, long),
 so % operator works on int and long only.
 
 For types float and double the division is performed until 
 remainder becomes ZERO, so % operator is not defined to 
 act on float and double.
 
 Refer the code.
 */
#include<stdio.h>

int main()
{
    int x, y;
    int q, r;
    float f;
    
    printf("\n Enter 2 numbers ");
    scanf("%d%d", &x,&y);
    
    q = x/y;//quotient
    r = x%y;//remainder
    
    printf("\n %d / %d = %d ", x, y, q);
    printf("\n %d %% %d = %d ", x, y, r);
   
    //for float and double
    
    //RULE : operation on operands of a common type, results in a value of the same type.
    //RULE : operation on operands of a compatible types, results in a value of the higher type.
    
    //f = 10/7;
    f = 10/7.0;
    printf("\n 10 / 7.0 = %f ", f);
    
    
    return 0;
}

