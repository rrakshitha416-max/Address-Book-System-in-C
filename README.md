📒 Address Book Management System in C This project is a command-line based Address Book application developed in C that enables users to efficiently manage contact information with features like creation, search, edit, deletion, and storage in a .csv file. Built using modular C programming, it incorporates strong input validation and file handling, simulating the functionality of real-world contact management systems.

📌 Project Overview Traditional paper-based address books are outdated and inefficient. This project brings a digital solution that allows users to manage contacts using a terminal-based interface. It includes real-time user interaction, robust input validation, and persistent storage using file I/O operations. Contacts are saved in a CSV format so that the data can be viewed or modified externally if needed.

⚙️ Components / Tools Used C Programming Language

GCC Compiler

Terminal / Command-line Interface

Text File (CSV format) for Storage

Modular File Structure

main.c – Program entry & menu interface

contact.c / contact.h – Core contact operations

file.c / file.h – File handling: load & save

utils.c / utils.h – Validation logic

🧠 Working Principle The system uses a menu-driven interface to perform the following operations:

Create Contact Adds a new contact after validating the name, email, and phone number. Prevents duplicates.

Search Contact Lets the user search by name, email, or phone. Displays matching results.

Edit Contact Allows editing of existing contact information after confirmation.

Delete Contact Removes a contact with confirmation and saves the updated list.

List Contacts Shows all contacts in a neatly formatted list.

Save & Exit Writes all changes to addressBook.csv and exits cleanly.

🔐 Input Validation Rules Email: Must contain a single @ and a valid .com domain Example: pavan.g@domain.com

Phone: Exactly 10 digits, numeric only Example: 9876543210

Name: Alphabetic characters only, no numbers or special characters Example: Anju

Invalid entries are rejected with clear error messages.

💡 Features Add, search, edit, delete, and list contacts

Validates email, phone, and name before saving

Stores data in .csv file for persistence

Prevents duplicate entries (based on email/phone)

Clean, modular codebase for easy maintenance

Supports hundreds of contacts with ease

🗂️ File Structure

📁 addressbook/
├── main.c            // Program entry and menu interface
├── contact.c/.h      // Core contact management logic (CRUD)
├── defination.c      // Input validation and search helpers
├── file.c/.h         // File handling: load and save contacts
├── populate.c        // Loads dummy contacts at startup
├── contacts.csv      // Saved contact data (auto-generated)
└── README.md         // Project documentation

📸 Project Media Sample Terminal Output

![Screenshot 2025-07-07 204640](https://github.com/user-attachments/assets/65da0603-a8ec-46ab-8ba4-4a99ad9c8009)

![Screenshot 2025-07-07 213102](https://github.com/user-attachments/assets/2bb73fb2-d8bf-4c8b-8dfc-7746f0e454ba)

Project demo : https://drive.google.com/file/d/1IqZupMrqUzBJiKHFk8fIH6HniDKJXta4/view?usp=sharing

📈 Future Improvements GUI version using GTK or ncurses

SQLite or MySQL database integration

Undo/restore recently deleted contacts

User authentication and password-protection

Soft-delete system with recovery option

👩‍💻 Developed By Pavan Kumar G V Graduate Engineer – Embedded Systems Enthusiast 📧 gvpavanec008@gmail.com
