#include "pch.h"
#include "CppUnitTest.h"
extern "C"
{
#include "../Priority HMS/Doctor.h"
#include "../Priority HMS/Patient.h"
}

#define _CRT_SECURE_NO_WARNINGS

  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoctorModuleUnitTest
{
	TEST_CLASS(DoctorandPatientModuleUnitTest)
	{
	public:
		
		TEST_METHOD(Testthecreationofdoctor)//testing to see of doctors is actually create when the CreateDocotr() function is called
		{
			char firstname[MAXCHARACTER] = "David";
			char lastname[MAXCHARACTER] = "Oladimeji";
			char department[MAXCHARACTER] = "Clinic";

			DOCTOR expected;
			strncpy_s(expected.firstname, MAXCHARACTER, "David", MAXCHARACTER);
			strncpy_s(expected.lastname, MAXCHARACTER, "Oladimeji", MAXCHARACTER);
			strncpy_s(expected.department, MAXCHARACTER, "Clinic", MAXCHARACTER);
			expected.index = 0;


			DOCTOR actual = CreateDoctor(firstname, lastname, department); 
			Assert::AreEqual(expected.firstname, actual.firstname);
			Assert::AreEqual(expected.lastname, actual.lastname);
			Assert::AreEqual(expected.department, actual.department);
			Assert::AreEqual(expected.index, actual.index);
		}

		TEST_METHOD(Testtoprintdoctortofile) // this test is to test to see of the doctors information is print the the ASCII text file
		{

			char First[MAXCHARACTER] = "David";
			char Last[MAXCHARACTER] = "Oladimeji";
			char department[MAXCHARACTER] = "Clinic";

			DOCTOR actual;
			strncpy_s(actual.firstname, MAXCHARACTER, First, MAXCHARACTER);
			strncpy_s(actual.lastname, MAXCHARACTER, Last, MAXCHARACTER);
			strncpy_s(actual.department, MAXCHARACTER, department, MAXCHARACTER);
			actual.index = 0;

			FILE* fp;
			fopen_s(&fp, "testText.txt", "w");
			if (fp == NULL)
			{
				printf("error\n");
			}

			PrintDoctorToFile(fp, actual);

			fclose(fp);

			//*****************************************************************************************
			char expected[] = "David Oladimeji Clinic";
			//*****************************************************************************************

			FILE* secondfp;
			fopen_s(&secondfp, "testText.txt", "r");
			if (secondfp == NULL)
			{
				printf("error\n");
			}

			char wrd[MAXCHARACTER], buffer[MAXCHARACTER];
			int n, m, i, j, line;
			int isthere = 0;

			m = strlen(expected);

			line = 0;

			while (fgets(buffer, MAXCHARACTER, secondfp) != NULL)
			{
				i = 0;
				n = strlen(buffer);

				while (i < n)
				{
					j = 0;
					while (i < n && j < m && buffer[i] == expected[j])
					{
						++i, ++j;
					}

					if ((i == n || buffer[i] == ' ' || buffer[i] == '\n') && j == m)
					{
						isthere++;
					}

					while (i < n && buffer[i] != ' ')
					{
						++i;
					}
					++i;
				}

				++line;
			}

			fclose(secondfp);

			Assert::AreEqual(1, isthere);
		}

		TEST_METHOD(Testthecreationofpatient)
		{
			char fname[MAXCHARACTER] = "John";
			char lname[MAXCHARACTER] = "Mark";
			int healthcard = 123456;
			char medicalinfromation [MAXCHARACTER] = "Covid19";

			PATIENT expected;
			strncpy_s(expected.firstname, MAXCHARACTER, "John", MAXCHARACTER);
			strncpy_s(expected.lastname, MAXCHARACTER, "Mark", MAXCHARACTER);
			expected.healthcardnumber = 123456;
			strncpy_s(expected.patientinfo, MAXCHARACTER, "Covid19", MAXCHARACTER);


			PATIENT actual = CreatePatient(fname, lname, healthcard, medicalinfromation);
			Assert::AreEqual(expected.firstname, actual.firstname);
			Assert::AreEqual(expected.lastname, actual.lastname);
			Assert::AreEqual(expected.healthcardnumber, actual.healthcardnumber);
			Assert::AreEqual(expected.patientinfo, actual.patientinfo);	
		}

		TEST_METHOD(Testifpatientisaddedtodocotor) //this test is to see if the patient is added to the doctor
		{
			DOCTOR doc;
			strncpy_s(doc.firstname, MAXCHARACTER, "David", MAXCHARACTER);
			strncpy_s(doc.lastname, MAXCHARACTER, "Oladimeji", MAXCHARACTER);
			strncpy_s(doc.department, MAXCHARACTER, "Clinic", MAXCHARACTER);
			doc.index = 0;

			PATIENT pat;
			strncpy_s(pat.firstname, MAXCHARACTER, "John", MAXCHARACTER);
			strncpy_s(pat.lastname, MAXCHARACTER, "Mark", MAXCHARACTER);
			pat.healthcardnumber = 123456;
			strncpy_s(pat.patientinfo, MAXCHARACTER, "Covid19", MAXCHARACTER);

			DOCTOR actual;
			actual = addPatienttoDoctor(doc, pat);

			Assert::AreEqual(1, actual.index);
			Assert::AreEqual(actual .patient[0]->firstname, pat.firstname);
			Assert::AreEqual(actual.patient[0]->lastname, "Mark");
			Assert::AreEqual(actual.patient[0]->healthcardnumber, 123456);
			Assert::AreEqual(actual.patient[0]->patientinfo, "Covid19"); 
		}

		TEST_METHOD(TestPatientprintingtofile) //testing to see if the patient's infromation will print to the file 
		{
			PATIENT actual;
			strncpy_s(actual.firstname, MAXCHARACTER, "John", MAXCHARACTER);
			strncpy_s(actual.lastname, MAXCHARACTER, "Mark", MAXCHARACTER);
			actual.healthcardnumber = 123456;
			strncpy_s(actual.patientinfo, MAXCHARACTER, "Covid19", MAXCHARACTER);

			FILE* fp;
			fopen_s(&fp, "patinetToFile.txt", "w");
			if (fp == NULL)
			{
				printf("error\n");
			}

			PrintPatientToFile(fp, actual); 

			fclose(fp);


			//**********************************************************
			char expected[MAXCHARACTER] = "Patient: John Mark - 123456";
			//**********************************************************

			FILE* secondfp;
			fopen_s(&secondfp, "patinetToFile.txt", "r");
			if (secondfp == NULL)
			{
				printf("error\n");
			}

			char wrd[MAXCHARACTER], buffer[MAXCHARACTER];
			int n, m, i, j, line;
			int isthere = 0;

			m = strlen(expected);

			line = 0;

			while (fgets(buffer, MAXCHARACTER, secondfp) != NULL)
			{
				i = 0;
				n = strlen(buffer);

				while (i < n)
				{
					j = 0;
					while (i < n && j < m && buffer[i] == expected[j])
					{
						++i, ++j;
					}

					if ((i == n || buffer[i] == ' ' || buffer[i] == '\n') && j == m)
					{
						isthere++;
					}

					while (i < n && buffer[i] != ' ')
					{
						++i;
					}
					++i;
				}

				++line;
			}

			fclose(secondfp);

			Assert::AreEqual(1, isthere); 
		}
	};
}
