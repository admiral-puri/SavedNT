/*
Program to demonstrate : goto statement

C supports declaration of labels (named locations)
and jumps (transfer of program control) to labels
by use of goto statement.

Declaring label and using goto to transfer program
control is a wrong practice and not promoted.

C supported it as a backward compatibility feature
that languages before C had.
 */
#include<stdio.h>

int main()
{
    int q;
    printf("\n Enter a number ");
    scanf("%d", &q);

    if(q % 2 == 0)
        goto StartFromBeginning;
    else
        goto StartFromMid;

StartFromBeginning:
    printf("\n 1");
    printf("\n 2");
    printf("\n 3");

StartFromMid:
    printf("\n 4");
    printf("\n 5");


    return 0;
}
