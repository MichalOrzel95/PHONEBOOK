//
// Created by Eagle on 2017-06-27.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "filehandling.h"

//Showing all contacts in phonebook
void ShowAll(FILE *file)
{
    char verse[80];
    printf("FORNAME,SURNAME,NUMBER\n");
    printf("******************************************\n");
    while((fgets(verse,80,file))!=NULL)
    {
        printf("%s",verse);
    }
}

//Adding new person to phonebook
void AddContact(FILE *file)
{
    char forname[30];
    char surname[30];
    int phonemuber;
    char number;

    do
    {
        printf("Enter a number of people to wrote: ");
        scanf("%c",&number);
        fseek(stdin,0,SEEK_END);
    }while(!(isdigit(number)) || number<0);


    for (int i = atoi(&number); i >0; --i)
    {
        printf("Enter the forname: ");
        scanf("%s",forname);
        printf("Enter the surname: ");
        scanf("%s",surname);
        printf("Enter the phonenumber: ");
        scanf("%i",&phonemuber);
        fseek(stdin,0,SEEK_END);

        fprintf(file,"\n%s,%s,%i",forname,surname,phonemuber);
    }

}
