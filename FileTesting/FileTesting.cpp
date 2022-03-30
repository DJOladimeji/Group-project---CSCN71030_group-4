#define _CRT_SECURE_NO_WARNINGS 

#include "pch.h"
#include "CppUnitTest.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <math.h> 
#include <ctype.h> 

#define NAMELENGTH 50 

extern "C" void creatingDoctor(); 
extern "C" void logIn(); 
extern "C" void addPatient(); 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileTesting
{
	TEST_CLASS(FileTesting)
	{
	public:
		
		TEST_METHOD(writingToDoctorPatientFile)
		{
			char name[NAMELENGTH] = "Gurjit"; 
			char tempName[NAMELENGTH]; 
			char c[NAMELENGTH];

			strcpy_s(tempName, name);
			strcat_s(tempName, ".txt");
			
			creatingDoctor(); 
			FILE* fp;
			fopen_s(&fp, tempName, "r");
			fgets(c, NAMELENGTH, fp);
			fclose(fp); 

			Assert::AreEqual(name, c); 
		} 
		TEST_METHOD(readingFromPatientFile)
		{
			char name[NAMELENGTH] = "Gurjit";
			char tempName[NAMELENGTH];
			char c[NAMELENGTH];

			strcpy_s(tempName, name);
			strcat_s(tempName, ".txt");

			creatingDoctor();
			FILE* fp;
			fopen_s(&fp, tempName, "r");
			fgets(c, NAMELENGTH, fp);
			fclose(fp);

			Assert::AreEqual(name, c); 
		}
	};
}
