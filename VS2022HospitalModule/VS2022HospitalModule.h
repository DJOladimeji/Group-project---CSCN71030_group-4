#pragma once
#pragma once
#define MAXSTRINGLENGTH 50 
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
int HospitalPopulation(char* [HOSPITALSIZE]);
char* getdocfilefromhospital(char*, char* [HOSPITALSIZE]);

bool addUsertohospital(char*, char* [HOSPITALSIZE], unsigned int);
bool deleteUserfromhospital(char*, char* [HOSPITALSIZE], unsigned int);
bool readdocfilefromhospital(char*, char* [HOSPITALSIZE]);
void hospitalstub(char* [HOSPITALSIZE]);
void doctorstub();
void createstring(char*);