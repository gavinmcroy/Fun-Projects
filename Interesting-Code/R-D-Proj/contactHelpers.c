//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include "contactHelpers.h"
#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
    printf("(Press Enter to continue)");
    clearKeyboard();

}

// getInt function definition goes here:
int getInt(void)
{
	int integer;
	char nextLine = 'x';

	while (nextLine != '\n') {

		scanf("%d%c", &integer, &nextLine);
		if (nextLine != '\n') {
			clearKeyboard();

			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return integer;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
	int rangeValue, rangeCheck = 0;

	while (rangeCheck == 0) {

		rangeValue = getInt();

		if (rangeValue > max || rangeValue < min) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
		else {
			rangeCheck = 1;
		}
	}
	return rangeValue;
}

// yes function definition goes here:
int yes(void)
{
	char newLine = 'x', confirm = 'x';
	int yes;

	while (newLine != '\n') {

		scanf("%c%c", &confirm, &newLine);
		if (newLine != '\n') {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else if (confirm == 'y' || confirm == 'Y') {
			yes = 1;
		}
		else if (confirm == 'n' || confirm == 'N') {
			yes = 0;
		}
		else {
			newLine = 'x';
		}

	}
	return yes;
}

// menu function definition goes here:
int menu(void)
{
	int choice = 0;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	choice = getIntInRange(0, 6);

	return choice;
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
	int done = 0;
	int options;

	while (done == 0) {

		options = menu();

		switch (options) {

		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			break;

		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			break;

		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			break;

		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			break;

		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			break;

		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			break;

		case 0:

			printf("\nExit the program? (Y)es/(N)o: ");
			done = yes();
			break;

		default:
			break;
		}
		printf("\n");
	}
	printf("Contact Management System: terminated\n");
}
