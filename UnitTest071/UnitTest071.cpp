#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.1rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest071
{
	TEST_CLASS(UnitTest071)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int rowCount = 3;
            const int colCount = 3;

            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                matrix[i] = new int[colCount];

            matrix[0][0] = -5; matrix[0][1] = 12; matrix[0][2] = -7;
            matrix[1][0] = 9; matrix[1][1] = 2; matrix[1][2] = -4;
            matrix[2][0] = 6; matrix[2][1] = 1; matrix[2][2] = -10;

            int S = 0; // Сума
            int k = 0; // Кількість

            // Виклик функції для обчислення суми і кількості елементів
            Calc(matrix, rowCount, colCount, S, k);

            // Перевірка результатів
            Assert::AreEqual(18, S); // Очікувана сума: 16 (9 + 6 + 1)
            Assert::AreEqual(7, k);  // Очікувана кількість: 4 (9, 6, 1, -5)

            // Перевірка того, що елементи були замінені на нулі
            Assert::AreEqual(0, matrix[0][0]);
            Assert::AreEqual(0, matrix[1][0]);
            Assert::AreEqual(0, matrix[2][0]);
            Assert::AreEqual(0, matrix[2][1]);

            // Очищення пам'яті
            for (int i = 0; i < rowCount; i++)
                delete[] matrix[i];
            delete[] matrix;
		}
	};
}
