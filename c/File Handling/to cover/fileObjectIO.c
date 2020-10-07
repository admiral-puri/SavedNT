//Program to implement : File Object W/R
//Refer : FileHandling.png
//See : fileObjectIO.png

#include<stdio.h>
typedef struct 
{
    char name[20];
    int age;
    char gender;
} Person;

int main()
{
    FILE *fio;
    int ch;
    Person p = {"Vikas", 25, 'M'};
    Person p1;
    
    fio = fopen("d:\\objectIO.txt", "wb+");
    if(fio == NULL)
    {
        printf("\n File Open Failed");
        return 1;//exit main fn
    }
    //file open w/r object 
    
    //write 1 object of given size (address given) into the file
    fwrite(&p,sizeof(Person),1,fio);
    rewind(fio);
    //read from the file data of 1 object (of given size) and transfer into the address of given object.
    fread(&p1,sizeof(Person),1,fio);
    
    printf("\n p{ %s %d %c }", p.name, p.age, p.gender);
    printf("\n p1{ %s %d %c }", p1.name, p1.age, p1.gender);
    
    fclose(fio);
    return 0;
}

