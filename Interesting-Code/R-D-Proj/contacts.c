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

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+
#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
#include "contacts.h"
#include "contactHelpers.h"


// getName:
void getName(struct Name* name)
{

    char yesNo;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    //scanf("%s%*c", &yesNo); //<--- Incorrect, not a c string, must be a char
    yesNo = yes();

    if (yesNo == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]%*c", name->middleInitial);
    }

    printf("Please enter the contact's last name: ");
    //clearKeyboard();
    fflush(stdin);
    scanf("%35[^\n]%*c", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{
    char yesNo;

    do
    {
        printf("Please enter the contact's street number: ");
        scanf("%d%*c", &address->streetNumber);
    } while (address->streetNumber < 1);
    address->streetNumber = getInt();

    printf("Please enter the contact's street name: ");
    clearKeyboard();
    scanf("%40[^\n]%*c", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");
    yesNo = yes();

    if (yesNo == 'y' || yesNo == 'Y')
    {
        do
        {
            printf("Please enter the contact's apartment number: ");
            scanf("%d%*c", &address->apartmentNumber);
        } while (address->apartmentNumber < 1);
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]%*c", address->postalCode);

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    char yesNo;

    printf("Enter your cell phone number: ");
    scanf("%10[^\n]%*c", numbers->cell);
    
    printf("Do you want to enter a home phone number? (y or n): ");
    yesNo = yes();

    //if (yesNo == 'y' && yesNo == 'Y') // <-- No! can't be both 'y' AND 'Y' (should be OR ||)
    if (yesNo == 'y' || yesNo == 'Y')
    {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]%*c", numbers->home);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    yesNo = yes();

    if (yesNo == 'y' || yesNo == 'Y')
    {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]%*c", numbers->business);
    }
}

void getContact(struct Contact* contact) {
    
        struct Contact locContact;

        getName(&locContact.name);
        getAddress(&locContact.address);
        getNumbers(&locContact.numbers);

        *contact = locContact;
        // Use an open and close curly brace with a blank line
    
}