// Lab_7_2-2.cpp
// < Кузів Назар >
// Лабораторна робота № 7.2-2
// Опрацювання багатовимірних масивів рекурсивним способом
// Варіант 6

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int MaxRow(int** R, const int rowNo, const int colCount, int colNo, int max);

void Create(int** R, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	R[i][j] = Low + rand() % (High - Low + 1);

	if (j < colCount - 1)
		Create(R, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(R, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** R, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << R[i][j];
	if (j < colCount - 1)
		Print(R, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(R, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
int MinofMax(int** R, const int rowCount, const int colCount, int rowNo, int min)
{
	int max = R[rowNo][0];
	max = MaxRow(R, rowNo, colCount, 1, max);

	if (rowNo == 0)
		 min = max;

	if (min > max)
		min = max;

	if (rowNo < rowCount - 1)
		MinofMax(R, rowCount, colCount, rowNo + 1, min);
	else
		return min;
}
int MaxRow(int** R, const int rowNo, const int colCount, int colNo, int max)
{
	if (R[rowNo][colNo] > max)
		max = R[rowNo][colNo];

	if (colNo < colCount - 1)
		MaxRow(R, rowNo, colCount, colNo + 1, max);
	else 
	{
		cout << "  Max = " << max << endl;
		return max;
	}
		

		
}

int main()
{
	srand((unsigned)time(NULL));

	//Діапазон значень елементів матриці
	int Low = -15;
	int	High = 15;

	int	rowCount = 5; // Кількість рядків
	int	colCount = 5; // Кількість стовпців


	int** R = new int* [rowCount];

	for (int i = 0; i < rowCount; i++)
		R[i] = new int[colCount];

	Create(R, rowCount, colCount, Low, High,0,0);
	Print(R, rowCount, colCount,0,0);
	cout << endl;

	int Min;
	Min = MinofMax(R, rowCount, colCount, 0, 0);

	cout << endl;
	cout << "  Min of Max = " << Min << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] R[i];
	delete[] R;

	return 0;
}

