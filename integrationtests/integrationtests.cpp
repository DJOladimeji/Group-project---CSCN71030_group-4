#include "pch.h"
#include "CppUnitTest.h"

extern "C"
{
#include "Doctor.h"
#include "Patient.h"
#include "Source.h"
#include "account.h"
#include "VS2022GHospitalModule.h" 
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace integrationtests
{
	TEST_CLASS(Files) 
	{
	public:
		
		TEST_METHOD(writingToDoctorPatientFile)
		{
			DOCTOR doc;
			strncpy_s(doc.firstname, MAXCHARACTER, "Gurjit", MAXCHARACTER);
			strncpy_s(doc.lastname, MAXCHARACTER, "Singh", MAXCHARACTER);
			strncpy_s(doc.department, MAXCHARACTER, "Surgery", MAXCHARACTER);
			doc.index = 0;
			unsigned int hpchoice = HOSPITAL1;
			char password[MAXCHARACTER] = { "abcdefg" }; //call craete passwordfunction 
			char expected[1000] = "Doctor: Gurjit Singh - Department: Surgery - Number of Patient = 0\n";

			char c[1000];

			writeDoctor(doc,password,hpchoice);  

			FILE* fp;
			fopen_s(&fp, "GurjitSingh.txt", "r");
			fgets(c, 1000, fp);
			
			fclose(fp);

			Assert::AreEqual(expected,c);  
		}
		
		/*
		TEST_METHOD(readingFromPatientFile)
		{
			PATIENT pat;
			strncpy_s(pat.firstname, MAXCHARACTER, "John", MAXCHARACTER);
			strncpy_s(pat.lastname, MAXCHARACTER, "Smith", MAXCHARACTER);
			pat.healthcardnumber = 123456;
			strncpy_s(pat.patientinfo, MAXCHARACTER, "Vin Diesel", MAXCHARACTER);

			char expected[MAXAMOUNTOFPATIENTINFO] = "John Smith - 123456";

			char c[MAXAMOUNTOFPATIENTINFO];
			
			addPatient(pat);

			FILE* fp;
			fopen_s(&fp, "DavidOladimeji.txt", "r");
			if (fp == NULL)
			{
				printf("Cannot open file\n");
			}

			fgets(c, MAXAMOUNTOFPATIENTINFO, fp);

			fclose(fp);

			Assert::AreEqual(expected, c);
		}
		*/
	};
	
	TEST_CLASS(Hospital)
	{
	public:

		//function test 
		TEST_METHOD(AddfiletohospitalPassTest)  //passed add test.
		{
			char* hospital[HOSPITALSIZE];
			char filename[MAXSTRINGLENGTH] = { "MichaelJordan.txt" };
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (hospital) {
					hospital[i] = (char*)malloc(MAXSTRINGLENGTH);
					if (hospital[i]) {
						memset(hospital[i], 0, MAXSTRINGLENGTH);
					}
				}
			}
			unsigned int choice = HOSPITAL1;
			hospitalstub(hospital);
			Add_to_Hospital(filename, hospital);
			Assert::AreEqual(filename, hospital[3]);
		}
		//function test 
		TEST_METHOD(AddfiletohospitalFailTest)  //passed add test.
		{
			char* hospital[HOSPITALSIZE];
			char filename[MAXSTRINGLENGTH] = { "IlyasYusuf.txt" };
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (hospital) {
					hospital[i] = (char*)malloc(MAXSTRINGLENGTH);
					if (hospital[i]) {
						memset(hospital[i], 0, MAXSTRINGLENGTH);
					}
				}
			}
			unsigned int choice = HOSPITAL1;
			hospitalstub(hospital);
			bool isAdded = Add_to_Hospital(filename, hospital);
			Assert::IsFalse(isAdded);
		}
		//function test 
		TEST_METHOD(DeletefiletohospitalPassTest)  //passed delete test.
		{
			char* hospital[HOSPITALSIZE];
			char filename[MAXSTRINGLENGTH] = { "IlyasYusuf.txt" };
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (hospital) {
					hospital[i] = (char*)malloc(MAXSTRINGLENGTH);
					if (hospital[i]) {
						memset(hospital[i], 0, MAXSTRINGLENGTH);
					}
				}
			}
			unsigned int choice = HOSPITAL1;
			hospitalstub(hospital);
			Delete_from_Hospital(filename, hospital);
			Assert::AreEqual("", hospital[3]);
		}
		TEST_METHOD(DeletefiletohospitalFailTest)  //passed add test.
		{
			char* hospital[HOSPITALSIZE];
			char filename[MAXSTRINGLENGTH] = { "MichaelJordan.txt" };
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (hospital) {
					hospital[i] = (char*)malloc(MAXSTRINGLENGTH);
					if (hospital[i]) {
						memset(hospital[i], 0, MAXSTRINGLENGTH);
					}
				}
			}
			unsigned int choice = HOSPITAL1;
			hospitalstub(hospital);
			bool isDeleted = Delete_from_Hospital(filename, hospital);
			Assert::IsFalse(isDeleted);
		}
		//function test 	
		TEST_METHOD(DisplayPopulationTest) //successful display population test.
		{
			char* hospital[HOSPITALSIZE];
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (hospital) {
					hospital[i] = (char*)malloc(MAXSTRINGLENGTH);
					if (hospital[i]) {
						memset(hospital[i], 0, MAXSTRINGLENGTH);
					}
				}
			}
			unsigned int choice = HOSPITAL1;
			hospitalstub(hospital);
			int pop = HospitalPopulation(hospital); 
			Assert::AreEqual(3, pop);
		}
	};

	TEST_CLASS(integrationtests)
	{
	public:
		//integration test
		TEST_METHOD(AddUsertohospitalPassTest)  //passed add test.
		{
			char* hospital[HOSPITALSIZE];
			char username[MAXSTRINGLENGTH] = { "MichaelJordan" };
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (hospital) {
					hospital[i] = (char*)malloc(MAXSTRINGLENGTH);
					if (hospital[i]) {
						memset(hospital[i], 0, MAXSTRINGLENGTH);
					}
				}
			}
			unsigned int choice = HOSPITAL1;
			bool isAdded = addUsertohospital(username, hospital, choice);
			Assert::IsTrue(isAdded);
		}
		//integration test
		TEST_METHOD(AddUsertohospitalFailTest)  //failed add test.
		{
			char* hospital[HOSPITALSIZE];
			char username[MAXSTRINGLENGTH] = { "IlyasYusuf" };
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (hospital) {
					hospital[i] = (char*)malloc(MAXSTRINGLENGTH);
					if (hospital[i]) {
						memset(hospital[i], 0, MAXSTRINGLENGTH);
					}
				}
			}
			unsigned int choice = HOSPITAL1;
			hospitalstub(hospital);
			bool isAdded = addUsertohospital(username, hospital, choice);
			Assert::IsFalse(isAdded);
		}
		//integration test
		TEST_METHOD(DeletefilefromhospitalPassTest) //passed delete test.
		{
			char* hospital[HOSPITALSIZE] = { 0 };
			char username[MAXSTRINGLENGTH] = { "IlyasYusuf" };
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (hospital) {
					hospital[i] = (char*)malloc(MAXSTRINGLENGTH);
					if (hospital[i]) {
						memset(hospital[i], 0, MAXSTRINGLENGTH);
					}
				}
			}
			unsigned int choice = HOSPITAL1;
			//This stub does not contain the filename.
			hospitalstub(hospital);
			//Should return false because the file is not in the hospital.
			bool isDeleted = deleteUserfromhospital(username, hospital, choice);
			Assert::IsTrue(isDeleted);
		}
		//integration test
		TEST_METHOD(DeletefilefromhospitalFailTest) //Failed delete test. 
		{
			char* hospital[HOSPITALSIZE] = { 0 };
			char username[MAXSTRINGLENGTH] = { "LarryBird" };
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (hospital) {
					hospital[i] = (char*)malloc(MAXSTRINGLENGTH);
					if (hospital[i]) {
						memset(hospital[i], 0, MAXSTRINGLENGTH);
					}
				}
			}
			unsigned int choice = HOSPITAL1;
			//This stub does not contain the filename.
			hospitalstub(hospital);
			//Should return false because the file is not in the hospital.
			bool isDeleted = deleteUserfromhospital(username, hospital, choice);
			Assert::IsFalse(isDeleted);
		}
		//integration test
		TEST_METHOD(getdocfilefromhospitalPassTest)  //successful getdocfile test after adding the file to the hospital
		{
			char* hospital[HOSPITALSIZE];
			char username[MAXSTRINGLENGTH] = { "IlyasYusuf" };
			char filename[MAXSTRINGLENGTH] = { "IlyasYusuf.txt" };
			char* fp = filename;
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (hospital) {
					hospital[i] = (char*)malloc(MAXSTRINGLENGTH);
					if (hospital[i]) {
						memset(hospital[i], 0, MAXSTRINGLENGTH);
					}
				}
			}
			unsigned int choice = HOSPITAL1;
			hospitalstub(hospital);
			char* result = NULL;
			result = getdocfilefromhospital(username, hospital);
			Assert::AreEqual(filename, result);

		}

		// test for logging in
		/*
		TEST_METHOD(AfterLoginChoice1Test)  //testing user choice 1: Adding Patient;
		{
			
			char username[MAXSTRINGLENGTH] = { "IlyasYusuf" };
			char filename[MAXSTRINGLENGTH] = { "IlyasYusuf.txt" };
			//char* fp = filename;
			char result[MAXCHARACTER] = {0}; 
			unsigned int choice = HOSPITAL1; 
			PATIENT patient1;
			patient1 = { "Kobe","Bryant",2408, "Feeling sad" }; 
			DOCTOR doc1,doc2; 
			strncpy_s(doc1.firstname, MAXCHARACTER, "Ilyas", MAXCHARACTER);
			strncpy_s(doc1.lastname, MAXCHARACTER, "Yusuf", MAXCHARACTER);
			strncpy_s(doc1.department, MAXCHARACTER, "Surgery", MAXCHARACTER);
			doc1.index = 0; 
			doc2 = doc1; 
			doc2.patient[1] = &patient1;  
			doc2.index = 1;  
			doc1 = addPatienttoDoctor(doc1, patient1, username);   
			Assert::AreEqual(doc2, doc1); 
		

		}
		*/
		TEST_METHOD(CheckUserNameTest)
		{ 
			char username[MAXSTRINGLENGTH] = { "IlyasYusuf" };
			char* searchname;
			int result = CheckUserName(username, searchname);  
			Assert::AreEqual(1, result); 

		}
		TEST_METHOD(PasswordGeneratorTest)  
		{
			char password1[11] = { 0 };
			srand(time(0));
			strcpy_s(password1,11 ,createpassword());   
			char password2[11] = { "jyuhvbfvbh"};
			
			Assert::AreNotEqual(password1, password2);   

		}
		
		TEST_METHOD(SwitchHospitalTest)  //testing user choice 3: Switch Hospital;  
		{
			char* hospital[HOSPITALSIZE];
			char* hospital2[HOSPITALSIZE];
			char username[MAXSTRINGLENGTH] = { "IlyasYusuf" };
			char filename[MAXSTRINGLENGTH] = { "IlyasYusuf.txt" };
			char* fp = filename;
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (hospital) {
					hospital[i] = (char*)malloc(MAXSTRINGLENGTH);
					if (hospital[i]) {
						memset(hospital[i], 0, MAXSTRINGLENGTH);
					}
				}
			}
			for (int i = 0; i < HOSPITALSIZE; i++) {
				if (hospital2) { 
					hospital2[i] = (char*)malloc(MAXSTRINGLENGTH);
					if (hospital2[i]) { 
						memset(hospital2[i], 0, MAXSTRINGLENGTH); 
					}
				}
			}
			unsigned int choice1 = HOSPITAL1;
			unsigned int choice2 = HOSPITAL2;
			hospitalstub(hospital);
			switchhospital(username, hospital, choice1, hospital2, choice2); 
			char* result = NULL;
			Assert::AreEqual(filename, hospital2[0]); 
		}
		
	};
	
}
