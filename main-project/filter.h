#pragma once
#ifndef FILTER_H
#define FILTER_H
#include "Confirence_program.h"
Confirence_program** filter(Confirence_program* array[], int size, bool (*check)(Confirence_program* element), int& result_size);
bool check_Confirence_program_by_author(Confirence_program* element);
bool check_Confirence_program_by_date(Confirence_program* element);
void sD(Confirence_program** report, int root, int bottom);
void heapSort(Confirence_program** report, int size);
void merge(Confirence_program** report, int size);
void sD_str(Confirence_program** report, int root, int bottom);
void heapSort_str(Confirence_program** report, int size);
void merge_str(Confirence_program** report, int size);
void title_sort(Confirence_program** report, int size);
#endif
