#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int K, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, K, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, K, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int N, const int K, int rowNo)
{
    PrintRow(a, rowNo, K, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, K, rowNo + 1);
    else
        cout << endl;
}

void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int FindMaxInRow(int** a, int row, int colCount, int currentCol, int maxCol)
{
    if (currentCol >= colCount)
        return maxCol;

    if (a[row][currentCol] > a[row][maxCol])
        maxCol = currentCol;

    return FindMaxInRow(a, row, colCount, currentCol + 1, maxCol);
}

void MoveMaxToDiagonal(int** a, int n, int row)
{
    if (row >= n)
        return;

    int maxCol = FindMaxInRow(a, row, n, 0, 0);
    if (maxCol != row)
        Swap(a[row][row], a[row][maxCol]);

    MoveMaxToDiagonal(a, n, row + 1);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned>(time(nullptr)));

    int Low = -34;
    int High = 26;
    int n;

    cout << " n = ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    CreateRows(a, n, n, Low, High, 0);
    PrintRows(a, n, n, 0);

    MoveMaxToDiagonal(a, n, 0);
    PrintRows(a, n, n, 0);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
