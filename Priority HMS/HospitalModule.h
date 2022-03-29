#pragma once
#define HOSPITALSIZE 10
#include <stdio.h>
#include <stdbool.h>


bool Add_to_Hospital(char*, char* [HOSPITALSIZE], unsigned int);
bool Delete_from_Hospital(char*, char* [HOSPITALSIZE], unsigned int);
bool Check_Hospital(char*, char* [HOSPITALSIZE], unsigned int*);
int Display_Population(char* [HOSPITALSIZE]);
char* getdocfilefromhospital(char*, char* [HOSPITALSIZE]);
void printhospital(char**);

