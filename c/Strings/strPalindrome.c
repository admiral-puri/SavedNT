//program to check where a string is a palindrome string or not

#include<stdio.h> 

int slength(char s[])
{
    int q;//a variable
    q =0;
    while(s[q] != '\0')
        q++;
    
    return q;
}

int chkPalindrome(char s[])
{
    int x, y;
    
    x = 0;//lower boundary
    y = slength(s)-1;//upper boundary
    
    while(x < y)
    {
        if(s[x] != s[y])
            return 0;//false
        x++;
        y--;
    }//while
    return 1;//true
}//chkPalindrome

int main()
{
    char str[20];// a string (declaration)
    int flag;
    
    printf("\n Enter a string ");
    scanf("%19s", str);
    
    
    //check for palindrome 
    flag = chkPalindrome(str);
    if(flag == 1)
        printf("\n %s is a palindrome ", str);
    else
        printf("\n %s is not a palindrome ", str);
    
    return 0;
}