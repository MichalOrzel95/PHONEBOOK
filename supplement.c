//
// Created by Michal Orzel on 2017-06-24.
//

//Include files
#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
    printf("******************************************\n");
}

//Choosing an option from menu
char ChooseOption(void)
{
    char number;
    do
    {
        printf("Move to an option by entering a particular number[1-5]: ");
        scanf("%c",&number);
        fseek(stdin,0,SEEK_END);
    }while(!(isdigit(number)) || (number=='0' || number>'5'));

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
void DoSelected(char number,FILE *file)
{
    switch(number)
    {
        case '1':
        {
            ShowAll(file);
        }break;
        case '2':
        {
            AddContact(file);
        }break;
        case '3':
        {
            RemovePerson(file);
        }break;
        case '4':
        {

        }break;
        case '5':
        {

        }break;
        default:
        {

        }break;
    }
    printf("\nEND\n");
}

