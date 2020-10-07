//Program to copy a file
//Through command line arguments

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
 FILE *fp1,*fp2;
 int x;

 if(argc != 3)
 {
    printf("\n Source and Target File Name Expected");
    exit(1);
 }

 //open the source file
 fp1 = fopen(argv[1], "rb");//file must exist

 //test open status
 if(fp1 == NULL)
 {
  printf("\n Source File %s Not Found", argv[1]);
  return 1;//return with FAILURE status
 }

 //open the target file
 fp2 = fopen(argv[2], "wb");//created or overwritten
 //test open status
 if(fp2 == NULL)
 {
  printf("\n Target File %s Cannot Be Created", argv[2]);
  fclose(fp1);
  return 1;//return with FAILURE status
 }

 //Both files are open, copy
 while((x = fgetc(fp1))!= -1)
    fputc(x, fp2);

 //close the files
 fclose(fp1);
 fclose(fp2);
 printf("Copy Success");


 return 0;
}
