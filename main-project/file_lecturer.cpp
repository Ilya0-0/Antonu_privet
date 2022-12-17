#include "file_lecturer.h"
#include "constants.h"

#include <fstream>
#include <cstring>

date convert(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.hour = atoi(str_number);
    str_number = strtok_s(NULL, " ", &context);
    result.minutes = atoi(str_number);
    //str_number = strtok_s(NULL, ":", &context);
    return result;
}

void lect(const char* file_name, Confirence_program* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            Confirence_program* item = new Confirence_program;
            file >> item->lecturer.last_name;
            file >> item->lecturer.first_name;
            file >> item->lecturer.middle_name;
            file >> tmp_buffer;
            item->start = convert(tmp_buffer); 
            file >> tmp_buffer;
            item->finish = convert(tmp_buffer);
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->title, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}