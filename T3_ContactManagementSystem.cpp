#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to represent a contact
struct Contact {
    string name;
    string phoneNumber;
    string email;
};

// Function to add a new contact
void addContact(Contact contacts[], int& size, const int capacity) {
    if (size == capacity) {
        cout << "Contact capacity reached. Cannot add more contacts." << endl;
        return;
    }

    cout << "Enter contact name: ";
    cin >> contacts[size].name;
    cout << "Enter phone number: ";
    cin >> contacts[size].phoneNumber;
    cout << "Enter email address: ";
    cin >> contacts[size].email;
    ++size;

    cout << "Contact added successfully!" << endl;
}

// Function to view all contacts
void viewContacts(const Contact contacts[], const int size) {
    if (size == 0) {
        cout << "No contacts available." << endl;
    } else {
        cout << "Contact List:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Name: " << contacts[i].name << ", Phone: " << contacts[i].phoneNumber << ", Email: " << contacts[i].email << endl;
        }
    }
}

// Function to edit a contact
void editContact(Contact contacts[], const int size) {
    string name;
    cout << "Enter the name of the contact you want to edit: ";
    cin >> name;
    for (int i = 0; i < size; ++i) {
        if (contacts[i].name == name) {
            cout << "Enter new phone number: ";
            cin >> contacts[i].phoneNumber;
            cout << "Enter new email address: ";
            cin >> contacts[i].email;
            cout << "Contact edited successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found." << endl;
}

// Function to delete a contact
void deleteContact(Contact contacts[], int& size) {
    string name;
    cout << "Enter the name of the contact you want to delete: ";
    cin >> name;
    for (int i = 0; i < size; ++i) {
        if (contacts[i].name == name) {
            for (int j = i; j < size - 1; ++j) {
                contacts[j] = contacts[j + 1];
            }
            --size;
            cout << "Contact deleted successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found." << endl;
}

// Function to save contacts to a file
void saveContactsToFile(const Contact contacts[], const int size, const string& filename) {
    ofstream fout(filename);
    if (fout.is_open()) {
        for (int i = 0; i < size; ++i) {
            fout << contacts[i].name << " " << contacts[i].phoneNumber << " " << contacts[i].email << endl;
        }
        cout << "Contacts saved to file." << endl;
    } else {
        cout << "Unable to open file for saving contacts." << endl;
    }
}

// Function to load contacts from a file
void loadContactsFromFile(Contact contacts[], int& size, const int capacity, const string& filename) {
    size = 0;
    ifstream fin(filename);
    if (fin.is_open()) {
        while (size < capacity && fin >> contacts[size].name >> contacts[size].phoneNumber >> contacts[size].email) {
            ++size;
        }
        cout << "Contacts loaded from file." << endl;
    } else {
        cout << "No existing contact file found." << endl;
    }
}

int main() {
    const int capacity = 100; // Maximum number of contacts
    Contact contacts[capacity];
    int size = 0;
    string filename = "contacts.txt";
    loadContactsFromFile(contacts, size, capacity, filename);

    int choice;
    while(true){
    do {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Edit Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Save Contacts to File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts, size, capacity);
                break;
            case 2:
                viewContacts(contacts, size);
                break;
            case 3:
                editContact(contacts, size);
                break;
            case 4:
                deleteContact(contacts, size);
                break;
            case 5:
                saveContactsToFile(contacts, size, filename);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
}
