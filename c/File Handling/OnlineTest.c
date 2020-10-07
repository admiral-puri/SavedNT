//Program to test String i/o
#include<stdio.h>
#include<string.h>

int main()
{
 FILE *fp;
 char fname[50] = "C:\\C1\\File Handling\\qset.txt";
 char fresult[50] = "C:\\C1\\File Handling\\result.txt";
 char str[500], name[100];
 char q[500], o1[500], o2[500],o3[500],o4[500], ans[5];
 char userans[5];
 int flag = 1;
 int len,cnt=0, marks =0;

 fp = fopen(fname, "r");
 if(fp == NULL)
 {
    printf("\n Question Set Not Found");
    return 1;
 }

 printf("\n Enter Name : ");
 fgets(name, 50, stdin);
 //clear the \n in name
 name[strlen(name) - 1] = '\0';


 //file is open start the test
 //considering all question be asked
 while(flag)
 {
    //read a string max 499 characters or until \n whichever encountered first
    //if read then \n would be found in the string
    //it (\n) may require handling

    if(fgets(str,499, fp)== NULL)
    {
        flag = 0;
    }
    else
    {//data fetched
     cnt++;
     len = strlen(str);
     if(len > 1)
     {
        if(cnt== 1)
            strcpy(q, str);
        else if(cnt == 2)
            strcpy(o1, str);
        else if(cnt == 3)
            strcpy(o2, str);
        else if(cnt == 4)
            strcpy(o3, str);
        else if(cnt == 5)
            strcpy(o4, str);
        else if(cnt == 6)
            strcpy(ans, str);

     }
     else if(len == 1)
     {
       printf("%s", q);
       printf("1)%s", o1);
       printf("2)%s", o2);
       if(strcmp(o3, "DUMMY\n") != 0)
        printf("3)%s", o3);
       if(strcmp(o4, "DUMMY\n") != 0)
        printf("4)%s", o4);

       printf("Answer : ");
       fflush(stdin);
       fgets(userans, 4, stdin);
       if(strcmp(userans, ans)== 0)
        marks++;
       cnt = 0;
     }
    }//else

 }//while
 printf("\n Score : %d/10", marks);
 //close the file
 fclose(fp);

 //compose a result
 sprintf(str, "%s : %d/10\n", name,marks);
 //put the result in a file

 fp = fopen(fresult, "a");//append
 if(fp == NULL)
    printf("\n Result Recording Error");

 fputs(str, fp);
 fclose(fp);

 return 0;
}
