#pragma once
#define HOSPITALSIZE 10
#define HOSPITAL1 1
#define HOSPITAL2 2
#define HOSPITAL3 3 
#include <stdio.h>
#include <stdbool.h>


bool Add_to_Hospital(char*, char* [HOSPITALSIZE]);
bool Delete_from_Hospital(char*, char* [HOSPITALSIZE]);
bool CheckforInsertion(char*, char* [HOSPITALSIZE]);
bool CheckforDeletion(char*, char* [HOSPITALSIZE], unsigned int*);
int Display_Population(char* [HOSPITALSIZE]);
char* getdocfilefromhospital(char*, char* [HOSPITALSIZE]);
void printhospital(char**);

