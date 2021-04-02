
#include<iostream>		8.2
#include<Windows.h>
using namespace std;
#define size 4

enum Efly {
	Mnsk = 1, Spb, Msk
}fly;
union fly2 {
	int numb;
	int punkt = fly;
	float time;
	int date;
	int cost;
	int places;
}flyy;
struct book {
	int numb;
	int punkt = fly;
	float time;
	int date;
	int cost;
	int places;
};
book arr[size];
int i = 0;
int oper;

void input();
void remove();
void output();
void search();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Что вы хотите сделать?\n";
	cout << "1 - Ввод данных в структуру\n";
	cout << "2 - Удаление данных из структуры\n";
	cout << "3 - Вывод данных на экран\n";
	cout << "4 - Поиск по дате\n";
	cout << "5 - Для завершения работы\n";
	cin >> oper;
	do {
		switch (oper)
		{
		case 1:  input(); break;
		case 2:  remove(); break;
		case 3:  output(); break;
		case 4:  search(); break;
		default:break;
		}
	} while (oper != 5);
	system("pause");
}

void input()
{
	if (i < size)
	{
		cout << "Номер рейса: ";
		cin >> flyy.numb;
		arr[i].numb = flyy.numb;
		cout << "Введите пункт назначения(1 - Минск, 2 - Санкт-Петербург, 3 - Москва): ";
		cin >> flyy.punkt;
		arr[i].punkt = flyy.punkt;
		cout << "Введите время отправлени(ЧЧ.ММ): ";
		cin >> flyy.time;
		arr[i].time = flyy.time;
		cout << "Введите дату вылета(ДДММГГГГ): ";
		cin >> flyy.date;
		arr[i].date = flyy.date;
		cout << "Введите стоимость билета: ";
		cin >> flyy.cost;
		arr[i].cost = flyy.cost;
		cout << "Введите кол-во свободных мест: ";
		cin >> flyy.places;
		arr[i].places = flyy.places;
		i++;
		cout << "-------------------------------------------" << endl;
	}
	else
		cout << "Введено максимальное кол-во строк!\n";
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}
void output()
{
	if (i > 0)
	{
		int n, day, mounth;
		cout << "Введите номер элемента, который хотите вывести: "; cin >> n;
		n--;
		day = arr[n].date / 1000000;
		mounth = (arr[n].date - (day * 1000000)) / 10000;
		cout << "Номер рейса: " << arr[n].numb;
		cout << endl;
		cout << "Пунк назначения: ";
		switch (arr[n].punkt) {
		case Mnsk: cout << "Минск" << endl;
			break;
		case Spb: cout << "Санкт-Петербург" << endl;
			break;
		case Msk: cout << "Москва" << endl;
			break;
		}
		cout << "Время отправления: " << arr[n].time << " Часов" << endl;
		cout << "Дата отправления: " << day << "." << mounth << "." << arr[n].date % 10000 << endl;
		cout << "Стоимость билета: " << arr[n].cost << endl;
		cout << "Кол-во свободных мест: " << arr[n].places << endl;
		cout << "-------------------------------------------" << endl;
	}
	else
		cout << "Недостаточно информации для вывода!" << endl;
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}
void remove()
{
	if (i > 0)
	{
		int d;
		cout << "Номер записи, которую нужно удалить: "; cin >> d;
		for (int de1 = (d - 1); de1 < i; de1++)
			arr[de1] = arr[de1 + 1];
		i--;
		cout << "Запись удалена" << endl;
	}
	else
		cout << "Недостаточно информации!" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}
void search()
{
	int test, date, day, mounth;
	if (i > 0)
	{
		cout << "Введите дату вылета(ДДММГГГГ): "; cin >> test;
		for (int k = 0; k < i; k++)
		{
			date = arr[k].date;
			if (date == test)
			{
				day = arr[k].date / 1000000;
				mounth = (arr[k].date - (day * 1000000)) / 10000;
				cout << "Номер рейса: " << arr[k].numb;
				cout << endl;
				cout << "Пунк назначения: ";
				switch (arr[k].punkt) {
				case Mnsk: cout << "Минск" << endl;
					break;
				case Spb: cout << "Санкт-Петербург" << endl;
					break;
				case Msk: cout << "Москва" << endl;
					break;
				}
				cout << "Время отправления: " << arr[k].time << " Часов" << endl;
				cout << "Дата отправления: " << day << "." << mounth << "." << arr[k].date % 10000 << endl;
				cout << "Стоимость билета: " << arr[k].cost << endl;
				cout << "Кол-во свободных мест: " << arr[k].places << endl;
				cout << "-------------------------------------------" << endl;
			}
		}
	}
	else
		cout << "Недостаточно информации!" << endl;
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}