//Program to output :
//ASCII values in range 0-255

#include<stdio.h>

int main()
{
    int q;
    for(q =0; q< 256; q++)
    {
        printf(" ( %d %c )", q,q );
    }
    return 0;
}

/*
ASCII (American Standard Code for Information Interchange) 
values are standard codes to represent information. 
 
8 bit ASCII character set uses codes in range 0-255  
to represent 256 unique values. 
 
Some well known  values and their ASCII codes :
A-Z : 65-90 
a-z : 97-122 
0-9 : 48-57 
32 : space  
  
See the output of example above. 
 */