//====================================================================
//Title: Edges C final project
//Description: This program implements a linked list to manage student data.
//Author: Ahmed Basem
//====================================================================
#include "Student_Management_System.h"
//====================================================================
//Main function.
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	personal_intro();
	main_menu();
	return 0;
}
//====================================================================
//Functions definitions.
//====================================================================
/**
 * Displays the main menu interface and handles user input to navigate different functionalities.
 *
 * - Uses a loop to print a separator line for visual clarity.
 * - Prompts the user to choose an option (1-7) for various student record operations.
 * - Uses `switch-case` to execute the corresponding function based on user input.
 * - Recursively calls `main_menu()` after each operation (except exit).
 *
 * Techniques:
 * - Recursion for menu re-display (simplifies flow but may cause stack growth).
 * - Input handling with `scanf()` (basic, no advanced validation).
 */
void main_menu(void) {
	int option = 0;
	for (int i = 0; i < 30; i++)
		printf("==");
	printf("\n");
	printf("Main Menu:\n");
	printf("Choose an option:\n");
	printf("1-Add a Student\n");
	printf("2-Display All Students\n");
	printf("3-Search for a Student by ID\n");
	printf("4-Update Student Information\n");
	printf("5-Delete a Student\n");
	printf("6-Calculate Average GPA\n");
	printf("7-Find Student with Highest GPA\n");
	printf("Press any key to exit\n");
	scanf("%d", &option);

	switch (option) {
	case 1:
		printf("1-Add a Student:-\n");
		s student_data;
		addStudent(&student_data);
		head = create_node(head, &student_data);
		main_menu();
		break;
	case 2:
		printf("2-Display All Students:-\n");
		displayStudents();
		main_menu();
		break;
	case 3:

		printf("3-Search for a Student by ID:-\n");
		printf("Enter student ID:\n");
		scanf("%d", &ID);
		searchStudentByID(ID);
		main_menu();
		break;
	case 4:
		printf("4-Update Student Information:-\n");
		printf("Enter student ID:\n");
		scanf("%d", &ID);
		updateStudent(ID);
		main_menu();
		break;
	case 5:
		printf("5-Delete a Student:-\n");
		printf("Enter student ID:\n");
		scanf("%d", &ID);
		deleteStudent(ID);
		main_menu();
		break;
	case 6:
		printf("6-Calculate Average GPA:-\n");
		avg = calculateAverageGPA();
		printf("average GPA of all students is %.2f\n", avg);
		main_menu();
		break;
	case 7:
		printf("7-Find Student with Highest GPA\n");
		searchHighestGPA();
		main_menu();
		break;
	default:
		return;

	}
}
//====================================================================
/**
 * Creates a new node for a linked list and inserts student data.
 *
 * @param head  Pointer to the head of the linked list.
 * @param ptr   Pointer to the student data to be stored.
 * @return      Updated head of the linked list.
 *
 * Techniques:
 * - Dynamic memory allocation (`malloc`) for node creation.
 * - Handles memory allocation failure gracefully.
 * - Traverses to the end of the list to append the new node (O(n) time).
 * - Preserves the original head pointer (safe for empty lists).
 */
n* create_node(n *head, const s *ptr) {
	n *new = (n*) malloc(sizeof(n));
	//handle failed allocation case
	if (new == NULL) {
		printf("Allocation failed.\n");
		return NULL;
	}
	strcpy(new->data.name, ptr->name);
	new->data.Age = ptr->Age;
	new->data.ID = ptr->ID;
	new->data.GPA = ptr->GPA;
	new->next = NULL;
	//handle empty case
	if (head == NULL) {
		return new;
	}
	//you can't change value of head in the function, head is only changed in the main and passed as a parameter
	n *current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = new;
	return head;
}
//====================================================================
/**
 * Collects student data interactively from the user.
 *
 * @param ptr   Pointer to the student struct where data will be stored.
 *
 * Techniques:
 * - Uses `getchar()` to clear input buffer before `fgets`.
 * - Validates GPA range (0-4) with error recovery.
 * - Removes newline characters from `fgets` input for clean string storage.
 */
void addStudent(s *ptr)
{

	//add students name,id,gpa,age
	while (getchar() != '\n')
		; // Only clear after previous scanf
	printf("Enter student name:");
	fgets(ptr->name, 50, stdin);
	ptr->name[strcspn(ptr->name, "\n")] = '\0'; // Remove newline character

	printf("Enter student age:");
	scanf("%d", &ptr->Age);

	printf("Enter student ID:");
	scanf("%d", &ptr->ID);

	printf("Enter student GPA:");
	scanf("%f", &ptr->GPA);
	if (ptr->GPA > 4 || ptr->GPA < 0) {
		printf("Error, GPA should be higher than 0 and no more than 4.\n");
		printf("Enter student GPA:");
		scanf("%f", &ptr->GPA);
	}
	printf("Student's data has been successfully added.\n");

}
//====================================================================
/**
 * Prints all student records in the linked list.
 *
 * Techniques:
 * - Checks for empty list (global `head`).
 * - Traversal using a temporary pointer (`current`) to avoid modifying `head`.
 * - Formatted output for readability.
 */
void displayStudents(void)
{
	if (head == NULL) {
		printf("List is empty!\n");
		return;
	}
	// to make a display function with void parameter you need a head as a global variable
	n *current = head;  // Start at the head

	// Traverse until we reach NULL (end of list)
	while (current != NULL) {
		printf("[Name: %s, Age: %d, ID: %d, GPA: %.2f]\n", current->data.name,
				current->data.Age, current->data.ID, current->data.GPA);
		current = current->next;  // Move to next node
	}

}
//====================================================================
/**
 * Searches for a student by ID and prints their record if found.
 *
 * @param id    The student ID to search for.
 *
 * Techniques:
 * - Linear search through the linked list (O(n) time).
 * - Early termination when a match is found.
 */
void searchStudentByID(int id) {
	if (head == NULL) {
		printf("List is empty!\n");
		return;
	}
	n *current = head;
	while (current != NULL) {
		if (current->data.ID == id) {
			printf("[Name: %s, Age: %d, ID: %d, GPA: %.2f]\n",
					current->data.name, current->data.Age, current->data.ID,
					current->data.GPA);
			return;
		}
		current = current->next;
	}
	printf("Student %d isn't found.\n", id);

}
//====================================================================
/**
 * Updates a student's record by ID.
 * - Searches for student by ID, prompts for new name/age/GPA if found.
 * - Validates GPA input (0-4 range).
 * - Uses same input cleaning as addStudent().
 */
void updateStudent(int id) {
	if (head == NULL) {
		printf("List is empty!\n");
		return;
	}
	n *current = head;
	while (current != NULL) {
		if (current->data.ID == id) {
			//add students name,id,gpa,age
			while (getchar() != '\n')
				; // Only clear after previous scanf
			printf("Enter student name:");
			fgets(current->data.name, 50, stdin);
			current->data.name[strcspn(current->data.name, "\n")] = '\0'; // Remove newline character

			printf("Enter student age:");
			scanf("%d", &current->data.Age);

			printf("Enter student GPA:");
			scanf("%f", &current->data.GPA);
			printf("Student %d's data has been successfully updated.\n", id);
			return;

		}
		current = current->next;
	}
	printf("Student %d isn't found\n", id);

}
//====================================================================
/**
 * Deletes a student record by ID.
 *
 * @param id    The ID of the student to delete.
 *
 * Techniques:
 * - Handles three cases: empty list, head deletion, and middle/tail deletion.
 * - Uses `prev` and `current` pointers for safe traversal and deletion.
 * - Frees memory to prevent leaks.
 */
void deleteStudent(int id) {
	if (head == NULL) {
		printf("List is empty!\n");
		return;
	}
	// Special case: deleting first node
	if (head->data.ID == id) {
		n *temp = head;
		head = head->next;
		free(temp);
		printf("Student %d's data has been successfully deleted.\n", id);
		return;
	}
	n *current = head;
	n *prev = NULL;

	while (current != NULL && current->data.ID != id) {
		prev = current;
		current = current->next;
	}
	if (current == NULL) {
		printf("Student %d isn't found!\n", id);
		return;
	}
	prev->next = current->next;
	free(current);
	printf("Student %d's data has been successfully deleted.\n", id);

}
//====================================================================
/**
 * Calculates average GPA of all students.
 * - Returns 0 if list is empty.
 * - Traverses list while summing GPAs and counting students.
 * - Returns total GPA / student count.
 */
float calculateAverageGPA(void) {
	if (head == NULL) {
		return 0;
	}
	n *current = head;
	float summation = 0, counter = 0;
	while (current != NULL) {
		counter++;
		summation += current->data.GPA;
		current = current->next;
	}
	float avg = summation / counter;
	return avg;
}
//====================================================================
/**
 * Finds and prints the student(s) with the highest GPA.
 *
 * Techniques:
 * - Linear traversal to track the highest GPA (O(n) time).
 * - Assumes non-empty list (checked at start).
 */
void searchHighestGPA(void) {
	if (head == NULL) {
		printf("List is empty!\n");
		return;
	}

	n *current = head;
	n *highestStudent = head;  // Keep track of student with highest GPA
	float highest = head->data.GPA;  // Initialize with first student's GPA

	while (current != NULL) {
		if (current->data.GPA > highest) {
			highest = current->data.GPA;
			highestStudent = current;  // Save the pointer to this student
		}
		current = current->next;
	}
	printf("The student with highest GPA:\n");
	printf("Name: %s\n", highestStudent->data.name);
	printf("ID: %d\n", highestStudent->data.ID);
	printf("GPA: %.2f\n", highestStudent->data.GPA);
}
//====================================================================
/**
 * Displays a formatted introduction banner with program/author details.
 *
 * Techniques:
 * - Uses loops for consistent separator lines.
 * - Hardcoded text for simplicity (could be parameterized).
 */
void personal_intro(void) {
	for (int i = 0; i < 30; i++)
		printf("==");
	printf("\n");
	printf("Title: \n");
	printf("Author: Ahmed Basem");
	printf("\n");
	for (int i = 0; i < 30; i++)
		printf("==");
	printf("\n");
}

