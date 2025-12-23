#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>

#define MAX_CONTACTS 100 // Maximum number of contacts allowed in the address book

// Structure to store individual contact information
typedef struct Contact
{
    char name[50];  // Name of the contact
    char phone[20]; // Phone number of the contact
    char email[50]; // Email address of the contact
} Contact;

// Structure to represent the address book containing an array of contacts
typedef struct
{
    Contact contacts[MAX_CONTACTS]; // Array of Contact structures
    int contactCount;               // Current count of contacts in the address book
} AddressBook;

// Function prototypes

// Creates a new contact and adds it to the address book
void createContact(AddressBook *addressBook);

// Searches for a contact based on user input
void searchContact(AddressBook *addressBook);

// Edits an existing contact's details
void editContact(AddressBook *addressBook);

// Deletes a contact from the address book
void deleteContact(AddressBook *addressBook);

// Lists all contacts stored in the address book
void listContacts(AddressBook *addressBook);

// Initializes the address book (usually sets contactCount to 0)
void initialize(AddressBook *addressBook);

// Saves the contact list to a file
void saveContactsToFile(AddressBook *AddressBook);

// Validates the format and uniqueness of a contact number
int validate_number(AddressBook *AddressBook, char *number);

// Validates the format and uniqueness of an email address
int validate_email(AddressBook *AddressBook, char *email);

// Search helpers for name, phone, and email
void search_name(AddressBook *addressBook);
void search_phone(AddressBook *addressBook);
void search_email(AddressBook *addressBook);

// Sub-functions to search by name/phone/email with support for multiple matches
void search_by_name(AddressBook *addressBook, int f);
void search_by_phone(AddressBook *addressBook, int f);
void search_by_email(AddressBook *addressBook, int f);

// Edits a contact at a specific index (selected previously)
void edit_contact(AddressBook *addressBook, int *name_index, int count);

// Deletes one or more contacts based on index array
void delete_contact(AddressBook *addressBook, int *index_array, int count);

// Checks if a phone number is already present in the address book
int is_duplicate_number(AddressBook *addressBook, char *new_number);

// Checks if an email is already present in the address book
int is_duplicate_email(AddressBook *addressBook, char *new_email);

#endif
