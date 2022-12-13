#include <iostream>
#include <iomanip>

using namespace std;

#include "Confirence_program.h"
#include "file_lecturer.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �9. GIT\n";
    cout << "������� �2. ��������� �����������\n";
    cout << "�����: ���� �����\n\n";
    Confirence_program* Confirence[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        lect("data.txt", Confirence, size);
        cout << "***** ��������� ����������� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** ����� ������� **********/
            cout << "������........: ";
            // ����� �������
            cout << Confirence[i]->lecturer.last_name << " ";
            // ����� ������ ����� �����
            cout << Confirence[i]->lecturer.first_name << ". ";
            // ����� ������ ����� ��������
            cout << Confirence[i]->lecturer.middle_name << ".";
            cout << '\n';
            /********** ����� ����� ������� **********/
            // ����� ����
            cout << "���� ����� �������...: ";
            cout << setw(4) << setfill('0') << Confirence[i]->finish.hour << ':';
            // ����� �����
            cout << setw(2) << setfill('0') << Confirence[i]->finish.minutes;
            cout << '\n';
            /********** ����� ������ ������� **********/
            // ����� ����
            cout << "����� ������ �������.....: ";
            cout << setw(4) << setfill('0') << Confirence[i]->start.hour << ':';
            // ����� �����
            cout << setw(2) << setfill('0') << Confirence[i]->start.minutes;
            cout << '\n';
            /********** ����� ���� ������� **********/
            cout << "���� �������...........: ";
            cout << '"' << Confirence[i]->title << '"';
            cout << '\n';
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