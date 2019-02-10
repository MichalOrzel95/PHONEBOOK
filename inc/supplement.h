//
// Created by Michal Orzel on 2017-06-24.
//

#ifndef HANDLING_FILES_SUPPLEMENT_H
#define HANDLING_FILES_SUPPLEMENT_H

//Kind of system
// LINUX | WINDOWS
#define SYSTEM WINDOWS
//Path to the phonebook
#define PHBPATH "phonebook.txt"
//Path to temp file(necessary to remove a person from phonebook)
#define TMPPATH "temp.txt"
//Path to a new file(necessary to remove a person from phonebook)
#define NEWPATH "newfile.txt"
//Path to export-file
#define EXPPATH "export-file.txt"
//Path to log-file
#define LOGPATH "log.txt"

//Terminal commands
#if SYSTEM == LINUX
#define CLEAR_SCREEN    system("clear")
#endif

#if SYSTEM == WINDOWS
#define CLEAR_SCREEN    system("cls")
#endif

//Functions' prototypes
void ShowEntrance(void);
char ChooseOption(void);
void DoSelected(FILE *file,char option_number);
int  CompareStrings(char *str1,char *str2);
void CloseFile(FILE *file);

#endif //HANDLING_FILES_SUPPLEMENT_H
