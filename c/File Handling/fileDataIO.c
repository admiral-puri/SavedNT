//Program to test data i/o
#include<stdio.h>

int main()
{
 FILE *fp;
 char fname[100] = "d:\\data.txt";
 int a1 = 34513;
 char c1= 'q';
 double d1= -134.8763;
 char s1[20]="computer";
 int a2;
 char c2;
 double d2;
 char s2[20];

 //open the target file
 fp = fopen(fname, "wb+");//created or overwritten
 //test open status
 if(fp == NULL)
 {
  printf("\n File %s Cannot Be Created", fname);
  return 1;//return with FAILURE status
 }

 //write data into the file
 fprintf(fp, "%d\n", a1);
 fprintf(fp, "%c\n", c1);
 fprintf(fp, "%lf\n", d1);
 fprintf(fp, "%s\n", s1);

 //rewind to BOF
 rewind(fp);

 fscanf(fp,"%d\n", &a2);
 fscanf(fp,"%c\n", &c2);
 fscanf(fp,"%lf\n", &d2);
 fscanf(fp,"%s\n", s2);

 printf("\n %d  %d ", a1,a2);
 printf("\n %c  %c ", c1,c2);
 printf("\n %lf  %lf ", d1,d2);
 printf("\n %s  %s ", s1,s2);



 fclose(fp);


 return 0;
}
