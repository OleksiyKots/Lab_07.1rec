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

            int S = 0; // ����
            int k = 0; // ʳ������

            // ������ ������� ��� ���������� ���� � ������� ��������
            Calc(matrix, rowCount, colCount, S, k);

            // �������� ����������
            Assert::AreEqual(18, S); // ��������� ����: 16 (9 + 6 + 1)
            Assert::AreEqual(7, k);  // ��������� �������: 4 (9, 6, 1, -5)

            // �������� ����, �� �������� ���� ������ �� ���
            Assert::AreEqual(0, matrix[0][0]);
            Assert::AreEqual(0, matrix[1][0]);
            Assert::AreEqual(0, matrix[2][0]);
            Assert::AreEqual(0, matrix[2][1]);

            // �������� ���'��
            for (int i = 0; i < rowCount; i++)
                delete[] matrix[i];
            delete[] matrix;
		}
	};
}
