//====================================================================
//Title: Edges C final project
//Description: This program implements a linked list to manage student data.
//Author: Ahmed Basem
//====================================================================

#ifndef STUDENT_MANAGEMENT_SYSTEM_H_
#define STUDENT_MANAGEMENT_SYSTEM_H_


//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//====================================================================
//typedefs
typedef struct student s;
typedef struct node n;
//====================================================================
// Further description is provided in the "Functions definitions" section.

// Function prototypes

// Displays a personal introduction message (e.g., developer info, program name)
void personal_intro(void);

// Displays the main menu options for user interaction
void main_menu(void);

// Adds a new student record to the system using the provided student struct pointer
void addStudent(s *ptr);

// Displays the list of all stored student records
void displayStudents(void);

// Searches for a student by their ID and displays their record if found
void searchStudentByID(int id);

// Updates the information of an existing student with the given ID
void updateStudent(int id);

// Deletes a student record with the specified ID from the system
void deleteStudent(int id);

// Calculates and returns the average GPA of all students
float calculateAverageGPA(void);

// Finds and displays the student(s) with the highest GPA in the system
void searchHighestGPA(void);

// Creates a new node in a linked list with the given student data and returns the updated list
n* create_node(n *head, const s *ptr);
//====================================================================
//structures
struct student {
	char name[50];
	float GPA;
	int ID;
	int Age;
};
struct node {
	s data; //data type struct sd
	struct node *next; //pointer to structure
};
//====================================================================
//Global declarations
n *head = NULL;
int ID = 0;
float avg = 0;

#endif /* STUDENT_MANAGEMENT_SYSTEM_H_ */
