#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(NULL, "Russian");
	string name;
	cout << "Hello,world!"<<endl;
	cout << "  ///" << endl;
	cout << " (*_*)" << endl;
	cout << "\\(__(>" << endl;
	cout << " /  \\" << endl;
	cout << "Введите ваше имя: ";
	cin >> name;
	cout << "Привет," << name << endl;
	return 0;
}