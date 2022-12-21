#pragma once
#ifndef FILE_LECTURER_H
#define FILE_LECTURER_H

#include "Confirence_program.h"
date convert(char* str);
void lect(const char* file_name, Confirence_program* array[], int& size);
int Confirence_program_time(Confirence_program* element);
#endif