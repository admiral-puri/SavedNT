//study of static variable
//read the note : static.txt
//see : static.png

#include<stdio.h>

void fx()// x creates
{
    int x = 10;//local
    static int y = 10;//local + static

    printf("\n x : %d , y : %d ", x, y);
    x++;
    y++;
}//x deallocates

int main() //y creates, but would remain usable in fx only
{
    fx();
    fx();
    fx();
    return 0;
}//y deallocates