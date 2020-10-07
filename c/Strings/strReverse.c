//program to reverse a string 
//see : strReverse.png

#include<stdio.h> 
//#include<string.h>

int slength(char s[])
{
    int q;//a variable
    q =0;
    while(s[q] != '\0')
        q++;
    
    return q;
}

void sreverse(char s[])
{
    int x, y;//boundaries
    char temp;//swap
    x = 0;//lower boundary
    y = slength(s) -1; //upper boundary
    
    while(x < y)
    {
        //swap
        temp = s[x];
        s[x] = s[y];
        s[y] = temp;
        
        //reinitialize
        x++;
        y--;
    }
    //as string is an array so it is passed by reference
    //hence changes to formal parameter array update 
    //the actual array
    
}

int main()
{
    char str[20];// a string (declaration)
    
    printf("\n Enter a string : ");
    scanf("%19s", str);
    
    printf("\n String : %s ", str);
    
    //reverse the string 
    //strrev(str);//a ready made function to reverse the string
    sreverse(str);//a user defined function to reverse the string
    
    printf("\n String : %s ", str);
    
    return 0;
}