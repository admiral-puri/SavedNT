#include<stdio.h> 
/*
Constants
========= 
Constant are unmodifiable values of the program.
C allows representation of constant in 3 ways:
 * As direct specified value
 * As a variable declared as const (read only)
 * As a member of ENUM
 
When a value is directly written in program code then 
system treats it as a constant.
Example:
 Numeric constants : 10, 1.23F, 1.23  are int, float and double constant values
 Char constants : 'q', 'w', 'e', etc are char constants
 String constant : "computer" , "programming"

Usage :  
 if(age > 20) {}
 if(percentage < 40) {}
 Here 20 and 40 are int constant values. 
  

If a variable is to made read only 
then keyword "const" is prefixed to it.
Such variables must be assigned a value 
once and at the time of declaration.
Next they act as read only and compiler 
doesnt support writing operations on them.
 
Example:
 const float PI =3.14 ;
 area = PI *r *r
 
Enum allows declaration of a set of int constant values.
  
Syntax : 
enum 
{
 name1 = value1,  //default value ZERO
 name2 = value2, //default value PREV VAL +1
 name3,
 name4
}; 
 
Example :
enum
{
 SUNDAY=1,
 MONDAY=2,
 TUESDAY,
 WEDNESDAY,
 THURSDAY,
 FRIDAY,
 SATURDAY
} 
 */

enum
{
 NEWBORN = 0,   
 INFANT = 2,
 KID = 5,
 CHILD = 12,
 TEEN = 19,
 ADULT = 20,
 GODMAN = 100 
}; 

int main()
{
    int age;
    printf("\n Enter age : ");
    scanf("%d", &age);
    
    if(age >= NEWBORN && age < INFANT)
    {
        printf("\n AAAA");
    }
    else if(age >= INFANT && age < KID)
    {
        printf("\n BBBB");
    }
    else if(age >= KID && age < CHILD)
    {
        printf("\n CCCC");
    }    
    else if(age >= CHILD && age < TEEN)
    {
        printf("\n DDDD");
    }
    else if(age >= TEEN && age < ADULT)
    {
        printf("\n EEEE");
    }
    else if(age >= ADULT && age < GODMAN)
    {
        printf("\n FFFF");
    }
    else if(age >= GODMAN)
    {
        printf("\n GGGG");
    }
    else 
    {
        printf("\n HHHH");
    }

//Here ENUM allowed us to declare a group of related constants.
//Their use keeps us away from remembering their numeric values.
//This enhances readability and eases use.
    return 0;
}//main
