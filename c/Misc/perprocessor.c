//Preprocessor Directives
#include<stdio.h>

#define PI 3.14 //macro PI with value 3.14
#define qwerty int main()
#define AREA(r)  PI*r*r //parameterized macro

qwerty
{
#undef qwerty //here after the occurrences of qwerty will not be replaced 
//#undef PI
#ifdef PI    
    float rad, ar;
    rad = 7;
    ar = AREA(rad);//after replacement ar = 3.14 * rad * rad;
    printf("Value of PI : %f", PI);
    printf("\nArea(%f) : %f ", rad, ar);
#else
    printf("\n SORRY PI IS NOT DEFINED");
#endif
    
    return 0;
}
