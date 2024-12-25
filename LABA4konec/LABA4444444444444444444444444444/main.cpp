#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

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
		if (N[i] < '1' || N[i]>'7')
		{
			return false;
		}
	}
	return true;
}

void func1()    // Гипотенуза по двум катетам
{
	string str1, str2; int N1,N2; double S;
	do
	{
		cout << "\nВведите длину 1 катета: ";
		cin >> str1;
		if (checkInt(str1) && str1.size() < 10)
		{
			N1 = stoi(str1);			
		}
	} while (!checkInt(str1) || str1.size() > 10 || N1 <= 0);
	do
	{
		cout << "\nВведите длину 2 катета: ";
		cin >> str2;
		if (checkInt(str2) && str2.size() < 10)
		{
			N2 = stoi(str2);			
		}
	} while (!checkInt(str2) || str2.size() > 10 || N2 <= 0);
	S = sqrt(pow(N1, 2) + pow(N2, 2));
	cout << endl<<  "Гипотенуза равна " << S << endl;
}

void func2() // Площадь круга
{
	string str; double R; double Pi = 3.141592;
	do
	{
		cout << "\nВведите радиус круга: ";
		cin >> str;
		if (checkInt(str) && str.size() < 10)
		{
			R = stoi(str);
		}
	} while (!checkInt(str) || str.size() > 10 || R <= 0);
	R = Pi * pow(R, 2);
	cout << endl << "Площадь равна " << R << endl;
}

int* func3(int arr[][4]) // Вернуть одномерный массив, состоящий из элементов главной диагонали массива
{	
	int* a = new int[4];
	for (int i = 0; i < 4; i++)
	{
		a[i] = arr[i][i]; // Заполнение массива элементами главной диагонали
	}
	cout << endl;	
	return (a);
}

int func4(int n)   //рекурсивно факториал 
{
	if (n <= 1) return 1;
	return n * func4(n - 1);
}

void func5(int arr[],int n)   //двигать массив влево вправо
{
	string lr; int l;
	do
	{
		cout << endl << "Двигать влево - 1, вправо - 0: ";
		cin >> lr; cout << endl;
		if (checkInt(lr) && lr.size() < 10)
		{
			l = stoi(lr);
		}
	} while (!checkInt(lr) || lr.size() > 10 || l < 0 || l>1);
	switch (l)
	{
	case 1:
	{
		int tmp = arr[0];
		for (int i = 0; i < n - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = tmp;
		break;
	}
	case 0:
		int tmp = arr[n-1];
		for (int i = n-1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = tmp;
		break;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int main()
{
	setlocale(NULL, "Rus");	
	int m; int v; string str; int b[5]{ 1,2,3,4,5 }; int a[4]{}; int arr[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
	do
	{	
		cout << "1)Найти длину гипотенузы по двум катетам";
		cout << endl << "2)Вычислить площадь круга";
		cout << endl << "3)Задача с массивами";
		cout << endl << "4)Вычислить факториал рекурсивно";
		cout << endl << "5)Циклический сдвиг массива влево либо вправо";
		cout << endl << "6)Выйти из программы" << endl;;
		cin >> str; cout << endl;
		if (checkMenu(str))
		{
			m = stoi(str);
			switch (m)
			{
			    case 1: func1(); break;
				case 2: func2(); break;
				case 3:
				{
					int* ptr = func3(arr);
					for (int i = 0; i < 4; i++)
					{
						cout << ptr[i] << '\t';
					}
					break;
				}
				case 4:
				{
					do
					{
						cout << "\nВведите число: "; 
						cin >> str; cout << endl;
						if (checkInt(str) && str.size() < 10)
						{
							v = stoi(str);
						}
					} while (!checkInt(str) || str.size() > 10 || v <= 0);
					cout << endl << func4(v);
					break;
				}
				case 5: func5(b,5); break;
				case 6: break;
			}
			cout << endl << endl;
		}
	} while (!checkMenu(str) || m != 6);
	return 0;
}