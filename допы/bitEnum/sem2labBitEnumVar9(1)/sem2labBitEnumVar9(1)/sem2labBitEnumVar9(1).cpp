#include<iostream>    
#include<iomanip>
#include<clocale>
#include<windows.h>
#include<string>
using namespace std;
int new_tvr();
int show_position();
int del();
void search();
int number(0);
enum edays
{
	Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
} days;

struct vokzal
{
	int number;
	char punkt[20];
	string dni;
	int vrprib;
	int vrotpr;
	unsigned ohours : 5;
	unsigned ominutes : 6;
	unsigned phours : 5;
	unsigned pminutes : 6;
} delt;
vokzal a[5];
int main()
{
	setlocale(LC_ALL, "Russian");
	int i, b, c; char z = '_', q = ' ', v = '=';
	do
	{
		cout << "\n Выберите действие:\n";
		cout << "1 - Удаление записи(ей)\n";
		cout << "2 - Ввод новой записи\n";
		cout << "3 - Вывод записи(ей)\n";
		cout << "4 - Поиск записей\n";
		cout << "5 - Выход\n";
		cout << endl << setw(3) << setfill(v) << v << endl;
		cout << setw(1) << setfill(q) << q; cin >> c;
		system("cls");
		switch (c)
		{
		case 1: del(); break;
		case 2: new_tvr(); break;
		case 3: show_position(); break;
		case 4: search(); break;
		case 5: break;
		}
	} while (c != 5);
	return 0;
}

int new_tvr()
{
	system("cls");
	int x, show_number, temp_dni;
	int hours, minutes, seconds;
	int i, b, c; char z = '_', q = ' ', v = '=';
	if (number <= 5)
	{
		show_number = number + 1;
		cout << "\n Позиция №" << show_number << endl;
		cout << "Номер поезда: "; cin >> a[number].number; cout << endl;
		cout << "Пункт назначения: ";  cin >> a[number].punkt; cout << endl;
		cout << "Время прибытия: " << endl;
		cout << setw(2) << setfill(q) << q << "Hours: "; cin >> hours;
		cout << setw(2) << setfill(q) << q << "Minutes: "; cin >> minutes;
		a[number].ohours = hours;
		a[number].ominutes = minutes;
		cout << endl;
		cout << "Время отправления: " << endl;
		cout << setw(2) << setfill(q) << q << "Hours: "; cin >> hours;
		cout << setw(2) << setfill(q) << q << "Minutes: "; cin >> minutes;
		a[number].phours = hours;
		a[number].pminutes = minutes;
		cout << endl << endl;
		cout << setw(36) << setfill(z) << z << endl << "Введите номер дня недели (от 1 до 7)" << endl;
		cin >> temp_dni;
		switch (temp_dni)
		{
		case (Monday):
		{ a[number].dni = "Monday"; break; }
		case (Tuesday):
		{ a[number].dni = "Tuesday"; break; }
		case (Wednesday):
		{ a[number].dni = "Wednesday"; break; }
		case (Thursday):
		{ a[number].dni = "Thursday"; break; }
		case (Friday):
		{ a[number].dni = "Friday"; break; }
		case (Saturday):
		{ a[number].dni = "Saturday"; break; }
		case (Sunday):
		{ a[number].dni = "Sunday"; break; }
		}
		number++;
	}
	else {
		cout << "\nСлишком сного поездов!";
		Sleep(1000);
		system("cls");
		return(0);
	}
	cout << setw(30) << setfill(z) << z << endl;
	cout << "\n1 - Добавить ещё поезд\n";
	cout << "2 - Главное меню\n";
	cout << endl << setw(3) << setfill(v) << v << endl;
	cout << setw(1) << setfill(q) << q; cin >> x;
	switch (x)
	{
	case 1: new_tvr();
	case 2: {system("cls");
		return 0; }
	}
}

int del()
{
	char z = '_', q = ' ', v = '=';
	system("cls");
	int x, b;
	cout << "\n1 - Удалить один поезд";
	cout << "\n2 - Удалить все поезда";
	cout << "\n3 - Главное меню";
	cout << endl << setw(3) << setfill(v) << v << endl;
	cout << setw(1) << setfill(q) << q; cin >> x;
	switch (x) {
	case 1:
	{	int num;
	system("cls");
	cout << "Введите номер позиции\n";
	cout << endl << setw(3) << setfill(v) << v << endl;
	cout << setw(1) << setfill(q) << q; cin >> num;
	for (int i = num - 1; i < number; i++)
	{
		a[i] = a[i + 1];
	}
	number--;
	system("cls");
	cout << "\n__Удаление прошло успешно__\n";
	cout << "\n1 - Продолжить удаление\n";
	cout << "2 - Главное меню\n";
	cout << endl << setw(3) << setfill(v) << v << endl;
	cout << setw(1) << setfill(q) << q; cin >> b;
	switch (b)
	{
	case 1: del();
	case 2:
		system("cls"); return 0;
	}
	}
	case 2:
	{
		int value(0);
		for (int i(0); i <= number; i++)
		{
			if (a[i].number)
				value++;
			a[i] = delt;
			//считает кол-во удаленных записей
		}
		number = 0;
		system("cls");
		cout << "\n__Удаление прошло успешно__\n";
		cout << "Кол-во удаленных записей: " << value << endl;
		Sleep(2000);
		system("cls");
		break;
	}
	case 3:
		system("cls"); return 0;
	}
}

int show_position()
{
	int b; char  q = ' ', v = '=', z = '_';
	system("cls");
	int position(1);
	cout << endl << setw(5) << setfill(q) << q;
	cout << "Время прибытия" << setw(5) << setfill(q) << q;
	cout << "Время отправления" << setw(5) << setfill(q) << q;
	cout << "Пункт\n";
	for (int i(0); i < number; i++)
	{
		cout << position;
		cout << setw(9) << setfill(q) << q << a[i].ohours << ":" << a[i].ominutes;
		cout << setw(15) << setfill(q) << q << a[i].phours << ":" << a[i].pminutes << endl;
		cout << setw(15) << setfill(q) << a[i].punkt << endl;
		position++;
	}
	cout << endl;
	cout << setw(40) << setfill(z) << z << "\n1 - Продолжить обзор\n";
	cout << "2 - Главное меню\n";
	cout << endl << setw(3) << setfill(v) << v << endl;
	cout << setw(1) << setfill(q) << q; cin >> b;
	switch (b) {
	case 1: show_position();
	case 2: system("cls");
	}
	return 0;
}

void search()
{
	char z = '_', q = ' ', v = '='; int m, n;
	system("cls");
	cout << "\n1 - Поиск по пункту назначения\n";
	cout << "2 - Поиск по дню недели\n";
	cout << endl << setw(3) << setfill(v) << v << endl;
	cout << setw(1) << setfill(q) << q; int x;
	cin >> x;
	system("cls");
	switch (x)
	{
	case 1: {
		system("cls");
		char temp[10];
		bool fl = false;
		cout << "Введите пункт назначения: ";
		cin >> temp;
		for (int i(0); i <= number; i++)
		{
			if (strcmp(a[i].punkt, temp) == 0)
			{
				getline(cin, a[i].dni);
				cout << "\n      Позиция №" << i + 1;
				cout << "\nНомер поезда: " << a[i].number;
				cout << "\nДни следования: " << a[i].dni;
				cout << "\nВремя прибытия: " << a[i].ohours << ":" << a[i].ominutes;
				cout << "\nВремя отправления: " << a[i].phours << ":" << a[i].pminutes;
				cout << endl;
				fl = 1;
			}
		}
		if (!fl)
		{
			cout << "\nНет таких поездов";
		}
		break;
	}
	case 2:
	{
		system("cls");
		char cost[10];
		bool flag = false;
		cout << "Введите день недели: ";
		cin >> cost; cout << endl;
		for (int i(0); i <= number; i++)
		{
			if (a[i].dni == cost)
			{
				cout << "\n      Позиция №" << i + 1;
				cout << "\nНомер поезда: " << a[i].number;
				cout << "\nПункт назначения: " << a[i].punkt;
				cout << "\nВремя прибытия: " << a[i].ohours << ":" << a[i].ominutes;
				cout << "\nВремя отправления: " << a[i].phours << ":" << a[i].pminutes;
				cout << endl;
				flag = 1;
			}
		}

		if (!flag)
		{
			cout << "\nНет таких поездов";
		}
		break;
	}
	}
	cout << setw(30) << setfill(z) << z << endl;
	int b;
	cout << "\n\n1 - Продолжить поиск\n";
	cout << "2 - Главное меню\n";
	cout << endl << setw(3) << setfill(v) << v << endl;
	cout << setw(1) << setfill(q) << q; cin >> b;
	if (b == 1) search();
	system("cls");
}