#include <iostream>
#include <iomanip>

using namespace std;

#include "Confirence_program.h"
#include "file_lecturer.h"
#include "constants.h"
#include "filter.h"
#include "processing.h"


void output(Confirence_program* Confirence)
{
	/********** вывод начала доклада **********/
		   // вывод часа
	cout << "Время начала доклада: ";
	cout << setw(2) << setfill('0') << Confirence->start.hour << ':';
	// вывод минут
	cout << setw(2) << setfill('0') << Confirence->start.minutes;
	cout << '\n';
	/********** вывод конца доклада **********/
		   // вывод часа
	cout << "Дата конца доклада: ";
	cout << setw(2) << setfill('0') << Confirence->finish.hour << ':';
	// вывод минут
	cout << setw(2) << setfill('0') << Confirence->finish.minutes;
	cout << '\n';
	/********** вывод лектора **********/
	cout << "Лектор: ";
	// вывод фамилии
	cout << Confirence->lecturer.last_name << " ";
	// вывод первой буквы имени
	cout << Confirence->lecturer.first_name[0] << ". ";
	// вывод первой буквы отчества
	cout << Confirence->lecturer.middle_name[0] << ".";
	cout << '\n';
	/********** вывод темы доклада **********/
	cout << "Тема доклада: ";
	cout << '"' << Confirence->title << '"';
	cout << '\n';
	cout << '\n';
}
int main()
{
	setlocale(LC_ALL, "Russian");
	    cout << "Лабораторная работа №9. GIT\n";
	    cout << "Вариант №2. Программа конференций\n";
	    cout << "Автор: Илья Бутов\n\n";
	    cout << "Группа: XII\n";
	Confirence_program* Confirence[MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		lect("data.txt", Confirence, size);
		cout << "*****  Программа конференций  *****\n\n";
		for (int i = 0; i < size; i++)
		{
			output(Confirence[i]);
		}
		bool (*check_function)(Confirence_program*) = NULL; // check_function -    ,    bool,
		//        book_subscription*
		cout << "\nВыберите способ фильтрации или обработки данных:\n";
		cout << "1)Вывод всех докладов Бутова Ильи Васильевича\n";
		cout << "2)Вывести все доклады длительностью больше 15 минут\n";
		cout << "3) Максимальное время доклада\n";
		cout << "\nВведите номер выбранного пункта: ";
		int item;
		cin >> item;
		cout << '\n';
		switch (item)
		{
		case 1:
			check_function = check_Confirence_program_by_author;
			cout << "*****   Вывод всех докладов Бутова Ильи Васильевича   *****\n\n";
			break;
		case 2:
			check_function = check_Confirence_program_by_date; 
			cout << "*****  Вывести все доклады длительностью больше 15 минут  *****\n\n";
			break;
		case 3:
		{
			int days = process(Confirence, size);
			int hour = 0, minutes;
			while (days > 60)
			{
				days = days - 60;
				hour++;
			}
			minutes = days;
			cout << "***** Максимальное время доклада *****\n\n";
			cout << hour<<":"<< minutes << "\n\n";
			break;
		}
		default:
			throw "Некорректный номер пункта";
		}
		if (check_function)
		{
			int new_size;
			Confirence_program** filtered = filter(Confirence, size, check_function, new_size);
			for (int i = 0; i < new_size; i++)
			{
				output(filtered[i]);
			}
			delete[] filtered;
		}
		for (int i = 0; i < size; i++)
		{
			delete Confirence[i];
		}
	}
	catch (const char* error)
	{
		cout << error << '\n';
	}
	return 0;
}
