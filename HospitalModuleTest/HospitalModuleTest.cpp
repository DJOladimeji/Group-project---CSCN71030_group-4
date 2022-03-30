
#include "pch.h"
#include "CppUnitTest.h"

extern "C" {

#include "HospitalModule.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{

	TEST_CLASS(UnitTest1)
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
			int pop = Display_Population(hospital);
			Assert::AreEqual(3, pop);
		}
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
	};
}
