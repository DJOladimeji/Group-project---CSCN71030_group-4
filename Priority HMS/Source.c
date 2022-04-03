//CSCN71030 - Group 4 
//March 15th - 2022 
//Gurjit Singh

#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <math.h> 
#include <ctype.h> 
#include "Source.h" 
#include "Doctor.h"
#include "Patient.h"
#define PASS_LEN 10
#define NAMELENGTH 50 
#define PASSWORDLENGTH 8 

void writeDoctor(DOCTOR d, char* password, unsigned int hospitalchoice) {

    char tempName[NAMELENGTH];
    char firstname[NAMELENGTH] = {0};
    char* username = 0; 
    char* tp = 0; 
    char tempPassword[PASS_LEN+1] = { 0 }; 
    for (int i = 0; i < (strlen(d.firstname) +1); i++)
    {
        if (d.firstname != NULL) {
            firstname[i] = d.firstname[i];
        }
    }
    
    //makes doctor file name
    strcat(firstname, d.lastname); 
    strcat(firstname, ".txt");
    FILE* fp1 = fopen(firstname, "w");

    //writes to doctor file
    PrintDoctorToFile(fp1, d);
    printf("\nInformation written\n");
    fclose(fp1);


    strcpy(tempName, d.firstname);
    username = strcat(tempName, d.lastname);
   
    strcpy(tempPassword, password); 
    int length = strlen(tempPassword);
    char* allocatedpassword = (char*)malloc(length + 1); 
    if (allocatedpassword) {
        memset(allocatedpassword, 0, (length + 1));
        strcpy(allocatedpassword, tempPassword); 

    }
    int len = strlen(username);
    char* allocatedstring = (char*)malloc(len + 1);
    if (allocatedstring) {
        memset(allocatedstring, 0, (len + 1));
        strcpy(allocatedstring, username);  
        
    }

    FILE* fp2 = fopen("UserNames.txt", "a");

    if (fp2 == NULL) {
        perror("Unable to open file\n");
        exit(1);
    }
  
    fprintf(fp2, "%s %i\n", allocatedstring, hospitalchoice); 


    fclose(fp2);

    FILE* fp3 = fopen("Passwords.txt", "a");

    if (fp3 == NULL) {
        perror("Unable to open file\n");
        exit(1);
    }

    fprintf(fp3, "%s\n",allocatedpassword );   


    fclose(fp3);

    //while not end of file{
     //fscanf("%s %s, username,password) grab the username and password
     //ilyasyusuf 123234234123
    //}
    free(allocatedpassword);
    free(allocatedstring); 
}



//combine these two 
//check login file for usernames
int CheckUserName(char* username2) { 
    
    char username[NAMELENGTH], buffer[NAMELENGTH];
    int n, m, i, j, line; 

    FILE* fp = fopen("UserNames.txt", "r");

    if (fp == NULL) {
        perror("Unable to open file\n"); 
        exit(1); 
    } 

    printf("\nEnter username:\n"); 
    scanf_s("%s", username, NAMELENGTH); 

  
    m = strlen(username); 
    line = 0; 

    printf("\n"); 

    while (fgets(buffer, NAMELENGTH, fp) != NULL)
    {
        i = 0;
        n = strlen(buffer);

        while (i < n)
        {
            j = 0;
            while (i < n && j < m && buffer[i] == username[j])
            {
                ++i, ++j;
            }

            if ((i == n || buffer[i] == ' ' || buffer[i] == '\n') && j == m)
            {
                printf("Username is correct\n\n"); 
                strcpy(username2,username);  
                fclose(fp); 
                return 1;
            }  

            while (i < n && buffer[i] != ' ')
            {
                ++i;
            } 
            ++i;
        }
        ++line;
    }

    printf("Username is incorrect\n");

    fclose(fp); 
    return 0; 
}
//check password file for password
int CheckPassword(char* password2) {


    char password[NAMELENGTH], buffer[NAMELENGTH];
    int n, m, i, j, line;

    FILE* fp = fopen("Passwords.txt", "r");

    if (fp == NULL) {
        perror("Unable to open file\n");
        exit(1);
    }

    printf("\nEnter password:\n");
    scanf_s("%s", password, NAMELENGTH);


    m = strlen(password);
    line = 0;

    printf("\n");

    while (fgets(buffer, NAMELENGTH, fp) != NULL)
    {
        i = 0;
        n = strlen(buffer);

        while (i < n)
        {
            j = 0;
            while (i < n && j < m && buffer[i] == password[j])
            {
                ++i, ++j;
            }

            if ((i == n || buffer[i] == ' ' || buffer[i] == '\n') && j == m)
            {
                printf("Password is correct\n\n");
                strcpy(password2, password); 
                fclose(fp);
                return 1;
            }

            while (i < n && buffer[i] != ' ')
            {
                ++i;
            }
            ++i;
        }
        ++line;
    }

    printf("Password is incorrect\n");

    fclose(fp);
    return 0;
}


void addPatient(PATIENT pat, char* filename) { 
    FILE* fp = fopen(filename, "a"); 

    PrintPatientToFile(fp, pat);
    printf("\nInformation written\n");

    fclose(fp); 
}

void createstring(char* string)
{
    char input[MAXCHARACTER];
    if (fgets(input, MAXCHARACTER, stdin) != NULL) { 
        input[strlen(input) - 1] = '\0';
        strcpy(string, input); 
    }
}