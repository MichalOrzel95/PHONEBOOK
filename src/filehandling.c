//
// Created by Eagle on 2017-06-27.
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "filehandling.h"
#include "supplement.h"

//Global variables
extern bool firstpassage;

//Showing all contacts in phonebook
void ShowAll(FILE *file)
{
    char verse[80];
    printf("FORENAME,SURNAME,NUMBER\n");
    printf("******************************************\n");
    //Print out all the phonebook
    while((fgets(verse,80,file))!=NULL)
    {
        printf("%s",verse);
    }
    printf("\n******************************************");
}

//Adding new person to phonebook
void AddContact(FILE *file)
{
    char forename[30];
    char surname[30];
    int phonenumber;
    char number;

    do
    {
        printf("Enter a number of people to wrote: ");
        scanf(" %c",&number);
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
            scanf("%i", &phonenumber);
            fseek(stdin, 0, SEEK_END);
        }while(phonenumber<100000000);

        if(firstpassage==true)
        {
            fprintf(file,"%s,%s,%i",forename,surname,phonenumber);
        }
        else
        {
            fprintf(file,"\n%s,%s,%i",forename,surname,phonenumber);
        }
    }
}

//Removing person from the phonebook
void RemovePerson(FILE *file)
{
    char buffer[50];
    char person[40];

    FILE *newfile;

    if((newfile=fopen(NEWPATH,"a+"))==NULL)
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
        if((strstr(buffer,person))==NULL)
        {
            fprintf(newfile,"%s",buffer);
        }
    }

    rename(PHBPATH,TMPPATH);
    rename(NEWPATH,PHBPATH);
    remove(TMPPATH);

    fclose(newfile);
}

//Searching for person in phonebook
void SearchPhonebook(FILE *file)
{
    char buffer[50];    //Array storing line from phonebook
    unsigned short option;

    printf("Available options:\n");
    printf("1-Searching by forename\n");
    printf("2-Searching by surname\n");
    printf("3-Searching by number\n");
    printf("4-Searching by name(fore+sur-name)\n");

    do
    {
        printf("Enter a number[1-4]: ");
        scanf("%hi", &option);
    }while((option<1 || option>4));

    switch(option)
    {
        case 1:
        {
            char forename[25];
            printf("Enter the forename: ");
            scanf("%s",forename);
            forename[strlen(forename)]=',';

            while((fgets(buffer,50,file))!=NULL)
            {
                if((CompareStrings(forename,buffer))==0)
                {
                    printf("%s",buffer);
                }
            }

        }break;
        case 2:
        {
            char surname[25];
            printf("Enter the surname: ");
            scanf("%s",surname);

            while((fgets(buffer,50,file))!=NULL)
            {
                if((strstr(buffer,surname))!=NULL)
                {
                    printf("%s",buffer);
                }
            }

        }break;
        case 3:
        {
            int pnumber;
            char pnumb[10];
            printf("Enter a number: ");
            scanf("%i",&pnumber);
            sprintf(pnumb,"%i",pnumber);

            while((fgets(buffer,50,file))!=NULL)
            {
                if((strstr(buffer,pnumb))!=NULL)
                {
                    printf("%s",buffer);
                }
            }

        }break;
        case 4:
        {
            char name[40];
            printf("Enter forename,surname: ");
            scanf("%s",name);

            while((fgets(buffer,50,file))!=NULL)
            {
                if((strstr(buffer,name))!=NULL)
                {
                    printf("%s",buffer);
                }
            }

        }break;
        default:
        {
            printf("Some error occured!\n");
        }break;
    }
}

//Exporting a person to another file
void ExportPerson(FILE *file)
{
    char buffer[50];
    char name[40];
    printf("Enter forename,surname: ");
    scanf("%s",name);

    FILE *exportfile;

    if((exportfile=fopen(EXPPATH,"a"))==NULL)
    {
        printf("Problem with creating export-file!\n");
        exit(EXIT_FAILURE);
    }

    while((fgets(buffer,50,file))!=NULL)
    {
        if((strstr(buffer,name))!=NULL)
        {
            fprintf(exportfile,"%s",buffer);
        }
    }

    fclose(exportfile);
}

//Counting contacts in phonebook
void CountContacts(FILE *file)
{
    char buffer[50];
    unsigned int numberofcontacts=0;

    while((fgets(buffer,50,file))!=NULL)
    {
        numberofcontacts++;
    }

    printf("Found %u contacts\n",numberofcontacts);
}
