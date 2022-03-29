#pragma once
#include <stdio.h>
#include <stdbool.h>


bool Add_to_Hospital(char*, char* [10], unsigned int);
bool Delete_from_Hospital(char*, char* [10], unsigned int);
bool Check_Hospital(char*, char* [10], unsigned int*);
int Display_Population(char* [10]);
char* getdocfilefromhospital(char*, char* [10]);
void printhospital(char**);

