//Program to read a file byte by byte
#include<stdio.h>

int main()
{
 FILE * fp;
 char fname[100] = "d:/a.txt";
 int x;

 //open a file
 fp = fopen(fname, "r");

 //test open status
 if(fp == NULL)
 {
  printf("\n File %s Not Found", fname);
  return 1;//return with FAILURE status
 }

 //file is open, read it
 while((x = fgetc(fp))!= -1)
    printf("%c", x);


 //close the file
 fclose(fp);

 return 0;
}
