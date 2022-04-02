#pragma once

#define MAX_HOSP_LEN 50
#define MAX_HOSP_SIZE 10
#define MAX_STR_LEN 50
#define PASS_LEN 10

char* createpassword();
//int logIn(char*, char*,char*[MAX_HOSP_SIZE]);
void AfterLoginWindow(char*[MAX_HOSP_SIZE], char*, char* ,unsigned int); 

bool deleteUserName(char*, char*[30], unsigned int[30]);
bool Delete_from_Usernames(char*, char* [30]);
bool CheckUserNameforDeletion(char*, char*[30], unsigned int*);
void Save_UserNames_File(char*[30], unsigned int[30]);
bool deletePasswords(char*, char* [30]); 
bool Delete_from_Password(char*,char* [30]);
bool CheckPasswordforDeletion(char*, char*[30], unsigned int*);
void Save_Password_File(char*[30]);
void Read_UserNames_File(char*[30], unsigned int[30]);
void Read_Passwords_File(char* [30]);