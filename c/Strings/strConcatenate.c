//Program to concatenate strings

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

void scat(char s1[], char s2[])
{
    int x,y;
    
    x = 0;//at beginning of s2
    y = slength(s1);//at end of s1
    
    while(s2[x] != '\0')
    {
        s1[y] = s2[x];
        x++;
        y++;
    }
    s1[y] = '\0';//mark EOS for s2
}

int main()
{
    char s1[40];
    char s2[20];
    
    printf("\n Enter a String : ");
    scanf("%19s", s1);//ant
    
    printf("\n Enter another String : ");
    fflush(stdin);
    scanf("%19s", s2);//hill
    
    //string concatenation
    //strcat(s1, s2);//rhs string is concatenated (appended) to the lhs string    
    scat(s1,s2);
    
    printf("\n s1 : %s ", s1);//anthill
    printf("\n s2 : %s ", s2);//hill
    
    return 0;
}