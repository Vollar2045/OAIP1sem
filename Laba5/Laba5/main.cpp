#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

bool checkInt(string N)
{
	for (int i = 0; i < N.size(); i++)
	{
		if (N[i] < '0' || N[i]>'9')
		{
			return false;
		}
	}
	return true;
}

bool checkMinusInt(string N)
{
	for (int i = 0; i < N.size(); i++)
	{
		if (N[0] != '-')
		{
			if (N[i] < '0' || N[i]>'9')
			{
				return false;
			}
			else
			{
				continue;
			}
		}                                         //если первый символ - это не минус
		if (N[0] == '-')
		{
			if (i == 0)
			{
				int k = 1;
				if (N[k] < '0' || N[k]>'9') return false;
				else continue;
			}
			if (N[i] < '0' || N[i]>'9') return false;
			else continue;					     //если первый символ - это минус
		}
	}
	return true;
}

bool checkMenu(string N)
{
	for (int i = 0; i < N.size(); i++)
	{
		if (N[i] < '1' || N[i]>'6')
		{
			return false;
		}
	}
	return true;
}

bool checkPoint(string N);

void func1(int arr[], int n)                          //Дан целочисленный массив размера N. Вывести все нечётные числа в
{                                  //данном массиве в порядке возрастания их индексов, атакже их количество.
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0)
		{
			count++;
			cout << arr[i] << '\t';
		}
	}
	cout << endl << "Кол-во нечетных чисел = " << count << endl;
}

void func2(int arr[], int n)         //Задан целочисленный массив размера N. Определить количество положительных чисел массива
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			count++;
		}
	}
	cout << endl << "Кол-во положительных чисел = " << count << endl;
}

void func3(double* arr, int& n)     ////Задан вещественный массив размера N. Перед каждым положительным элементом массива вставить нулевой элемент.
{
	const int maxSize = 2 * n;
	double* newArr = new double[maxSize];
	int newSize = 0;
	double zeroElement = 0.0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > 0) {

			newArr[newSize++] = zeroElement;
		}

		newArr[newSize++] = arr[i];
	}
	for (int i = 0; i < newSize; ++i) {
		arr[i] = newArr[i];
	}
	n = newSize;
	delete[] newArr;
}

int main()
{
	int m; string str;
	const int N = 5; const int M = 3; int NN = 5; int MM = 3; double* arr = new double[2 * N] {-1.5, 2.4, 3.1, 4.5, 0};
	int array[N][M]{};
	setlocale(NULL, "Rus");
	srand(time(0));
	if (arr == nullptr)
	{
		cout << "Нехватка памяти" << endl;
		return -1;
	}
	do
	{
		int i = 0; int a[N]{};
		cout << "1)Дан целочисленный массив размера N. Вывести все нечётные числа в данном массиве в порядке возрастания их индексов, а также их количество.";
		cout << endl << "2)Задан целочисленный массив размера N. Определить количество положительных чисел массива.";
		cout << endl << "3)Задан вещественный массив размера N. Перед каждым положительным элементом массива вставить нулевой элемент.";
		cout << endl << "4)Сформировать целочисленную матрицу размера N × M, у которой все элементы I - й строки имеют значение 10 ∙ I(I = 1, 2, ..., N).";
		cout << endl << "5)Задана целочисленная матрица размером N × M.Поменять местами максимальный и минимальный элемент каждой строки матрицы.";
		cout << endl << "6)Выйти из программы" << endl;;
		cin >> str; cout << endl;
		if (checkMenu(str))
		{
			m = stoi(str);
			switch (m)
			{
			case 1:
			{           //Дан целочисленный массив размера N. Вывести все нечётные числа в
				do		 //данном массиве в порядке возрастания их индексов, атакже их количество. 				
				{
					cout << "Введите целое число: " << endl;
					cin >> str;
					if (checkMinusInt(str) && str.size() < 10)
					{
						a[i] = stoi(str);
						i++;
					}
					else
					{
						cout << "Ошибка ввода" << endl;
					}
				} while (!checkMinusInt(str) || str.size() > 10 || i < N);
				func1(a, N);
				break;
			}
			case 2:               //Задан целочисленный массив размера N. Определить количество положительных чисел массива.
			{
				do
				{
					cout << "Введите целое число: " << endl;
					cin >> str;
					if (checkMinusInt(str) && str.size() < 10)
					{
						a[i] = stoi(str);
						i++;
					}
					else
					{
						cout << "Ошибка ввода" << endl;
					}
				} while (!checkMinusInt(str) || str.size() > 10 || i < N);
				func2(a, N);
				break;
			}
			case 3:   //Задан вещественный массив размера N. Перед каждым положительным элементом массива вставить нулевой элемент.
			{
				cout << "Изначальный массив: ";
				for (int i = 0; i < NN; ++i)
				{
					cout << arr[i] << " ";
				}
				cout << endl;
				func3(arr, NN);
				cout << "Измененный массив: ";
				for (int i = 0; i < NN; ++i)
				{
					cout << arr[i] << " ";
				}
				cout << endl;
				delete[] arr;
				break;
			}
			case 4:   //Сформировать целочисленную матрицу размера N × M, у которой все элементы I - й строки имеют значение 10 ∙ I(I = 1, 2, ..., N).
			{
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < M; j++)
					{
						cout << (array[i][j] = (i + 1) * 10) << '\t';
					}
					cout << endl;
				}
				break;
			}
			case 5:   //Задана целочисленная матрица размером N × M.Поменять местами максимальный и минимальный элемент каждой строки матрицы.
			{
				int** array4 = new int* [NN];
				for (int i = 0; i < NN; i++)
				{
					array4[i] = new int[M];
				}
				for (int i = 0; i < NN; ++i)
				{
					for (int j = 0; j < MM; ++j)
					{
						array4[i][j] = rand() % 10 + 1;
					}
				}
				cout << "Изначальная матрица:" << endl;
				for (int i = 0; i < NN; ++i)
				{
					for (int j = 0; j < MM; ++j)
					{
						cout << array4[i][j] << " ";
					}
					cout << endl;
				}
				for (int i = 0; i < NN; ++i)
				{
					int minIndex = 0;
					int maxIndex = 0;
					for (int j = 0; j < M; ++j)
					{
						if (array4[i][j] > array4[i][maxIndex])
						{
							maxIndex = j;
						}
						if (array4[i][j] < array4[i][minIndex])
						{
							minIndex = j;
						}
					}
					swap(array4[i][maxIndex], array4[i][minIndex]);
				}
				cout << "Измененная матрица:" << endl;
				for (int i = 0; i < NN; ++i)
				{
					for (int j = 0; j < MM; ++j)
					{
						cout << array4[i][j] << " ";
					}
					cout << endl;
				}
				for (int i = 0; i < NN; i++)
				{
					delete[] array4[i];
				}
				delete[] array4;
			}
			break;
			}
		}
	} while (!checkMenu(str) || m != 6);
	return 0;
}
