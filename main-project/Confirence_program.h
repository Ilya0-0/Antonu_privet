#pragma once
#ifndef Confirence_program_H
#define Confirence_program_H

#include "constants.h"

struct date
{
    int hour;
    int minutes;
};

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct Confirence_program
{
    person lecturer;
    date start;
    date finish;
    char title[MAX_STRING_SIZE];
};

#endif
