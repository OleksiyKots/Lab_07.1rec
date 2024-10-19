#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Рекурсивні функції для створення, друку, сортування та обчислення
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int** a, const int rowCount, const int colCount, int i = 0, int j = 0);
void Sort(int** a, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Change(int** a, const int col1, const int col2, const int rowCount, int i = 0);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);

int main()
{
    srand((unsigned)time(NULL));

    // Вхідні дані
    int Low = -34;
    int High = 26;
    int rowCount = 8;
    int colCount = 6;

    // Створення матриці
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // 1. Створення матриці з випадковими елементами
    Create(a, rowCount, colCount, Low, High);

    // Виведення початкової матриці
    cout << "Initial matrix:" << endl;
    Print(a, rowCount, colCount);
    cout << endl;

    // 2. Сортування матриці за заданими ключами
    Sort(a, rowCount, colCount);

    // Виведення відсортованої матриці
    cout << "Sorted matrix:" << endl;
    Print(a, rowCount, colCount);
    cout << endl;
    
    // 3. Обчислення суми та кількості елементів за критерієм (додатні або непарні)
    int S = 0; // Сума
    int k = 0; // Кількість
    Calc(a, rowCount, colCount, S, k);

    // Виведення результатів
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    // Виведення модифікованої матриці (після заміни елементів на нулі)
    cout << endl;
    cout << "Modified matrix" << endl;
    Print(a, rowCount, colCount);

    // Звільнення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Рекурсивне створення матриці з випадковими значеннями
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    if (i == rowCount)
        return;

    a[i][j] = Low + rand() % (High - Low + 1);

    if (j < colCount - 1)
        Create(a, rowCount, colCount, Low, High, i, j + 1);
    else
        Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

// Рекурсивне виведення матриці на екран
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
    if (i == rowCount)
        return;

    cout << setw(4) << a[i][j];

    if (j < colCount - 1)
        Print(a, rowCount, colCount, i, j + 1);
    else
    {
        cout << endl;
        Print(a, rowCount, colCount, i + 1, 0);
    }
}

// Рекурсивне сортування стовпців матриці за ключами
void Sort(int** a, const int rowCount, const int colCount, int i0, int i1)
{
    if (i0 == colCount - 1)
        return;

    if (i1 < colCount - i0 - 1)
    {
        if ((a[0][i1] < a[0][i1 + 1]) ||
            (a[0][i1] == a[0][i1 + 1] && a[1][i1] < a[1][i1 + 1]) ||
            (a[0][i1] == a[0][i1 + 1] && a[1][i1] == a[1][i1 + 1] && a[2][i1] < a[2][i1 + 1]))
        {
            Change(a, i1, i1 + 1, rowCount);
        }
        Sort(a, rowCount, colCount, i0, i1 + 1);
    }
    else
    {
        Sort(a, rowCount, colCount, i0 + 1, 0);
    }
}

// Рекурсивна функція перестановки стовпців
void Change(int** a, const int col1, const int col2, const int rowCount, int i)
{
    if (i == rowCount)
        return;

    int tmp = a[i][col1];
    a[i][col1] = a[i][col2];
    a[i][col2] = tmp;

    Change(a, col1, col2, rowCount, i + 1);
}

// Рекурсивна функція для обчислення суми і кількості елементів за критерієм та їх заміни на нулі
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
    if (i == rowCount)
        return;

    if (a[i][j] > 0 || a[i][j] % 2 != 0)
    {
        S += a[i][j]; // Додаємо елемент до суми
        k++;          // Збільшуємо кількість
        a[i][j] = 0;  // Заміна елемента на 0
    }

    if (j < colCount - 1)
        Calc(a, rowCount, colCount, S, k, i, j + 1);
    else
        Calc(a, rowCount, colCount, S, k, i + 1, 0);
}
