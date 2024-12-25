#include <iostream>
#include <cstdlib>
#include <string>

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
		if (N[0]!='-')
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

int func1() //Найти произведение числа N<4 и предыдущих 4 чисел
{
	string str; int N ;
	do
	{
		cout << "\nВведите число N>4: ";
		cin >> str;
		if (checkInt(str) && str.size() < 10)
		{
			N = stoi(str);
			if (N <= 4)
			{
				cout << "Вы ввели неверное значение." << endl;
			}
		}
	} while (!checkInt(str) || str.size()>10 || N<=4);	
	int S = N;
	for (int i = 0; i < 4; i++)
	{
		S = S * (N - (i + 1));
	}
	cout << "Произведение равно " << S << endl << endl;
	return 0;
}

void func2() //Складывать числа 1, 2, и т.д., пока сумма не превысит 100
{
	int S = 0;
	for (int i = 0; S < 100; i++)
	{
		S += i;
		if (S > 100)
		{
			S = S - i;
			break;
		}
	}
	cout << "Сумма равна " << S << endl << endl;;
}

int func3() //3)Ввести целое число N > 0. Найти произведение: N! = 1 ∙ 2 ∙ ... ∙ N
{
	string str;	int F = 1; int N;
	do
	{
		cout << "\nВведите целое число N>0: ";
		cin >> str;
		if (checkInt(str) && str.size() < 10)
		{
			N = stoi(str);
			if (N <= 0)
			{
				cout << "Вы ввели неверное значение." << endl;
			}
		}
	} while (!checkInt(str) || str.size() > 10 || N <= 0);	
	for (int i = 1; i < N; i++)
	{
		F *= (i + 1);
	}
	cout << endl << "N!= " << F << endl;
	return 0;
}

int func4()  //Ввести число N > 1. Вывести наибольшее из целых чисел K, для которых сумма 1 + 1 / 2 + ⋯ + 1 / K < N, а также сумму
{
	float S = 0.0; int N = 0; float K = 1;
	string str;
	do
	{
		cout << "\nВведите число N>1: ";
		cin >> str;
		if (checkInt(str) && str.size() < 10)
		{
			N = stoi(str);
			if (N <= 1)
			{
				cout << "Вы ввели неверное значение." << endl;
			}
		}
	} while (!checkInt(str) || str.size() > 10 || N <= 1);
	while (S < N)
	{
		S = S + (1 / K);
		if (S >= N)
		{
			S = S - (1 / K);
			cout << endl << "Наибольшее из целых чисел K= " << K << endl;
			cout << "Сумма равна " << S << endl;
			break;
		}
		K++;
	}
	return 0;
}

void func5()  //Ввести последовательность целых ненулевых чисел. Признак завершения последовательности - значение 0. 
{             //Найти сумму отрицательных членов
	const int max = 10; int N[max] = { 0 }; int S = 0; string str; int i = 0;
	do
	{
		cout << "Введите целое число != 0: " << endl;
		cin >> str;
		if (checkMinusInt(str) && str.size() < 10)
		{
			N[i] = stoi(str);			
			if (N[i] == 0) break;
			i++;
		}
		else
		{
			cout << "error" << endl;
		}
	} while (!checkMinusInt(str) || str.size() > 10 || i!=max);
	for (int i = 0; i < max; i++)
	{
		cout << N[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < max; i++)
	{
		if (N[i] < 0) S += N[i];
	}
	cout << "Сумма отрицательных членов равна " << S << endl << endl; 	
}

int main()
{
	setlocale(NULL, "Russian");
	int m; string str;
	do
	{
		cout << "Выберите номер задания:\n1)Найти произведение N>4\n2)Складывать числа 1, 2, и т.д., пока сумма не превысит 100\n";
		cout << "3)Ввести целое число N > 0. Найти произведение: N! = 1 ∙ 2 ∙ ... ∙ N\n";
		cout << "4)Ввести число N > 1. Вывести наибольшее из целых чисел K, для которых сумма 1 + 1 / 2 + ⋯ + 1 / K < N, а также сумму\n";
		cout << "5)Ввести последовательность целых ненулевых чисел. Признак завершения последовательности - значение 0. Найти сумму отрицательных членов\n";
		cout << "6)Выйти из программы\nНомер:";
		cin >> str;
		if (checkMenu(str))
		{
			m = stoi(str);
			switch (m)
			{
			case 1: func1(); break;
			case 2: func2(); break;
			case 3: func3(); break;
			case 4: func4(); break;
			case 5: func5(); break;
			case 6: break;
			}
		}
	} while (!checkMenu(str) || m != 6);	
	return 0;
}