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
    int numb;
    char option_number;

    if((phonebook=fopen(PHBPATH,"a+"))==NULL)
    {
        printf("Problem with opening phonebook!\n");
        printf("Closing program...");
        exit(EXIT_FAILURE);
    }

    do
    {
        ShowEntrance();
        DoSelected(phonebook,ChooseOption());
        printf("Press 1 to return to menu or other key to exit: ");
        scanf("%i",&numb);
        fseek(stdin,0,SEEK_END);
    }while(numb==1);


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


