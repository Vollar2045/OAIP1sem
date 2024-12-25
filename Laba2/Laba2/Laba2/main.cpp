#include <iostream>
#include <string>
#include <cstdlib>  

using namespace std;

double func1(double x, double y)
{
	double f;
	if (y == 0)
	{
		f = 0;
		return(f);
	}
	if (x == 0 && y!=0)
	{
		f = pow((pow(x, 2) + y), 3);
		return(f);
	}	
	if (x / y > 0)
	{
		f = log(x / y) + pow((pow(x,2) + y),3);
		return(f);
	}
	else if (x / y < 0)
	{
		f = log(fabs(x / y))+ pow((pow(x, 2) + y), 3);
		return(f);
	}
}

void func2(string card)
{
	int counter = 0;
	char x = 'X'; char h = 'H'; char y = 'Y'; char n = 'I';
	char q = '2'; char w = '3'; char e = '4'; char r = '5'; char t = '6'; char u = '7'; char o = '8'; char p = '9'; char a = 'T';
	char s = 'J'; char d = 'D'; char f = 'K'; char g = 'A';
	for (int i = 0; i < 2; i++)
	{
		if (card[i] == q)
		{
			cout << "Двойка "; counter = 1; break;
		}
		if (card[i] == w)
		{
			cout << "Три "; counter = 1; break;
		}
		if (card[i] == e)
		{
			cout << "Четыре "; counter = 1; break;
		}
		if (card[i] == r)
		{
			cout << "Пять "; counter = 1; break;
		}
		if (card[i] == t)
		{
			cout << "Шесть "; counter = 1; break;
		}
		if (card[i] == u)
		{
			cout << "Семь "; counter = 1; break;
		}
		if (card[i] == o)
		{
			cout << "Восемь "; counter = 1; break;
		}
		if (card[i] == p)
		{
			cout << "Девять "; counter = 1; break;
		}
		if (card[i] == a)
		{
			cout << "Десять "; counter = 1; break;
		}
		if (card[i] == s)
		{
			cout << "Валет "; counter = 1; break;
		}
		if (card[i] == d)
		{
			cout << "Дама "; counter = 1; break;
		}
		if (card[i] == f)
		{
			cout << "Король "; counter = 1; break;
		}
		if (card[i] == g)
		{
			cout << "Туз "; counter = 1; break;
		}
		if(i==1&&counter==0) cout << "Вы ввели неправильное описание карты. " << endl;
	}
	for (int i = 0; i < 2 && counter==1; i++)
	{	
		if (card[i] == x)
		{
			cout << "крести"; break;
		}
		if (card[i] == h)
		{
			cout << "бубны"; break;
		}
		if (card[i] == y)
		{
			cout << "черви"; break;
		}
		if (card[i] == n)
		{
			cout << "пики"; break;
		}		
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c;
	int repeat=0;
	cout << "Введите первое число: " << endl;
	cin >> a;
	cout << "Введите второе число: " << endl;
	cin >> b;
	if (a > b)  cout <<"Наибольшим является число a=" << a << endl;
	if (a < b)  cout <<"Наибольшим является число b=" << b << endl;
	if (a == b) cout << "a=b" << endl;	
	while (repeat == 0)
	{
		cout << "Введите номер дня недели: " << endl;
		cin >> c;
		switch (c)
		{
		case(1):
			cout << "Понедельник " << endl;
			repeat = 1;
			break;
		case(2):
			cout << "Вторник " << endl;
			repeat = 1;
			break;
		case(3):
			cout << "Среда " << endl;
			repeat = 1;
			break;
		case(4):
			cout << "Четверг " << endl;
			repeat = 1;
			break;
		case(5):
			cout << "Пятница " << endl;
			repeat = 1;
			break;
		case(6):
			cout << "Суббота " << endl;
			repeat = 1;
			break;
		case(7):
			cout << "Воскресенье " << endl;
			repeat = 1;
			break;
		default:
			cout << "Вы ввели неверный номер дня недели" << endl;			
		}
	}
	double x,y,f;
	cout << endl<< "Введите x: ";
	cin >> x ;
	cout <<endl<<"Введите y: ";
	cin >> y;
	f=func1(x,y);
	cout <<endl<< "f= "<< f;
	string card;
	cout << endl << "Введите описание карты,состоящее из двух букв: ";
	cin>>card;
	func2(card);
	return 0;
}