//Demonstration of : Storage Class Specifers
//Refer : StorageClassSpecifiers.txt

#include<stdio.h>
#include<arith.h>
int main()
{
    auto int x; //int x;
    register int y;
    extern int z;
    
    for(y = 1; y < 100; y++)
    {
        x = y +z;
        printf("\n %d", x);
    }
  
    
    return 0;
}
