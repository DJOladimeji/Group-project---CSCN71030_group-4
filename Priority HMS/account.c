#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "account.h"

int signUp(char* userName, /*char* firstname, char* lastname, */char* hospitalArray[MAX_HOSP_SIZE]) {
	// Open registry file
	FILE* fp = NULL;
	fopen_s(fp, "registry.txt", "r");

	// Search for username
	char currLine[MAX_STR_LEN] = "";
	bool usernameFound = false;
	while (*currLine != EOF) {
		fgets(currLine, MAX_STR_LEN, fp);
		if (currLine == userName) {
			usernameFound = true;
			*currLine = EOF;
		}
	}

	// Check availability
	if (usernameFound) {
		printf("Username already exists\n");
		fclose(fp);
		return EXIT_FAILURE;
	}
	printf("Username available\n");

	// Close registry file
	fclose(fp);

	// Get hospital choice from user
	//printf("Enter hospital name: ");
	printf("Enter a number to choose a hospital (1,2,3): ");
	unsigned int hospitalChoice = 0;
	scanf_s(hospitalChoice, "%i", sizeof(unsigned int));

	// Create A doctor
	// Create new doctor file (gurjit)

	// Add doctor filename to hospital (ilyas)

	// Generate password
	char userPass[PASS_LEN] = "";
	userPass[PASS_LEN - 1] = '\0';

	srand(time(0));
	for (int i = 0; userPass[i] != '\0'; i++) {
		userPass[i] = rand() % 26 + 'a';
	}

	// Store username and password in registry file
	fopen_s(fp, "registry.txt", "r");
	char userInfo[MAX_STR_LEN] = "";
	strcat_s(userInfo, MAX_STR_LEN, userName);
	strcat_s(userInfo, MAX_STR_LEN, " ");
	strcat_s(userInfo, MAX_STR_LEN, userPass);
	strcat_s(userInfo, MAX_STR_LEN, "\n");
	fputs(userInfo, fp);
	fclose(fp);

	printf("%s\n", userPass);

	return EXIT_SUCCESS;
}

int logIn(char* username, char* password) {
	// Open registry file
	FILE* fp = NULL;
	fopen_s(fp, "registry.txt", "r");

	// Search for username
	char currLine[MAX_STR_LEN] = "";
	bool usernameFound = false;
	char* foundUsername = NULL;
	while (*currLine != EOF) {
		fgets(currLine, MAX_STR_LEN, fp);
		if (currLine == username) {
			usernameFound = true;
			foundUsername = username;
			*currLine = EOF;
		}
	}

	// Verify login
	if (!usernameFound) {
		printf("Username not found");
		return EXIT_FAILURE;
	}
	if (username != foundUsername) {
		printf("Incorrect password");
		return EXIT_FAILURE;
	}
	printf("File found");

	// Get information and hold on to it

	// Close registry file
	fclose(fp);

	// Open doctor file
	// Read from held information to doctor object (using gurjit's module)
	// Close doctor file
	
	// Modification menu
	bool menuOpen = true;
	while (menuOpen = true) {
		char userchoice = ' ';
		printf("How do you want to proceed?\n");
		printf("a. Modify object\n");	// placeholder: will call davids functions to modify the object
		printf("q. Quit\n");			// then will call gurjit's module to save modification to doctor file
		printf("\n >> ");
		scanf_s(userchoice, "%c", sizeof(char));
		printf("\n");

		if (userchoice == 'a') {
			// Modify object (david)
		}
		if (userchoice == 'q') {
			menuOpen = false;
		}
	}
	
	// Open doctor file
	// Write from object to doctor file
	// Close doctor file
	
	// Open hospital file
	fopen_s(fp, "registry.txt", "w");
	// Modify doctor filename	// call ilyas' module & gurjit's module
	// If User wants to delete account
		// Delete doctor file
		// Remove doctor file from hospital
	// Close hospital file (done by ilyas' module automatically)
	fclose(fp);

	return EXIT_SUCCESS;
}