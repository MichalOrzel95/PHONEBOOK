//
// Created by Eagle on 2017-06-27.
//

#ifndef PHONEBOOK_FILEHANDLING_H
#define PHONEBOOK_FILEHANDLING_H

void ShowAll(FILE *file);
void AddContact(FILE *file);
void RemovePerson(FILE *file);
void SearchPhonebook(FILE *file);
void ExportPerson(FILE *file);
void CountContacts(FILE *file);

#endif //PHONEBOOK_FILEHANDLING_H
