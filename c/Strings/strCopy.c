//Program to implement string copy

#include<stdio.h>
//#include<string.h>

void scopy(char s2[], char s1[])
{
    int i;
    for(i =0 ; s1[i] != '\0'; i++)
        s2[i] = s1[i];
    
    s2[i] = '\0';//mark EOS for s2
}

int main()
{
    char s1[20];
    char s2[20];
    
    printf("\n Enter a String : ");
    scanf("%19s", s1);
    
    //string copy
    //strcpy(s2, s1);//rhs string is copied into the lhs string    
    scopy(s2,s1);
    
    printf("\n s1 : %s ", s1);
    printf("\n s2 : %s ", s2);
    
    return 0;
}