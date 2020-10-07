//program to check where a string is a palindrome string or not
//through command line arguments

#include<stdio.h>
#include<stdlib.h>

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

int main(int argc, char *argv[])
{
    int flag;

    if(argc != 2)
    {
        printf("\n Wrong Number of arguments, expected a string ");
        exit(1);
    }

    //check for palindrome
    flag = chkPalindrome(argv[1]);
    if(flag == 1)
        printf("\n %s is a palindrome ", argv[1]);
    else
        printf("\n %s is not a palindrome ", argv[1]);

    return 0;
}
