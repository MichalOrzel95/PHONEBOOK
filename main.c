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
    char option_number;
    ShowEntrance();
    option_number=ChooseOption();
    DoSelected(option_number);

    return 0;
}//End of main


