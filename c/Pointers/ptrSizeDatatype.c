//Program to study : size and datatype of pointer
//Refer : ptrSizeDatatype.png

#include<stdio.h>

int main()
{
    int *ip;
    char *cp;
    double *dp;
    
    printf("\n --- size of the pointers ---");
    printf("\n int pointer : %d ", sizeof(ip));
    printf("\n char pointer : %d ", sizeof(cp));
    printf("\n double pointer : %d ", sizeof(dp));
    
    printf("\n\n --- dereferencing quantity for the pointers ---");
    printf("\n int pointer : %d ", sizeof(*ip));
    printf("\n char pointer : %d ", sizeof(*cp));
    printf("\n double pointer : %d ", sizeof(*dp));
    
    printf("\n\n --- pointer arithmetic (adding 3) ---");
    printf("\n int pointer : %u %u ", ip, ip+3);
    printf("\n char pointer : %u %u ", cp, cp+3);
    printf("\n double pointer : %u %u ", dp, dp+3);
    
    return 0;
}