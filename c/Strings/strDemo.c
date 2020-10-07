//program to demonstrate use of a string
//refer : About String.txt
//see : strDemo.png

#include<stdio.h> 

int main()
{
    char str[20];// a string (declaration)
    
    //scan (user input)
    printf("\n Enter a string ");
    scanf("%19s", str);//Fetch from stdin, max 19 characters or until a space or enter is encountered. Store the fetched data into the string. The delimiter (space/enter) is not fetched, it is left out in the stream.
    
    //try it
    //str[3] = '\0';
    
    //print (output)
    printf("\n String is : %s ", str);
    
    return 0;
}