//Program to toggle the case of a string 
//Example : tiGeR --> TIgEr
//Note:
//Uppercase alphabets are A to Z
//They take ASCII value 65 to 90
//Lowercase alphabets are a to z
//They take ASCII value 97 to 122
//Observe the difference : 32
//So adding/subtracting 32 changes the case

#include<stdio.h>

void toggleCase(char s[])
{//original : tiGeR
 //toggled : TIgEr

    int i;
    for(i =0; s[i] != '\0'; i++)
    {
        if(s[i] >=65 && s[i] <=90)//range for upper case alphabets
        {//uppercase, toggle to lower case
            s[i] = s[i] + 32;
        }
        else if(s[i] >=97 && s[i] <=122)//range for lower case alphabets
        {//lowercase, toggle to upper case
            s[i] = s[i] - 32;
        }

    }//for
}//toggleCase

int main()
{
    char str[20];

    printf("\n Enter a string : ");
    scanf("%19s", str);
    
    printf("\n String : %s ", str);
    
    //togglecase the string 
    toggleCase(str);

    printf("\n String : %s ", str);
    
    return 0;
}
