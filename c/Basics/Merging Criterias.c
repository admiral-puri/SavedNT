//Program to study : Merging Criterias
//see : Merging Criterias.png
 
#include<stdio.h>

int main()
{
    int x, y;
    x = 0;
    y = 1;
    if(++x && y--)
        printf("\n Hello %d %d", x, y);//Hello 1 0 
    else
        printf("\n Hi %d %d",x,y);

    return 0;
}

