---
layout: project
type: project
image: img/db.png
title: "Database Project"
date: 2025
published: true
labels:
  - C
  - C++
summary: "Created a bank database program in C and C++ for an ICS 212 project."
---

In the spring 2025 semester, I created a bank database program in C and C++ that stores user records locally within files that are managed through the user interface. The functions include adding, removing, deleting, and finding records within the database. 

Through this project, I gained a deeper understanding of linked lists, debugging, and handling edge cases. Below is one of the functions used within my program.


```cpp
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
```
