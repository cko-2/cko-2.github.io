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
//  DATE:        November 29, 2024
//
//  FILE:        record.h
//
//  DESCRIPTION:
//  header file contains the struct record, and the variables that are contained.
//
****************************************************************/
#ifndef RECORD_H
#define RECORD_H

struct record
{
    int accountno;
    char name[25];
    char address[45];
    struct record* next;
};

#endif