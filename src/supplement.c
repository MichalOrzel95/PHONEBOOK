//
// Created by Michal Orzel on 2017-06-24.
//

//Include files
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "supplement.h"
#include "filehandling.h"

//Functions' definitions
//Showing the MENU of phonebook
void ShowEntrance(void)
{
    printf("******************************************\n");
    printf("****************PHONEBOOK*****************\n");
    printf("************Created by M.Orzel************\n");
    printf("*******************MENU*******************\n");
    printf("1.Show all the phonebook\n");
    printf("2.Add new people\n");
    printf("3.Delete someone from the phonebook\n");
    printf("4.Search for someone\n");
    printf("5.Export someone to a new file\n");
    printf("6.Number of contacts in phonebook\n");
    printf("******************************************\n");
}

//Choosing an option from menu
char ChooseOption(void)
{
    char number;
    do
    {
        fseek(stdin,0,SEEK_END);
        printf("Choose an option[1-6] or [e/E] to exit: ");
        scanf(" %c",&number);
        if(number=='e' || number=='E')
            exit(EXIT_FAILURE);
    }while(!(isdigit(number)) || (number=='0' || number>'6'));

    return number;
}

//Comparing 2 strings
int CompareStrings(char *str1,char *str2)
{
    size_t size=strlen(str1);

    while(size>0)
    {
        if((*str1)!=(*str2))
        {
            return -1;
        }
        str1++;
        str2++;
        size--;
    }
    return 0;
}

//Switch function
void DoSelected(FILE *file,char option_number)
{
    CLEAR_SCREEN;
    switch(option_number)
    {
        case '1':
        {
            ShowAll(file);  //Show phonebook
        }break;
        case '2':
        {
            AddContact(file);   //Add to phonebook
        }break;
        case '3':
        {
            RemovePerson(file); //Remove from phonebook
        }break;
        case '4':
        {
            SearchPhonebook(file);  //Search for someone in phonebook
        }break;
        case '5':
        {
            ExportPerson(file); //Export a person from the phonebook
        }break;
        case '6':
        {
            CountContacts(file);    //Count contacts in phonebook
        }break;
        default:
        {

        }break;
    }
    printf("\n\n");

    CloseFile(file);
}

//Closing the phonebook
void CloseFile(FILE *file)
{
    //Checking system
    #if SYSTEM != LINUX
    //Wait untill user press a key
    printf("\nPress any key to end: ");
    getchar();
    #endif
    //Closing file
    fclose(file);
}
