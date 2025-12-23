/*Docuementation
Name: G.V.Pavan Kumar
Date: 4-07-2025
Description: AddressBook Project
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"

// Function to validate a phone number (must be exactly 10 digits and numeric)
int validate_number(AddressBook *addressBook, char *number)
{
    int i = 0;
    // Loop through each character of the number until a non-digit is found
    while (number[i] >= '0' && number[i] <= '9')
    {
        i++; // Move to the next character
    }
    // If exactly 10 digits were found, the number is valid
    if (i == 10)
    {
        return 1; // Valid number
    }
    return 0; // Invalid number
}

// Function to validate an email address format
int validate_email(AddressBook *addressBook, char *email)
{
    int i = 0, j;

    // Check if email contains '@' and ends with ".com"
    if (strchr(email, '@') == NULL || strstr(email, ".com") == NULL)
    {
        return 0; // Invalid if either is missing
    }

    // Loop through the email string
    while (email[i])
    {
        // If '@' is found, perform further checks
        if (email[i] == '@')
        {
            // Check if characters before and after '@' are alphanumeric
            if (isalnum(email[i - 1]) && isalnum(email[i + 1]))
            {
                j = i + 1;
                // Check domain part before ".com" — must be alphanumeric only
                while (email[j] != '.' && email[j])
                {
                    if (!isalnum(email[j]))
                        return 0; // Invalid character in domain
                    j++;
                }
            }
        }

        // If uppercase letters or spaces are found, reject the email
        if (isupper(email[i]) || email[i] == ' ')
        {
            return 0;
        }
        i++;
    }

    // Confirm ".com" is at the end and no characters follow it
    if (strstr(email, ".com") == &email[j] && email[j + 4] == '\0')
    {
        return 1; // Valid email
    }

    return 0; // Invalid if ".com" is not correctly positioned
}

// Function to check if a given phone number already exists in the address book
int is_duplicate_number(AddressBook *addressBook, char *new_number)
{
    // Loop through all contacts in the address book
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        // Compare each contact's phone number with the new number
        if (strcmp(addressBook->contacts[i].phone, new_number) == 0)
            return 1; // Duplicate found
    }
    return 0; // No duplicate found
}

// Function to check if a given email already exists in the address book
int is_duplicate_email(AddressBook *addressBook, char *new_email)
{
    // Loop through all contacts in the address book
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        // Compare each contact's email with the new email
        if (strcmp(addressBook->contacts[i].email, new_email) == 0)
            return 1; // Duplicate email found
    }
    return 0; // No duplicate email found
}

// Function to search for a contact by name
void search_name(AddressBook *addressBook)
{
    char new_name[20]; // Buffer to store the name entered by the user
    int i, found = 0;  // 'found' tracks how many matching contacts were found

    while (1) // Repeat until at least one match is found
    {
        printf("Enter the name:");
        scanf(" %[^\n]", new_name); // Read a line of input including spaces

        // Loop through all contacts in the address book
        for (i = 0; i < addressBook->contactCount; i++)
        {
            // Compare each contact's name with the input name
            if (strcmp(addressBook->contacts[i].name, new_name) == 0)
            {
                // If a match is found, display the contact details
                printf("contact %d\n", found + 1);
                printf("Name : %s\n", addressBook->contacts[i].name);
                printf("Phone : %s\n", addressBook->contacts[i].phone);
                printf("Email : %s\n", addressBook->contacts[i].email);
                found++; // Increment the found counter
            }
        }

        // If no match was found, prompt user to try again
        if (found == 0)
        {
            printf("contact is not found\n");
            continue;
        }

        // Exit loop once at least one contact was found
        break;
    }
}

// Function to search for a contact by phone number
void search_phone(AddressBook *addressBook)
{
    int i, found = 0; // 'found' keeps track of how many matches were found
    char number[20];  // To store the phone number entered by the user
    int result = 0;   // Flag to check if the number is valid

    while (!result) // Loop until a valid number is entered
    {
        printf("enter the number:");
        scanf(" %[^\n]", number);                      // Read the phone number input including spaces
        result = validate_number(addressBook, number); // Validate number format

        if (result) // If number is valid
        {
            for (i = 0; i < addressBook->contactCount; i++) // Search through all contacts
            {
                if (strcmp(number, addressBook->contacts[i].phone) == 0) // Match found
                {
                    // Print contact details
                    printf("contact :%d\n", found + 1);
                    printf("Name : %s\n", addressBook->contacts[i].name);
                    printf("Phone : %s\n", addressBook->contacts[i].phone);
                    printf("Email : %s\n", addressBook->contacts[i].email);
                    found++; // Increment match count
                }
            }
        }
        if (!result) // If number is invalid
        {
            printf("Invalid number Try again\n");
        }
    }

    // If no contact was found with the valid number
    if (found == 0)
    {
        printf("Number not found\n");
    }
}

// Function to search for a contact by email address
void search_email(AddressBook *addressBook)
{
    char email[30];               // To store the email entered by the user
    int found = 0, i, result = 0; // 'found' counts matches, 'result' indicates valid email

    while (!result) // Loop until a valid email is entered
    {
        printf("Enter the mail to search:");
        scanf(" %[^\n]", email);                     // Read the email input including spaces
        result = validate_email(addressBook, email); // Validate email format

        if (result) // If the email is valid
        {
            for (i = 0; i < addressBook->contactCount; i++) // Search through all contacts
            {
                if (strcmp(email, addressBook->contacts[i].email) == 0) // Match found
                {
                    // Print contact details
                    printf("contact :%d\n", found + 1);
                    printf("Name : %s\n", addressBook->contacts[i].name);
                    printf("Phone : %s\n", addressBook->contacts[i].phone);
                    printf("Email : %s\n", addressBook->contacts[i].email);
                    found++; // Increment match counter
                }
            }
        }
        if (!result) // If email format is invalid
        {
            printf("Invalid email !\n");
        }
    }

    // If no matching email was found
    if (found == 0)
    {
        printf("Email not found\n");
    }
}

// Function to search for contacts by name and either edit or delete them based on the flag 'f'
void search_by_name(AddressBook *addressBook, int f)
{
    char new_name[30];            // To store the name entered by the user
    int count = 0, i;             // 'count' counts matches, 'i' is a loop index
    int name_index[MAX_CONTACTS]; // Array to store indices of matched contacts

    while (1) // Keep prompting until at least one match is found
    {
        printf("\nEnter the name:");
        scanf(" %[^\n]", new_name); // Read the name including spaces

        // Search through all contacts
        for (i = 0; i < addressBook->contactCount; i++)
        {
            // If the name matches, store the index
            if (strcmp(addressBook->contacts[i].name, new_name) == 0)
            {
                name_index[count++] = i; // Store index and increment count
            }
        }

        // If no match found, notify and continue the loop
        if (count == 0)
        {
            printf("\nContact is not found\n");
            continue;
        }
        else
        {
            // If f is non-zero, call edit function
            if (f)
            {
                edit_contact(addressBook, name_index, count);
                break; // Exit after editing
            }
            else
            {
                // If f is zero, call delete function
                delete_contact(addressBook, name_index, count);
                break; // Exit after deleting
            }
        }

        break; // (Redundant but harmless due to previous break statements)
    }
}

// Function to search for a contact by phone number and either edit or delete it based on the flag 'f'
void search_by_phone(AddressBook *addressBook, int f)
{
    int i, count = 0;    // 'i' is loop index, 'count' tracks matches
    char new_number[20]; // To store the phone number entered by the user
    int number_index[5]; // Array to store the indices of matched contacts (supports up to 5 matches)

    while (1) // Loop until a valid number is entered and found
    {
        printf("Enter the contact number: ");
        scanf(" %[^\n]", new_number); // Read phone number including spaces

        // Basic validation function
        if (!validate_number(addressBook, new_number)) // Check if number is valid
        {
            printf("Invalid number format!\n");
            continue; // Prompt again if invalid
        }

        count = 0;                                      // Reset count for each attempt
        for (i = 0; i < addressBook->contactCount; i++) // Loop through contacts
        {
            if (strcmp(addressBook->contacts[i].phone, new_number) == 0) // Match found
                number_index[count++] = i;                               // Store index and increment count
        }

        if (count == 0) // No matches found
        {
            printf("Contact number not found.\n");
        }
        else // At least one match found
        {
            if (f) // If flag is set, perform edit
            {
                edit_contact(addressBook, number_index, count);
                break;
            }
            else // If flag is not set, perform delete
            {
                delete_contact(addressBook, number_index, count);
                break;
            }
        }
    }
}

// Function to search for a contact by email and either edit or delete it based on the flag 'f'
void search_by_email(AddressBook *addressBook, int f)
{
    int i, count = 0;              // 'i' is loop index, 'count' tracks matches
    char new_email[50];            // To store the email entered by the user
    int email_index[MAX_CONTACTS]; // Array to store the indices of matched contacts

    while (1) // Keep prompting until a valid email is found and processed
    {
        printf("Enter the contact email: ");
        scanf(" %[^\n]", new_email); // Read the email input including spaces

        // Validate the email format
        if (!validate_email(addressBook, new_email))
        {
            printf("Invalid email format!\n");
            continue; // Prompt again if invalid
        }

        count = 0;                                      // Reset match count before searching
        for (i = 0; i < addressBook->contactCount; i++) // Loop through all contacts
        {
            // If email matches, store the index
            if (strcmp(addressBook->contacts[i].email, new_email) == 0)
                email_index[count++] = i;
        }

        if (count == 0) // No match found
        {
            printf("Contact email not found.\n");
        }
        else // One or more matches found
        {
            if (f) // If flag is set, perform edit
            {
                edit_contact(addressBook, email_index, count);
                break;
            }
            else // If flag is not set, perform delete
            {
                delete_contact(addressBook, email_index, count);
                break;
            }
        }
    }
}

// Function to edit a contact from the given list of matching indices
void edit_contact(AddressBook *addressBook, int *index, int count)
{
    int i, f = 1, select = 1;                            // 'f' is for display numbering, 'select' will store selected contact index
    char edit_name[50], edit_number[20], edit_email[50]; // Buffers to store new user input

    // Display all matched contacts to the user
    printf("\nThese are the matches contacts:\n");
    for (i = 0; i < count; i++)
    {
        printf("\ncontact %d\n", f);
        printf("Name : %s\n", addressBook->contacts[index[i]].name);
        printf("Phone : %s\n", addressBook->contacts[index[i]].phone);
        printf("Email : %s\n", addressBook->contacts[index[i]].email);
        f++;
    }

    // If more than one match, prompt user to choose the exact contact to edit
    if (count > 1)
    {
        while (1)
        {
            printf("\nSelect the one contact from %d: ", count);
            if (scanf("%d", &select) != 1) // Validate numeric input
            {
                while (getchar() != '\n') // clear the input buffer
                    ;
                printf("Invalid selection select 1 to 4 only\n");
                continue;
            }
            if (select >= 1 && select <= count) // Check if selected index is within range
                break;
            printf("\nInvalid selection\n");
        }
    }

    // Ask which field to edit: Name, Phone, Email, or Exit
    printf("\nChoose the edit option\n1.Name\n2.Phone\n3.Email\n4.return to back menu\n");
    int choose = 0;
    select = index[select - 1]; // Map user's selection to actual contact index

    while (1)
    {
        printf("\nSelect one to edit:");
        if (scanf("%d", &choose) != 1) // Validate numeric input
        {
            while (getchar() != '\n') // clear the input buffer
                ;
            printf("Invalid selection select 1 to 4 only\n");
            continue;
        }

        switch (choose)
        {
        case 1:
            // Edit Name
            printf("Enter the new name:");
            scanf(" %[^\n]", edit_name);
            strcpy(addressBook->contacts[select].name, edit_name);
            break;

        case 2:
            // Edit Phone Number with validation
            while (1)
            {
                printf("Enter the new number:");
                scanf(" %[^\n]", edit_number);
                if (!validate_number(addressBook, edit_number)) // Check for valid format
                {
                    printf("Invalid number\n");
                    continue;
                }
                if (!is_duplicate_number(addressBook, edit_number)) // Check for duplicates
                {
                    strcpy(addressBook->contacts[select].phone, edit_number);
                    break;
                }
            }
            break;

        case 3:
            // Edit Email with validation
            while (1)
            {
                printf("Enter the new email:");
                scanf(" %[^\n]", edit_email);
                if (!validate_email(addressBook, edit_email)) // Check for valid format
                {
                    printf("Invalid Email\n");
                    continue;
                }
                if (!is_duplicate_email(addressBook, edit_email)) // Check for duplicates
                {
                    strcpy(addressBook->contacts[select].email, edit_email);
                    break;
                }
            }
            break;

        case 4:
            // Exit without editing
            return;

        default:
            // Handle invalid choices
            printf("\nInvalid input Enter the valied one\n");
            continue;
        }

        break; // Exit loop after a successful edit
    }

    // Show updated contact information
    printf("\nSuccessfully Edited your contact\n");
    printf("Name  : %s\n", addressBook->contacts[select].name);
    printf("Phone : %s\n", addressBook->contacts[select].phone);
    printf("Email : %s\n", addressBook->contacts[select].email);
}

// Function to delete a selected contact from the address book
void delete_contact(AddressBook *addressBook, int *index, int count)
{
    int i, select = 1, f = 1; // 'select' stores user's selection, 'f' is used for display numbering

    // Display all matching contacts
    printf("These are the matches contacts:\n");
    for (i = 0; i < count; i++)
    {
        printf("\ncontact %d\n", f);
        printf("Name : %s\n", addressBook->contacts[index[i]].name);
        printf("Phone : %s\n", addressBook->contacts[index[i]].phone);
        printf("Email : %s\n", addressBook->contacts[index[i]].email);
        f++;
    }

    // If there are multiple matches, prompt the user to select one
    if (count > 1)
    {
        while (1)
        {
            printf("Select the one contact from %d: ", count);
            scanf("%d", &select);               // Take user input
            if (select >= 1 && select <= count) // Validate input range
                break;
            printf("Invalid selection\n"); // Retry if invalid
        }
    }

    // Convert user selection to actual index in contact array
    select = index[select - 1];

    // Shift all contacts after the selected one to the left by one position
    for (i = select; i < addressBook->contactCount; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    // Decrease total contact count
    addressBook->contactCount--;

    // Notify the user
    printf("\nContact deleted successfully.\n");
}
