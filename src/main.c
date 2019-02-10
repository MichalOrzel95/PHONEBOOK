//
// Created by Michal Orzel on 2017-06-24.
// Project of phone-library using files' handling in C
//

//Include files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "supplement.h"
#include "filehandling.h"

bool firstpassage;

//Main function
int main(void)
{
    FILE *phonebook,*logs;
    char sign;
    char option_number;
    time_t time_now;
    time(&time_now);
    firstpassage=true;

    if((logs=fopen(LOGPATH,"a+"))==NULL)
    {
        printf("Problem with a log-file!\n");
        printf("Closing program...");
        exit(EXIT_FAILURE);
    }

    fprintf(logs,"%s",ctime(&time_now));

    do
    {
        if((phonebook=fopen(PHBPATH,"a+"))==NULL)
        {
            printf("Problem with opening phonebook!\n");
            printf("Closing program...");
            exit(EXIT_FAILURE);
        }

        CLEAR_SCREEN;

        //Set file to beginning
        fseek(phonebook,0,SEEK_SET);

        ShowEntrance();
        DoSelected(phonebook,ChooseOption());
        firstpassage=false;
        printf("Press [r/R] to return to menu or other key to exit: ");
        scanf(" %c",&sign);
    }while(sign=='r' || sign=='R');

    return 0;
}//End of main
