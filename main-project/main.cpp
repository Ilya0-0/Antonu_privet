#include <iostream>
#include <iomanip>

using namespace std;

#include "Confirence_program.h"
#include "file_lecturer.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №9. GIT\n";
    cout << "Вариант №2. Программа конференций\n";
    cout << "Автор: Илья Бутов\n\n";
    Confirence_program* Confirence[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        lect("data.txt", Confirence, size);
        cout << "***** Программа конференций *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод лектора **********/
            cout << "Лектор........: ";
            // вывод фамилии
            cout << Confirence[i]->lecturer.last_name << " ";
            // вывод первой буквы имени
            cout << Confirence[i]->lecturer.first_name << ". ";
            // вывод первой буквы отчества
            cout << Confirence[i]->lecturer.middle_name << ".";
            cout << '\n';
            /********** вывод конца доклада **********/
            // вывод часа
            cout << "Дата конца доклада...: ";
            cout << setw(4) << setfill('0') << Confirence[i]->finish.hour << ':';
            // вывод минут
            cout << setw(2) << setfill('0') << Confirence[i]->finish.minutes;
            cout << '\n';
            /********** вывод начала доклада **********/
            // вывод часа
            cout << "Время начала доклада.....: ";
            cout << setw(4) << setfill('0') << Confirence[i]->start.hour << ':';
            // вывод минут
            cout << setw(2) << setfill('0') << Confirence[i]->start.minutes;
            cout << '\n';
            /********** вывод темы доклада **********/
            cout << "Тема доклада...........: ";
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