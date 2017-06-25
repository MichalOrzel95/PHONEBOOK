//
// Created by Michal Orzel on 2017-06-24.
// Project of phone-library using files' handling in C
//

//Include files
#include <stdio.h>
#include <string.h>
#include "supplement.h"

//Main function
int main(void)
{
    FILE *phonebook;
    char option_number;
    ShowEntrance();
    if((phonebook=fopen("phonebook.txt","a+"))!=NULL)
    {
        option_number=ChooseOption();
        DoSelected(option_number,phonebook);
    }
    else
    {
        printf("There is a problem with file!\n");
    }


    return 0;
}//End of main


