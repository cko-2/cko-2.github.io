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
//  FILE:        llist.h
//
//  DESCRIPTION:
//  header file contains the llist class, which has variable
//  and function declarations to be defined in llist.cpp
//
****************************************************************/

#ifndef LLIST_H
#define LLIST_H

#include "record.h"

class llist
{
private:
    record* start;
    char filename[20];

    int readfile();
    int writefile();
    void cleanup();

public:
    llist();
    llist(const char[]);
    ~llist();
    int addRecord(int, char[], char[]);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
};

#endif