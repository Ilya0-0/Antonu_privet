#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/Confirence_program.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	// вспомогательная функция для создания одной записи на абонементе
	// так как для тестов необходимы лишь данные о дате выдачи и возврате книги,
	// данные о названии, авторе и читателе не заполняются
	Confirence_program* build_Confirence(int start_hour, int start_minutes, int finish_hour, int finish_minutes)
	{
		Confirence_program* Confirences = new Confirence_program;
		Confirences->start.hour = start_hour;
		Confirences->start.minutes = start_minutes;
		Confirences->finish.hour = finish_hour;
		Confirences->finish.minutes = finish_minutes;
		return Confirences;
	}

	// вспомогательная функция для удаления массива тестовых данных
	void delete_Confirence(Confirence_program* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}

	TEST_CLASS(unittestproject)
	{
	public:
		TEST_METHOD(TestMethod1) // время охватывает некий диапазон времени(часов)
		{
			Confirence_program* Confirence[3];
			Confirence[0] = build_Confirence(10, 10, 13, 10); // 2 часа
			Confirence[1] = build_Confirence(11, 10, 15, 10); // 4 часа
			Confirence[2] = build_Confirence(13, 30, 16, 30); // 3 часа
			Assert::AreEqual(240, process(Confirence, 3));
			delete_Confirence(Confirence, 3);
		}

		TEST_METHOD(TestMethod2) // время охватывает 1 час
		{
			Confirence_program* Confirence[3];
			Confirence[0] = build_Confirence(10, 10, 11, 10); // 1 час
			Confirence[1] = build_Confirence(11, 10, 12, 10); // 1 час
			Confirence[2] = build_Confirence(12, 30, 13, 30); // 1 час
			Assert::AreEqual(60, process(Confirence, 3));
			delete_Confirence(Confirence, 3);
		}

		TEST_METHOD(TestMethod3) // время до обеда/после обеда
		{
			Confirence_program* Confirence[2];
			Confirence[0] = build_Confirence(00, 00, 12, 00); // 12 часов 
			Confirence[1] = build_Confirence(12, 00, 23, 59); // 11 часов 59 минут
			Assert::AreEqual(720, process(Confirence, 2));
			delete_Confirence(Confirence, 2);
		}
	};
}