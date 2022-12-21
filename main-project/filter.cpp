#include "filter.h"
#include <cstring>
#include <iostream>
#include "Confirence_program.h"
#include <fstream>
using namespace std;

Confirence_program** filter(Confirence_program* array[], int size, bool (*check)(Confirence_program* element), int& result_size)
{
	Confirence_program** result = new Confirence_program * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_Confirence_program_by_author(Confirence_program* element)
{
	return strcmp(element->lecturer.first_name, "Илья") == 0 &&
		strcmp(element->lecturer.middle_name, "Васильевич") == 0 &&
		strcmp(element->lecturer.last_name, "Бутов") == 0;
}

bool check_Confirence_program_by_date(Confirence_program* element)
{
	return element->finish.minutes - element-> start.minutes > 15;
}
void sD(Confirence_program** report, int root, int bottom)
{
    int maxChild;
    int done = 0; 
  
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)   
            maxChild = root * 2;   
        else if (report[root * 2]->length < report[root * 2 + 1]->length)
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (report[root]->length > report[maxChild]->length)
        {
            std::swap(report[root], report[maxChild]);
            root = maxChild;
        }
        else 
            done = 1; 
    }
}
void heapSort(Confirence_program** report, int size)
{
   
    for (int i = (size / 2); i >= 0; i--)
        sD(report, i, size - 1);
   
    for (int i = size - 1; i >= 1; i--)
    {
        std::swap(report[0], report[i]);
        sD(report, 0, i - 1);
    }
}
void merge(Confirence_program** report, int size)
{
    int mid = size / 2; 
    if (size % 2 == 1)
        mid++;
    int h = 1; 
   
    Confirence_program** c = new Confirence_program * [size];
    int step;
    while (h < size)
    {
        step = h;
        int i = 0;   
        int j = mid; 
        int k = 0;   
        while (step <= mid)
        {
            while ((i < step) && (j < size) && (j < (mid + step)))
            { 
              
              
                if (report[i]->length > report[j]->length)
                {
                    c[k] = report[i];
                    i++; k++;
                }
                else {
                    c[k] = report[j];
                    j++; k++;
                }
            }
            while (i < step)
            {
                c[k] = report[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < size))
            { 
                c[k] = report[j];
                j++; k++;
            }
            step = step + h; 
        }
        h = h * 2;
        for (i = 0; i < size; i++)
            report[i] = c[i];
    }
}
void sD_str(Confirence_program** report, int root, int bottom)
{
    int maxChild; 
    int done = 0; 
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)  
            maxChild = root * 2;   

        else if (strlen(report[root * 2]->lecturer.last_name) > strlen(report[root * 2 + 1]->lecturer.last_name))
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (strlen(report[root]->lecturer.last_name) < strlen(report[maxChild]->lecturer.last_name))
        {
           
            std::swap(report[root], report[maxChild]);
            root = maxChild;
        }
        else 
            done = 1; 
    }
}
void heapSort_str(Confirence_program** report, int size)
{
  
    for (int i = (size / 2); i >= 0; i--)
        sD_str(report, i, size - 1);

    for (int i = size - 1; i >= 1; i--)
    {
        std::swap(report[0], report[i]);
        sD_str(report, 0, i - 1);
    }
}
void merge_str(Confirence_program** report, int size)
{
    int mid = size / 2;
    if (size % 2 == 1)
        mid++;
    int h = 1;
  
    Confirence_program** c = new Confirence_program * [size];
    int step;
    while (h < size)
    {
        step = h;
        int i = 0;   
        int j = mid; 
        int k = 0;   
        while (step <= mid)
        {
            while ((i < step) && (j < size) && (j < (mid + step)))
            { 
              
                if (strlen(report[i]->lecturer.last_name) < strlen(report[j]->lecturer.last_name))
                {
                    c[k] = report[i];
                    i++; k++;
                }
                else {
                    c[k] = report[j];
                    j++; k++;
                }
            }
            while (i < step)
            { 
                c[k] = report[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < size))
            { 
                c[k] = report[j];
                j++; k++;
            }
            step = step + h;
        }
        h = h * 2;
        for (i = 0; i < size; i++)
            report[i] = c[i];
    }
}
void title_sort(Confirence_program** report, int size)
{
    int i = 0;
    int buf;
    while (i < size)
    {
        int count = 0;
        char* lecturer = report[i]->lecturer.last_name;
        for (int j = 0; j < size; j++)
        {
            if (strcmp(report[j]->lecturer.last_name, lecturer) == 0)
                count++;
        }
        if (count == 1)
            i++;
        else
        {
            buf = i;
            Confirence_program** c = new Confirence_program * [count];
            for (int j = 0; j < count; j++)
            {
                c[j] = report[buf];
                buf++;
            }
            int min;
            for (int k = 0; k < count ; k++)
            {
                min = k;
                for (int j = k + 1; j < count; j++)
                {
                    if (strlen(c[j]->title) < strlen(c[min]->title))
                    {
                        min = j;
                    }
                }
                std::swap(c[k], c[min]);
            }
            for (int l = 0; l < count; l++)
            {
                report[i] = c[l];
                i++;
            }
        }
    }
}