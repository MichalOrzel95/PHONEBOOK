//
// Created by Michal Orzel on 2017-06-24.
//

#ifndef HANDLING_FILES_SUPPLEMENT_H
#define HANDLING_FILES_SUPPLEMENT_H

//Kind of system
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
#define CLEAR_SCREEN    printf("\x1b[2J")
#define CURSOR_HOME     printf("\x1b[;H")


//Functions' prototypes
void ShowEntrance(void);
char ChooseOption(void);
void DoSelected(FILE *file,char option_number);
int  CompareStrings(char *str1,char *str2);
void CloseFile(FILE *file);

#endif //HANDLING_FILES_SUPPLEMENT_H
