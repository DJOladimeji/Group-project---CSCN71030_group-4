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

#define NAMELENGTH 50 
#define PASSWORDLENGTH 8 


int main(void) {
    creatingDoctor();

    logIn(); 

	return 0; 
} 


void creatingDoctor() { 
    printf("writeToDoctorPatientFile\n\n");

    char name[NAMELENGTH] = "Gurjit"; 
    char tempName[NAMELENGTH]; 

    //printf("Enter first name and last name:\n");
    //scanf("%[^\n]", name, NAMELENGTH); 
    strcpy(tempName, name); 
    strcat(tempName, ".txt"); 
	FILE* fp1 = fopen(tempName, "w"); 


	fprintf(fp1, "%s", name); 
	printf("\nInformation written\n"); 

	fclose(fp1);  


    printf("\n\nwriteToLoginFile\n\n");

    char username[NAMELENGTH];
    int password = 0;

    printf("Now enter username(first name and last name without spaces):\n");
    scanf("%s", username, NAMELENGTH); 

    
    int alphabet = 1, number = 0, i;

    while (alphabet != 0 || number > 8) { 
        printf("\nEnter something:\n");
        char str[NAMELENGTH];
        scanf("%s", str);

        alphabet = 0, number = 0; 
        for (i = 0; str[i] != '\0'; i++)
        {

            // check for alphabets
            if (isalpha(str[i]) != 0)
                alphabet++;

            // check for decimal digits
            else if (isdigit(str[i]) != 0)
                number++;
        }

        printf("Alphabetic_letters = %d, "
            "Decimal_digits = %d\n",
            alphabet, number);
    } 


    FILE* fp2 = fopen("Login.txt", "a");

    if (fp2 == NULL) {
        perror("Unable to open file\n");
        exit(1);
    }

    fprintf(fp2, "%s %d\n", username, password); 
    printf("\nInformation written\n");

    fclose(fp2); 


    printf("\n\nwriteToHospitalFile\n\n"); 

    printf("Which hospital would you like to be placed in:\n\
        \r1) Hospital 1\n\
        \r2) Hospital 2\n\
        \r3) Hospital 3\n"); 

    int hospitalNumber; 
    scanf("%d", &hospitalNumber); 

    switch (hospitalNumber) { 
    case 1: {
        FILE* fp3 = fopen("Hospital1.txt", "a");

        if (fp3 == NULL) {
            perror("Unable to open file\n");
            exit(1);
        }

        fprintf(fp3, "%s\n", name); 
        printf("\nInformation written\n"); 

        fclose(fp3); 

        break;
    }
    case 2: {
        FILE* fp3 = fopen("Hospital2.txt", "a");

        if (fp3 == NULL) {
            perror("Unable to open file\n");
            exit(1);
        }

        fprintf(fp3, "%s\n", name); 
        printf("\nInformation written\n"); 

        fclose(fp3); 

        break;
    } 
    case 3: {
        FILE* fp3 = fopen("Hospital3.txt", "a");

        if (fp3 == NULL) {
            perror("Unable to open file\n");
            exit(1);
        }

        fprintf(fp3, "%s\n", name); 
        printf("\nInformation written\n"); 

        fclose(fp3); 

        break;
    }
    default: {
        printf("\nEnter correct number\n"); 
    }
    } 
}


void logIn() { 
    printf("Login\n");

    char username[NAMELENGTH], buffer[NAMELENGTH];
    int n, m, i, j, line; 

    FILE* fp = fopen("Login.txt", "r");

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

                addPatient(); 

                exit(1); 
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
} 


void addPatient() {
    printf("addPatient\n\n"); 


    //int i = 1; 
    //char charValue = i + '0'; 
    //printf("The character value is: %c\n", charValue); 

    char name[NAMELENGTH]; 
    char pastRecords[NAMELENGTH]; 

    printf("Enter first name and last name of patient:\n");
    scanf("%[^\n]", name, NAMELENGTH); 
    scanf("%[^\n]", name, NAMELENGTH); 
    printf("Enter any patient's past records:\n");
    scanf("%[^\n]", pastRecords, NAMELENGTH); 
    scanf("%[^\n]", pastRecords, NAMELENGTH); 

    FILE* fp4 = fopen("DoctorPatient.txt", "a");

    fprintf(fp4, "%s - Health Card # - Past records: %s\n", name, pastRecords); 
    printf("\nInformation written\n");

    fclose(fp4); 
}