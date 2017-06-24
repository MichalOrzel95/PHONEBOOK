//
// Created by Michal Orzel on 2017-06-24.
//

//Include files
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
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
int ChooseOption(void)
{
    char number;
    bool flag;
    do
    {
        flag=false;
        printf("Move to an option by entering a particular number: ");
        scanf("%c",&number);
        fseek(stdin,0,SEEK_END);
        if(isdigit(number))
        {
            flag=true;
        }
    }while(flag==false);

    return number;
}

