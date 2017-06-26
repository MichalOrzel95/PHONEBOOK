//
// Created by Michal Orzel on 2017-06-24.
//

//Include files
#include <stdio.h>
#include <ctype.h>
#include "supplement.h"

//Functions' definitions
//Showing the MENU of phonebook
void ShowEntrance(void)
{
    printf("******************************************\n");
    printf("****************PHONEBOOK*****************\n");
    printf("************Created by M.Orzel************\n");
    printf("*******************MENU*******************\n");
    printf("1.Show all phonebook\n");
    printf("2.Add new people\n");
    printf("3.Delete someone from the phonebook\n");
    printf("4.Search for someone\n");
    printf("5.Export someone to new file\n");
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

        }break;
        case '3':
        {

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
}

//Showing all contacts in phonebook
void ShowAll(FILE *file)
{
    char verse[80];
    printf("FORNAME\t\tSURNAME\t\tNUMBER\n");
    printf("-------\t\t-------\t\t------\n");
    while((fgets(verse,80,file))!=NULL)
    {
        printf("%20s",verse);
    }
}

