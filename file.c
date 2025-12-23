/*Docuementation
Name: G.V.Pavan Kumar
Date: 4-07-2025
Description: AddressBook Project
*/

#include <stdio.h>
#include "file.h"
#include "contact.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fptr = fopen("contacts.csv", "w");
    if (fptr == NULL)
    {
        fprintf(stderr, "Cannot open the file for writing\n");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fptr, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fptr = fopen("contacts.csv", "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "Cannot open the file for reading\n");
        return;
    }

    int i = 0;
    while (i < MAX_CONTACTS)
    {
        int ret = fscanf(fptr, "%99[^,],%19[^,],%99[^\n]\n",
                         addressBook->contacts[i].name,
                         addressBook->contacts[i].phone,
                         addressBook->contacts[i].email);

        if (ret != 3)
        {
            break; // Stop if line is not formatted properly
        }

        i++;
    }

    addressBook->contactCount = i;
    fclose(fptr);
}
