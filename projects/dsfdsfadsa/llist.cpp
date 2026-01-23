/*****************************************************************
//
//  NAME:        Chase Obuhanych
//
//  HOMEWORK:    project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 30, 2024
//
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   llist contains constructors for the class llist, as well as
//   a deconstructor, and code for the database functions used by
//   the user interface
//
****************************************************************/

#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include "llist.h"

using namespace std;

/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   constructor for the llist class called with
//                 no parameters, should not normally occur
//
****************************************************************/

llist::llist()
{
    start = NULL;
    strcpy(filename, "record.txt");
    #ifdef DEBUG
    cout << "DEBUG | Calling constructor with 0 parameters\n";
    #endif
    readfile();
}

/*****************************************************************
//
//  Function name: llist
//
//  Parameters:    fname (const char[]) : file name to be read
//
//  DESCRIPTION:   constructor for the llist class called with
//                 the file name as a parameter
//
****************************************************************/

llist::llist(const char fname[])
{
    start = NULL;
    strcpy(filename, fname);
    #ifdef DEBUG
    cout << "DEBUG | Calling constructor with filename parameter: " << filename << endl;
    #endif
    readfile();
}

/*****************************************************************
//
//  Function name: ~llist
//
//  DESCRIPTION:   deconstructor for the llist class, clears memory
//                 and calls the write function
//
****************************************************************/

llist::~llist()
{
    #ifdef DEBUG
    cout << "DEBUG | Calling deconstructor\n";
    #endif
    writefile();
    cleanup();
}

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   adds a node to the linked list containing
//                 the account number, name, and address.
//                 adds it in numerical order according to
//                 account number.
//
//  Parameters:    accountno (int)
//                 name (char[])
//                 address (char[])
//
//  Return values:  0 - successfully added to linked list
//                  -1 - could not add due to duplicate
//
****************************************************************/

int llist::addRecord(int accountno, char name[], char address[])
{
    #ifdef DEBUG
    cout << "DEBUG | Add function called successfully, parameters passed:\n";
    cout << "Account number: " << accountno << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    #endif
    record* temp = new record;
    record* current = start;
    record* previous = NULL;

    temp->accountno = accountno;
    strcpy(temp->name, name);
    strcpy(temp->address, address);
    temp->next = NULL;

    if (start == NULL)
    {
        start = temp;
        return 0;
    }

    while (current != NULL)
    {
        if (current->accountno == accountno)
        {
            #ifdef DEBUG
            cout << "DEBUG | Duplicate account number found\n";
            #endif
            delete temp;
            return -1;
        }
        if (current->accountno > accountno)
        {
            temp->next = current;
            if (previous != NULL)
            {
                previous->next = temp;
            }
            else
            {
                start = temp;
            }
            return 0;
        }
        previous = current;
        current = current->next;
    }

    if (previous != NULL)
    {
        previous->next = temp;
    }
    return 0;
}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   prints each record in the current linked list
//
****************************************************************/

void llist::printAllRecords()
{
    #ifdef DEBUG
    cout << "DEBUG | Print function called successfully\n";
    #endif
    if (start == NULL)
    {
        cout << "No records found." << endl;
    }
    else
    {
        record* current = start;
        cout << "Current Records:\n";
        while (current != NULL)
        {
            cout << "----------------------------------------------------------\n";
            cout << "Account number: " << current->accountno << "\nName: " << current->name <<"\nAddress: " << current->address <<"\n";
            current = current->next;
        }
    }
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   gets an account number from user input and
//                 prints the data for that node if applicable
//
//  Parameters:    accountno (int)
//
//  Return values:  -1 - record not found
//                  0 - record found and printed
//
****************************************************************/

int llist::findRecord(int accountno)
{
    #ifdef DEBUG
    cout << "DEBUG | Find function called successfully, parameters passed: \n";
    cout << "Account number: " << accountno << endl;
    #endif
    record* current = start;
    while (current != NULL)
    {
        if (current->accountno == accountno)
        {
            cout << "Account No: " << current->accountno << "\nName: " << current->name <<"\nAddress: " << current->address << "\n";
            return 0;
        }
        current = current->next;
    }
    return -1;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   deletes the record specified by the user through
//                 an inputted account number
//
//  Parameters:    accountno (int)
//
//  Return values:  -1 - record not found
//                  0 - record deleted successfully
//
****************************************************************/

int llist::deleteRecord(int accountno)
{
    #ifdef DEBUG
    cout << "DEBUG | Delete function called successfully, parameters passed: \n";
    cout << "Account number: " << accountno << endl;
    #endif
    record* current = start;
    record* previous = NULL;
    record *nextr;
    while (current != NULL)
    {
        if (current->accountno == accountno)
        {
            if (previous == NULL)
            {
                nextr = current -> next;
                start = nextr;
            }
            else
            {
                nextr = current->next;
                previous->next = nextr;
            }
            delete current;
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return -1;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   overwrites a text file with values from the linked list
//                 writes a '%' between nodes
//
//  Parameters:    filename (char[])
//
//  Return values:  -1 - file not found
//                  0 - read file successfully, stored on linked list
//
****************************************************************/

int llist::writefile()
{
    #ifdef DEBUG
    cout << "DEBUG | Write function called successfully\n";
    #endif
    ofstream file(filename);
    if (!file.is_open())
    {
        return -1;
    }
    record* current = start;
    while (current != NULL)
    {
        file << current->accountno << endl;
        file << current->name << endl;
        file << current->address << endl;
        file << "%" << endl;
        #ifdef DEBUG
        cout << "Writing entry to file: " << filename << endl;
        cout << current->accountno << endl;
        cout << current->name << endl;
        cout << current->address << endl;
        #endif
        current = current->next;
    }
    file.close();
    return 0;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   reads a file and store the values on the linked
//                 list, nodes separated by '%'
//
//  Parameters:    filename (char[])
//
//  Return values:  -1 - file not found
//                  0 - read file successfully, stored on linked list
//
****************************************************************/

int llist::readfile()
{
    #ifdef DEBUG
    cout << "DEBUG | Read function called successfully\n";
    #endif
    ifstream file(filename);
    if (!file.is_open())
    {
        return -1;
    }
    cleanup();
    string line;
    int accountno;
    char name[25], address[45];

    while (getline(file, line))
    {
        istringstream(line) >> accountno;
        file.getline(name, 25);
        address[0] = '\0';
        while (getline(file, line) && line != "%")
        {
            if (!line.empty())
            {
                strcat(address, line.c_str());
                strcat(address, "\n");
            }
        }
        addRecord(accountno, name, address);
    }
    #ifdef DEBUG
    cout << "DEBUG | All entries from file are added to the record\n";
    #endif
    file.close();
    return 0;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   frees each node before closing and assigns null
//                 to start
//
****************************************************************/

void llist::cleanup()
{
    #ifdef DEBUG
    cout << "DEBUG | Cleanup function called, clearing records\n";
    #endif
    record* current = start;
    while (current != NULL)
    {
        record* next = current->next;
        delete current;
        current = next;
    }
    start = NULL;
}
