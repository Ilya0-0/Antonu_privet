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
	/********** ����� ������ ������� **********/
		   // ����� ����
	cout << "����� ������ �������: ";
	cout << setw(2) << setfill('0') << Confirence->start.hour << ':';
	// ����� �����
	cout << setw(2) << setfill('0') << Confirence->start.minutes;
	cout << '\n';
	/********** ����� ����� ������� **********/
		   // ����� ����
	cout << "���� ����� �������: ";
	cout << setw(2) << setfill('0') << Confirence->finish.hour << ':';
	// ����� �����
	cout << setw(2) << setfill('0') << Confirence->finish.minutes;
	cout << '\n';
	/********** ����� ������� **********/
	cout << "������: ";
	// ����� �������
	cout << Confirence->lecturer.last_name << " ";
	// ����� ������ ����� �����
	cout << Confirence->lecturer.first_name[0] << ". ";
	// ����� ������ ����� ��������
	cout << Confirence->lecturer.middle_name[0] << ".";
	cout << '\n';
	/********** ����� ���� ������� **********/
	cout << "���� �������: ";
	cout << '"' << Confirence->title << '"';
	cout << '\n';
	cout << '\n';
}
int main()
{
	setlocale(LC_ALL, "Russian");
	    cout << "������������ ������ �9. GIT\n";
	    cout << "������� �2. ��������� �����������\n";
	    cout << "�����: ���� �����\n\n";
	    cout << "������: XII\n";
	Confirence_program* Confirence[MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		lect("data.txt", Confirence, size);
		cout << "*****  ��������� �����������  *****\n\n";
		for (int i = 0; i < size; i++)
		{
			output(Confirence[i]);
		}
		bool (*check_function)(Confirence_program*) = NULL; // check_function -    ,    bool,
		//        book_subscription*
		cout << "\n�������� ������ ���������� ��� ��������� ������:\n";
		cout << "1)����� ���� �������� ������ ���� �����������\n";
		cout << "2)������� ��� ������� ������������� ������ 15 �����\n";
		cout << "3) ������������ ����� �������\n";
		cout << "\n������� ����� ���������� ������: ";
		int item;
		cin >> item;
		cout << '\n';
		switch (item)
		{
		case 1:
			check_function = check_Confirence_program_by_author;
			cout << "*****   ����� ���� �������� ������ ���� �����������   *****\n\n";
			break;
		case 2:
			check_function = check_Confirence_program_by_date; 
			cout << "*****  ������� ��� ������� ������������� ������ 15 �����  *****\n\n";
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
			cout << "***** ������������ ����� ������� *****\n\n";
			cout << hour<<":"<< minutes << "\n\n";
			break;
		}
		default:
			throw "������������ ����� ������";
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
