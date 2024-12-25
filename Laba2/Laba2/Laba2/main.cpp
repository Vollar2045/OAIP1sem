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
			cout << "������ "; counter = 1; break;
		}
		if (card[i] == w)
		{
			cout << "��� "; counter = 1; break;
		}
		if (card[i] == e)
		{
			cout << "������ "; counter = 1; break;
		}
		if (card[i] == r)
		{
			cout << "���� "; counter = 1; break;
		}
		if (card[i] == t)
		{
			cout << "����� "; counter = 1; break;
		}
		if (card[i] == u)
		{
			cout << "���� "; counter = 1; break;
		}
		if (card[i] == o)
		{
			cout << "������ "; counter = 1; break;
		}
		if (card[i] == p)
		{
			cout << "������ "; counter = 1; break;
		}
		if (card[i] == a)
		{
			cout << "������ "; counter = 1; break;
		}
		if (card[i] == s)
		{
			cout << "����� "; counter = 1; break;
		}
		if (card[i] == d)
		{
			cout << "���� "; counter = 1; break;
		}
		if (card[i] == f)
		{
			cout << "������ "; counter = 1; break;
		}
		if (card[i] == g)
		{
			cout << "��� "; counter = 1; break;
		}
		if(i==1&&counter==0) cout << "�� ����� ������������ �������� �����. " << endl;
	}
	for (int i = 0; i < 2 && counter==1; i++)
	{	
		if (card[i] == x)
		{
			cout << "������"; break;
		}
		if (card[i] == h)
		{
			cout << "�����"; break;
		}
		if (card[i] == y)
		{
			cout << "�����"; break;
		}
		if (card[i] == n)
		{
			cout << "����"; break;
		}		
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c;
	int repeat=0;
	cout << "������� ������ �����: " << endl;
	cin >> a;
	cout << "������� ������ �����: " << endl;
	cin >> b;
	if (a > b)  cout <<"���������� �������� ����� a=" << a << endl;
	if (a < b)  cout <<"���������� �������� ����� b=" << b << endl;
	if (a == b) cout << "a=b" << endl;	
	while (repeat == 0)
	{
		cout << "������� ����� ��� ������: " << endl;
		cin >> c;
		switch (c)
		{
		case(1):
			cout << "����������� " << endl;
			repeat = 1;
			break;
		case(2):
			cout << "������� " << endl;
			repeat = 1;
			break;
		case(3):
			cout << "����� " << endl;
			repeat = 1;
			break;
		case(4):
			cout << "������� " << endl;
			repeat = 1;
			break;
		case(5):
			cout << "������� " << endl;
			repeat = 1;
			break;
		case(6):
			cout << "������� " << endl;
			repeat = 1;
			break;
		case(7):
			cout << "����������� " << endl;
			repeat = 1;
			break;
		default:
			cout << "�� ����� �������� ����� ��� ������" << endl;			
		}
	}
	double x,y,f;
	cout << endl<< "������� x: ";
	cin >> x ;
	cout <<endl<<"������� y: ";
	cin >> y;
	f=func1(x,y);
	cout <<endl<< "f= "<< f;
	string card;
	cout << endl << "������� �������� �����,��������� �� ���� ����: ";
	cin>>card;
	func2(card);
	return 0;
}