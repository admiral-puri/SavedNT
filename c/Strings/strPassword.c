//Program to accept password from user
//if it is "student" then output LOGIN SUCCESS
//otherwise output LOGIN FAILED
//see : strCompare.png

#include<stdio.h>
//#include<string.h>

void getPassword(char s[])
{
    printf("\n Enter Password : ");
    //getch() takes a char from stdin
    //returns its ASCII 
    //user input is not echoed on screen
    int q, i;
    i =0;
    
    while(i < 19)//19 is string size
    {
        fflush(stdin);
        q = getch();//canonical input (typed key value reaches the application immediately, doesn't wait for user to press enter)        
        if(q == 13)//enter
            break;
        else if(q == 8 )//backspace
        {
            if(i > 0)
                i--;
        }
        else
        {
            s[i] = q;
            i++;
        }
        printf("*");
    }
    
    s[i] = '\0';//mark the end of string (EOS)
}//getPassword


int sCompare(char a[], char b[])
{//a-b > 0 : a > b
 //a-b < 0 : b > a
 //a-b ==0 : a == b   
    
    int i;//loop control
    int difference;
    
    i =0;//beginning with index 0
    while(a[i] != '\0' || b[i] != '\0')//going upto the EOS
    {
        difference = a[i] - b[i];//ASCII subtraction
        if(difference != 0)
            return difference;//comparison ends
        
        i++;//compare the next element
    }//while
    return 0;//equal strings (no difference across corresponding elements ASCCI values)
}

int main()
{
    char str[20];
    int flag;
    
    getPassword(str);
    flag = sCompare(str, "student"); 
    
    if(flag == 0)
        printf("\n LOGIN SUCCESS");//equal
    else
        printf("\n LOGIN FAILED");//not equal
    
    return 0;
}