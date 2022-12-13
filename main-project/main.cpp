#include <iostream>

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
        for (int i = 0; i < size; i++)
        {
            cout << Confirence[i]->lecturer.last_name << '\n';
            cout << Confirence[i]->lecturer.first_name << '\n';
            cout << Confirence[i]->lecturer.middle_name << '\n';
            cout << Confirence[i]->finish.hour << ' ';
            cout << Confirence[i]->finish.minutes << '\n';
            cout << Confirence[i]->start.hour << ' ';
            cout << Confirence[i]->start.minutes << '\n';
            cout << Confirence[i]->title << '\n';
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