# Group-project---CSCN71030_group-4
place where function names will be placed 

David Oladimeji: 

CreateDoctor: This function will take in three char arrays, one for the doctors first
name, last name, and department. it will create a doctor using the doctor structure,
and will then return this data package as a Doctor.

PrintDoctor: This function will take in a doctor(first name, last name, departent), and
will print it out to the screen, using a printf fucntion. it will have no return value.

PrintDoctorToFile: This function will take in a doctor(first name, last name,
department), and will print the information to a file using fprintf. It will have not return
value.

CreatePatient: This fucntion will take in four char arrays, one for the patient's first
name, last name, health card info, and medical information. it will create a patient
using the patient structure, and will then return this data package as a patient.

PrintPatient: This fuction will take in a patient(first name, last name, health card info, mediacl infromation), and will print it out to the screen, using a printf fucntion. it will have no return value.

PrintPatientToFile: This function will take in a patient(first name, last name,
health card info, medical infromation), and will print the information to a file using fprintf. It will have not return value. 


Gurjit Singh: 

A function called displaySpecificInfo() will display a specific patient's, doctor's, or hospital's information without taking any input parameters and having a return type void. The function will open the doctor/patient file or the hospital file and read the specific information and print it. 

A function called deleteDoctor() with no input parameters and void return type will ask for the doctor name and will delete the doctor/patient file under that name. It will also delete the name of that doctor and their number of patients from the hospital file. 

Another function called deletePatient() with no input parameters and void return type will ask for the patient name or health card number and will delete that patient's information from the doctor/patient file and will decrease the number of patients of the doctor the patient was under from the hospital file. 

Then, a function called updateInfo() with no input parameters and void return type will ask for the doctor's or patient's information whose personal information is to be changed and will open the doctor/patient file according to that person which will be updated with new information. 

Ilyas Yusuf

Read_Hospital_File: The hospital module will have a function of void type that takes an array of char pointers, and an unsigned int as parameters. The function will use the unsigned int to choose which hospital file to open. Then it will fill the 2D array with its content. This function will be void type and will have no return. 

Save_to_Hospital_File: This function will be void type and takes an array of char pointers, and an unsigned int as parameters. The function will use the unsigned int to choose which hospital file to open. The function will write each element of the 2D array line by line to the hospital text file.

Add_to_Hospital: This function will add the doctor file name to a hospital. The function type will be boolean. It will return true if it successfully adds the filename to the hospital, and false if it doesn't. The function parameters are the hospital file name that is to be added, the hospital array, and t

Delete_from_Hospital: This function will delete the doctor file name from a hospital. The function type will be boolean. It will return true if it successfully deletes the file name from the hospital, and false if it doesn't.

CheckforInsertion: The purpose of this function is to check if the doctor in the current session is already have their file in the hospital. This is to prevent duplicate entries into the array and hospital text files. It will iterate through the array and use strcmp function to see if the current doctor has their name in the array. This function will be boolean type and return true if a duplicate is found, and false if not. The parameters of the function is a hospital array and the string of the file name to be added. 

CheckforDeletion: The purpose of this function is to check if the doctor file name is in the hospital so it can be deleted. This is to ensure that a file can only be deleted from a hospital if it's actually in that hospital. It will iterate through the array and use strcmp function to see if the current doctor has their name in the array. This function will be boolean type and return true if the file name is found, and false if not. The parameters of the function is a hospital array, an unsigned int pointer for the index of file to be deleted and the string of the file name to be added.

HospitalPopulation: This function will return the number of file names there are in the hospital. The purpose of this function is to aid the doctor in their choice of hospital because some doctors could make their choice based on the hospital population.  

Max Dabski:

signUp: This will take in username and password parameters in the form of separate char pointers. It will use the parameters to create a new doctor file after verifying with the registry file that one with a matching username does not already exist. It will also add the doctor to a user-specified hospital's file. It will return 1 if unsuccessful and 0 if successful.

logIn: This will take in username and password parameters in the form of separate char pointers. It will use the parameters to load data from an existing doctor file into a doctor object after verifying with the registry file that the given username and password match those of an existing account. It will also allow the user to modify the information in the doctor account via a text-based interface, modifying doctor and hospital files accordingly. It will return 1 if unsuccessful and 0 if successful.
