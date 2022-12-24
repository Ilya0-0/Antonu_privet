#include "processing.h"
// функция вычисляет количество дней, прошедших с 1 января 1-го года н. э. до заданной даты
int time(date d)
{
	int result = 60 * d.hour + d.minutes;
	return result;
}

// функция вычисляет количество дней, прошедших между указанными датами
int diff(date a, date b)
{
	int x = time(a);
	int y = time(b);
	return (x > y ? x - y : y - x);
}

int process(Confirence_program* array[], int size)
{
	int max = diff(array[0]->start, array[0]->finish);
	for (int i = 1; i < size; i++)
	{
		int curr = diff(array[i]->start, array[i]->finish);
		if (curr > max)
		{
			max = curr;
		}
	}
	return max;
}
