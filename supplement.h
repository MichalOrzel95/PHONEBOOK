//
// Created by Michal Orzel on 2017-06-24.
//

#ifndef HANDLING_FILES_SUPPLEMENT_H
#define HANDLING_FILES_SUPPLEMENT_H

//Preprocessor commands
#define SYSTEM LINUX

//Functions' prototypes
void ShowEntrance(void);
char ChooseOption(void);
void DoSelected(char number,FILE *file);
int  CompareStrings(char *str1,char *str2);

#endif //HANDLING_FILES_SUPPLEMENT_H
