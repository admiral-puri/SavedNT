//program to calculate: string length
//see : strLength.png

#include<stdio.h> 
//#include<string.h>

int slength(char s[])
{
    int x;//a variable
    x =0;
    while(s[x] != '\0')
        x++;
    
    return x;
}

int main()
{
    char str[20];// a string (declaration)
    int x;
    
    printf("\n Enter a string : ");
    scanf("%19s", str);
    
    //calculate string length
    //x = strlen(str); //ready made function to find the string length
    x = slength(str);//user defined function to find the string length
    
    printf("\n String : %s ", str);
    printf("\n length : %d ", x);
    
    return 0;
}