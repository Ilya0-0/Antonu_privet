#include "filter.h"
#include <cstring>
#include <iostream>

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
