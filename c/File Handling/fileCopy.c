//Program to copy a file
#include<stdio.h>

int main()
{
 FILE *fp1,*fp2;
 char fname1[100], fname2[100];
 int x;

 printf("\n Enter the source file ");
 scanf("%99s", fname1);
 printf("\n Enter the target file ");
 fflush(stdin);
 scanf("%99s", fname2);

 //open the source file
 fp1 = fopen(fname1, "rb");//file must exist

 //test open status
 if(fp1 == NULL)
 {
  printf("\n Source File %s Not Found", fname1);
  return 1;//return with FAILURE status
 }

 //open the target file
 fp2 = fopen(fname2, "wb");//created or overwritten
 //test open status
 if(fp2 == NULL)
 {
  printf("\n Target File %s Cannot Be Created", fname2);
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
