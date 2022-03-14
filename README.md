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
Read_Hospital_File: The hospital module will have a function of void type that takes a file pointers as a parameter. The function will open that file, then fill the 2D array with its content. This function will be void type and will have no return. 

Save_to_Hospital_File: This function will be void type and take a file pointer as its parameter. The function will write each element of the 2D array line by line to the hospital text file.

Add_to_Hospital: This function will add the doctor in the current session to the hospital. This will add the doctor's full name and unique ID to the first column. Then add the number of patients they have to the second column as an unsigned integer. This function type will be the hospital structure that I will define. It will also return the 2D array after the changes were made.

Delete_From_Hospital: This function will remove the doctor in the current session to the hospital. It will find the information to be deleted by checking the strings in the first column of the array using the strstr function from the C standard library. This function type will be the hospital structure that I defined. It will also return the 2D array after the changes were made. It will take the hospital array structure and a string as its parameters. The string will be the name of the current doctor in session.

Check_Hospital: The purpose of this function is to check if the doctor in the current session is already have their information in the hospital. This is to prevent duplicate entries into the array and text files. It will iterate through the array and use strstr function to see if the current doctor has their name in the array. This function will be void type and return nothing. The parameters of the function is a hospital structure and a string. 

Display_Population: This function will print to the screen the number of doctors there are in the hospital as well as sum the total number of patients the whole hospital has. The purpose of this function is to aid the doctor in their choice of hospital because some doctors could make their choice based on the hospital population.  
