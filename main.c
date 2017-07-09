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
    char option_number;

    ShowEntrance();
    if((phonebook=fopen("/home/orzelm/PROGRAMMING/PHONEBOOK/phonebook.txt","a+"))==NULL)
    {
        printf("There was a problem with file!\n");
        printf("Closing program...");
        exit(EXIT_FAILURE);
    }

    option_number=ChooseOption();
    DoSelected(option_number,phonebook);

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


