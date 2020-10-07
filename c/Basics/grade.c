//Program to give a grade based on average of 3 subjects
//study of else if statement
//refer : conditional branching.txt
//see : else if.png
#include<stdio.h>

int main()
{
    int s1,s2,s3;
    float avg;
    
    printf("\n Enter marks for 3 subjects ");
    scanf("%d%d%d", &s1,&s2,&s3);
    avg = (s1+s2+s3)/3.0;
    
    if(avg >=0 && avg < 40)
    {
        printf("\n Average : %.2f ", avg);
        printf("\n Grade : D");
    }
    else if(avg >=40 && avg < 60)
    {
        printf("\n Average : %.2f ", avg);
        printf("\n Grade : C");
    }
    else if(avg >=60 && avg < 75)
    {
        printf("\n Average : %.2f ", avg);
        printf("\n Grade : B");
    }
    else if(avg >=75 && avg <= 100)
    {
        printf("\n Average : %.2f ", avg);
        printf("\n Grade : A");
    }
    else
    {
        printf("\n Invalid Marks");
    }
    return 0;
}

