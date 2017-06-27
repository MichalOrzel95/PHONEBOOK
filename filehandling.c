//
// Created by Eagle on 2017-06-27.
//

#include <stdio.h>
#include "filehandling.h"

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

