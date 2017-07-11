//
// Created by Michal Orzel on 2017-06-24.
// Project of phone-library using files' handling in C
//

//Include files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "supplement.h"
#include "filehandling.h"

//Main function
int main(void)
{
    FILE *phonebook;
    char sign;
    char option_number;

    if((phonebook=fopen(PHBPATH,"a+"))==NULL)
    {
        printf("Problem with opening phonebook!\n");
        printf("Closing program...");
        exit(EXIT_FAILURE);
    }

    do
    {
        //Set file to beginning
        fseek(phonebook,0,SEEK_SET);
        ShowEntrance();
        DoSelected(phonebook,ChooseOption());
        printf("Press r/R to return to menu or other key to exit: ");
        scanf(" %c",&sign);
    }while(sign=='r' || sign=='R');


    //Checking system
    #if SYSTEM != LINUX
    //Wait untill user press a key
    printf("\nPress any key to end: ");
    getchar();
    #endif
    //Closing file
    fclose(phonebook);

    return 0;
}//End of main


