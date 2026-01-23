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
//  FILE:        user_interface.cpp
//
//  DESCRIPTION:
//   this program types out a user interface and prompts the user to input one of the five choices until they quit.
//   'add' will ask the user for an account number, name, and address, which will then be sent to the addRecord function.
//   'printall' takes no parameters and will print all existing records.
//   'find' will ask the user for an account number, which will be sent to the findRecord function.
//   'delete' will ask the user for an account number, which will be sent to the deleteRecord function.
//   'quit' will exit out of the loop and terminate the program.
//
****************************************************************/

#include <iostream>
#include <cstring>
#include "llist.h"
#include <fstream>
using namespace std;

void getaddress(char[], int);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Prints a user interface where it will prompt
//                 the user for valid input. It can then ask for
//                 further information such as account number, name, etc.
//
//  Return values:  0 : success
//
****************************************************************/

int main()
{
    #ifdef DEBUG
    cout << "DEBUG | Debug Mode Success\n";
    #endif
    llist mylist("record.txt");

    int accountno;
    char name[25];
    char address[45];
    int check;
    int quit;
    char input[64];

    check = 0;
    quit = 0;

    while (quit == 0)
    {
        cout << "----------------------------------------------------------\n";
        cout << "Welcome to the ICS 212 Bank Database.\n";
        cout << "----------------------------------------------------------\n\n";
        cout << "Please select an option.\n\n";
        cout << "add: Adds a record to the database.\n";
        cout << "printall: Prints all existing records in the database.\n";
        cout << "find: Finds a specific record within the database.\n";
        cout << "delete: Deletes an existing record from the database.\n";
        cout << "exit: Exits the program.\n";
        cout << "----------------------------------------------------------\n\n";

        cin >> input;
        #ifdef DEBUG
        cout << "DEBUG | User Input: " << input << endl;
        #endif
        if (strncmp(input, "add", strlen(input)) == 0 && strlen(input) <= strlen("add"))
        {
            check = 0;

            #ifdef DEBUG
            cout << "DEBUG | Selected ADD \n";
            #endif

            while (check == 0) {
                char trash [100];
                cout << "Please enter the account number: ";
                if (cin >> accountno)
                {
                    if (accountno > 0)
                    {
                        check = 1;
                    }
                    else
                    {
                        cout << "\nInvalid input. Please enter a positive integer.\n";
                        cin.getline(trash, 100);
                    }
                }
                else
                {
                    cout << "\nInvalid input.\n";
                    cin.clear();
                    cin.getline(trash, 100);
                }
            }
            check = 0;
            cin.ignore();
            while (check == 0)
            {
                char trash [100];
                cout << "Please enter the name: ";
                cin.getline(name, 25);
                if (strlen(name) > 0)
                {
                    check = 1;
                }
                else
                {
                    cout << "\nInvalid input. Please enter a name.\n";
                    cin.getline(trash, 100);
                }
            }
            getaddress(address, 45);
            if (mylist.addRecord(accountno, name, address) == -1)
            {
                cout << "\nError: Record could not be added due to duplicate account number.\n\n";
                #ifdef DEBUG
                cout << "DEBUG | Attempted to pass parameters: " << accountno << name << address << endl;
                #endif
                cin.clear();
            }
            else
            {
                cout << "\nRecord added successfully to the database.\n\n";
            }
        }

        else if (strncmp(input, "printall", strlen(input)) == 0 && strlen(input) <= strlen("printall"))
        {
            mylist.printAllRecords();
            #ifdef DEBUG
            cout << "DEBUG | Successfully printed all records in list.\n";
            #endif
        }

        else if (strncmp(input, "find", strlen(input)) == 0 && strlen(input) <= strlen("find"))
        {
            check = 0;
            while (check == 0)
            {
                char trash [100];
                cout << "Please enter the account number: ";
                if (cin >> accountno)
                {
                    if (accountno > 0)
                    {
                        check = 1;
                    }
                    else
                    {
                        cout << "\nInvalid input. Please enter a positive integer.\n";
                        cin.getline(trash, 100);
                    }
                }
                else
                {
                    cout << "\nInvalid input.\n";
                    cin.clear();
                    cin.getline(trash, 100);
                }
            }
            if (mylist.findRecord(accountno) == -1)
            {
                cout << "Error: Record not found.\n";
                #ifdef DEBUG
                cout << "DEBUG | Attempted to pass parameter: " << accountno << endl;
                #endif
            }
        }
        else if (strncmp(input, "delete", strlen(input)) == 0 && strlen(input) <= strlen("delete"))
        {
            check = 0;
            while (check == 0)
            {
                char trash [100];
                cout << "Please enter the account number: ";
                if (cin >> accountno) {
                    if (accountno > 0)
                    {
                        check = 1;
                    }
                    else
                    {
                        cout << "\nInvalid input. Please enter a positive integer.\n";
                        cin.getline(trash, 100);
                    }
                }
                else
                {
                    cout << "\nInvalid input.\n";
                    cin.clear();
                    cin.getline(trash, 100);
                }
            }
            if (mylist.deleteRecord(accountno) == -1)
            {
                cout << "\nError: Record not found.\n";
                #ifdef DEBUG
                cout << "DEBUG | Attempted to pass parameter: " << accountno << endl;
                #endif
            }
            else
            {
                cout << "\nRecord deleted successfully from the database.\n";
            }
        }
        else if (strncmp(input, "exit", strlen(input)) == 0 && strlen(input) <= strlen("exit"))
        {
            quit = 1;
            cout << "Goodbye!\n";
        }
        else
        {
            cout << "\nInvalid input.\n";
        }
    }
    return 0;
}

/*****************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION:   Uses a loop that goes through every character
//                 that the user inputs and adds it to a character
//                 array until the user types in '%'.
//
//  Parameters:    address (char[]) : address array to be modified
//                 size (int): size of the array
//
****************************************************************/

void getaddress(char address[], int size)
{
    #ifdef DEBUG
    cout << "DEBUG | getaddress function called successfully\n";
    #endif
    int i = 0;
    int check = 0;
    char current;

    std::cout << "Please enter an address and type '%' when you are done: ";
    while (check == 0)
    {
        current = cin.get();
        if (current == '%')
        {
            check = 1;
        }
        else if (i < size - 1)
        {
            address[i] = current;
            i++;
        }
    }
    address[i] = '\0';
}