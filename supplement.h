//
// Created by Michal Orzel on 2017-06-24.
//

#ifndef HANDLING_FILES_SUPPLEMENT_H
#define HANDLING_FILES_SUPPLEMENT_H

//Kind of system
#define SYSTEM LINUX
//Path to the phonebook
#define PHBPATH "/home/orzelm/PROGRAMMING/PHONEBOOK/phonebook.txt"
//Path to temp file(necessary to remove a person from phonebook)
#define TMPPATH "/home/orzelm/PROGRAMMING/PHONEBOOK/temp.txt"
//Path to a new file(necessary to remove a person from phonebook)
#define NEWPATH "/home/orzelm/PROGRAMMING/PHONEBOOK/newfile.txt"

//Functions' prototypes
void ShowEntrance(void);
char ChooseOption(void);
void DoSelected(FILE *file,char option_number);
int  CompareStrings(char *str1,char *str2);

#endif //HANDLING_FILES_SUPPLEMENT_H
