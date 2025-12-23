/*Docuementation
Name: G.V.Pavan Kumar
Date: 4-07-2025
Description: AddressBook Project
*/

#include <stdio.h>    // Standard I/O functions
#include <stdlib.h>   // For exit()
#include <string.h>   // For string functions
#include "contact.h"  // User-defined header for contact structure
#include "file.h"     // Header for file operations
//#include "populate.h" // Header for populating initial data

void listContacts(AddressBook *addressBook)
{
    int i, found = 1;
    /* Define the logic for print the contacts */
    for (i = 0; i < addressBook->contactCount; i++) // Loop through all contacts
    {
        printf("Contact :%d\n", found++);                         // Print contact index
        printf("Name : %s\n", addressBook->contacts[i].name);     // Print name
        printf("Phone : %s\n", addressBook->contacts[i].phone);   // Print phone number
        printf("Email : %s\n\n", addressBook->contacts[i].email); // Print email
    }
}

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;    // Initialize contact count to 0
   // populateAddressBook(addressBook); // Populate contacts (default or from file)

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook); // Uncomment to enable file load
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}

void createContact(AddressBook *addressBook)
{
    // Read the name from the user
    char name[30];
    printf("Enter the name:");                                           // Prompt for name
    scanf(" %[^\n]", name);                                              // Read full line input
    strcpy(addressBook->contacts[addressBook->contactCount].name, name); // Store name

    // read the number
    char number[11];
    int result = 1, i, ret = 0;

    while (result)
    {
        printf("Enter the ph.number:"); // Prompt for phone number
        scanf(" %s", number);           // Read phone number

        if (validate_number(addressBook, number))
        {
            result = is_duplicate_number(addressBook, number);
        }
        if (result)
        {
            printf("Invalid mobile number!\n"); // Show error
            continue;
        }
        break;
    }
    // saving the mobile number
    strcpy(addressBook->contacts[addressBook->contactCount].phone, number); // Store number

    // CODE FOR MAIL..........
    char email[50];
    result = 1;

    while (result)
    {
        // Read the email ID
        printf("Enter the email:"); // Prompt for email
        scanf(" %s", email);        // Read email
        // Function call
        if (validate_email(addressBook, email))
        {
            result = is_duplicate_email(addressBook, email); // checking for duplicate mail
        }

        if (result)
        {
            printf("Entered Email is invalid Please Re-Enter the mail\n"); // Show error
            continue;
        }
        break;
    }
    // Storing Entered Email
    strcpy(addressBook->contacts[addressBook->contactCount].email, email); // Store email

    // Increment the contact count.
    (addressBook->contactCount)++; // Increase total contacts

    printf("you are successfully saved the contact\n"); // Success message
}

void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
    int choice = 0;
    printf("Select one to search \n"); // Menu
    printf("1. Name\n");
    printf("2. Number\n");
    printf("3. Email\n");
    printf("4.Press 4 to goto main menu\n");
    while (1)
    {
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n') // clear the input buffer
                ;
            printf("Invalid selection select 1 to 4 only\n"); // Error on invalid input
            continue;
        }

        switch (choice)
        {
        case 1:
            search_name(addressBook); // Search by name
            return;
        case 2:
            search_phone(addressBook); // Search by phone
            return;
        case 3:
            search_email(addressBook); // Search by email
            return;
        case 4:
            return; // Back to main
        default:
            printf("Invalid choice.Enter the valid one\n"); // Wrong option
            continue;
        }
    }
}

void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
    int choice = 0;
    printf("\nSelect one to search\n");
    printf("1.name\n2.phone\n3.email\n4.back to main menu\n");
    while (1)
    {
        printf("Enter your choice:");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n') // clear the input buffer
                ;
            printf("Invalid selection select 1 to 4 only\n"); // Error on bad input
            continue;
        }

        switch (choice)
        {
        case 1:
            search_by_name(addressBook, 1); // Edit by name
            break;
        case 2:
            search_by_phone(addressBook, 1); // Edit by phone
            break;
        case 3:
            search_by_email(addressBook, 1); // Edit by email
            break;
        case 4:
            return; // Back to main menu
        default:
            printf("Invalid Please enter the valid one\n"); // Invalid menu input
            continue;
        }
        break; // Exit after edit
    }
}

void deleteContact(AddressBook *addressBook)
{
    /* Define the logic for deletecontact */
    int choice = 0;
    printf("Select one to search\n");
    printf("1.name\n2.phone\n3.email\n4.To return main menu\n");
    while (1)
    {
        printf("Choose one option:");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n') // clear the input buffer
                ;
            printf("Invalid selection select 1 to 4 only\n"); // Handle bad input
            continue;
        }

        switch (choice)
        {
        case 1:
            search_by_name(addressBook, 0); // Delete by name
            break;
        case 2:
            search_by_phone(addressBook, 0); // Delete by phone
            break;
        case 3:
            search_by_email(addressBook, 0); // Delete by email
            break;
        case 4:
            return; // Back to main menu
        default:
            printf("Invalid Please enter the valid one"); // Invalid input
            continue;
        }
        break; // Exit after delete
    }
}
