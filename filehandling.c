//
// Created by Eagle on 2017-06-27.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "filehandling.h"
#include "supplement.h"

//Showing all contacts in phonebook
void ShowAll(FILE *file)
{
    char verse[80];
    printf("FORENAME,SURNAME,NUMBER\n");
    printf("******************************************\n");
    while((fgets(verse,80,file))!=NULL)
    {
        printf("%s",verse);
    }
}

//Adding new person to phonebook
void AddContact(FILE *file)
{
    char forename[30];
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
        scanf("%s",forename);
        printf("Enter the surname: ");
        scanf("%s",surname);
        do
        {
            printf("Enter the phonenumber: ");
            scanf("%i", &phonemuber);
            fseek(stdin, 0, SEEK_END);
        }while(phonemuber<100000000);

        fprintf(file,"\n%s,%s,%i",forename,surname,phonemuber);
    }
}

//Removing person from the phonebook
void RemovePerson(FILE *file)
{
    char buffer[50];
    char person[50];

    FILE *newfile;

    if((newfile=fopen("/home/orzelm/PROGRAMMING/PHONEBOOK/newfile.txt","a+"))==NULL)
    {
        printf("Problem with removing!\n");
        printf("Closing...");
        exit(EXIT_FAILURE);
    }

    printf("Enter forename,surname: ");
    scanf("%s",person);

    //Searching for a person in the phonebook
    while((fgets(buffer,50,file))!=NULL)
    {
        if((CompareStrings(person,buffer))!=0)
        {
            fprintf(newfile,"%s",buffer);
        }
    }

    rename("/home/orzelm/PROGRAMMING/PHONEBOOK/phonebook.txt","/home/orzelm/PROGRAMMING/PHONEBOOK/temp.txt");
    rename("/home/orzelm/PROGRAMMING/PHONEBOOK/newfile.txt","/home/orzelm/PROGRAMMING/PHONEBOOK/phonebook.txt");
    remove("/home/orzelm/PROGRAMMING/PHONEBOOK/temp.txt");
}
