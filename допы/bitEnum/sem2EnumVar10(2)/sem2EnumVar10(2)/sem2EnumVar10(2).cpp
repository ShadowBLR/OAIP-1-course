#include<iostream>	
#include<Windows.h>
using namespace std;
#define size 4
union fly2 {
	fly2()
	{};
	~fly2()
	{};
	string name;
	string surName;
	string lastName;
	bool pol;
	int day;
	int month;
	int year;
	string adress;
};
fly2 flyy;
struct student {
	string name;
	string surName;
	string lastName;
	bool pol;
	int day;
	int month;
	int year;
	string adress;
};
student arr[size];
int i = 0;
int oper;

void input();
void remove();
void output();
void search();

int main()
{
	setlocale(LC_ALL, "ru");
	do {
		cout << "Что вы хотите сделать?\n";
		cout << "1 - Ввод данных в структуру\n";
		cout << "2 - Удаление данных из структуры\n";
		cout << "3 - Вывод данных на экран\n";
		cout << "4 - Поиск по году\n";
		cout << "5 - Для завершения работы\n";
		cin >> oper;
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
		cout << "Имя ";
		cin >> arr[i].name;
		cout << "Фамилия ";
		cin >> flyy.surName;
		arr[i].surName = flyy.surName;
		cout << "Отчество ";
		cin >> flyy.lastName;
		arr[i].lastName = flyy.lastName;
		cout << "день рождения ";
		cin >> flyy.day;
		arr[i].day = flyy.day;
		cout << "месяц ";
		cin >> flyy.month;
		arr[i].month = flyy.month;
		cout << "Год ";
		cin >> flyy.year;
		arr[i].year = flyy.year;
		cout << "Пол 1 - мужской \n0 - женский\n";
		cin >> flyy.pol;
		arr[i].pol = flyy.pol;
		cout << "Адрес\n";
		cin >> flyy.adress;
		arr[i].adress = flyy.adress;
		i++;
		cout << "-------------------------------------------" << endl;
	}
	else
		cout << "Введено максимальное кол-во строк!\n";
}
void output()
{
	for (int i = 0; i < ::i; i++)
	{
		cout << "\nИмя " << arr[i].name;
		cout << "\nФамилия " << arr[i].surName;
		cout << "\nОтчество " << arr[i].lastName;
		if(arr[i].pol)cout << "\nмужской";
		else cout << "\nженский";
		cout << "\nдень " << arr[i].day;
		cout << "\nмесяц " << arr[i].month;
		cout << "\nгод " << arr[i].year;
		cout << "\nадрес " << arr[i].adress;
		cout << "\n-------------------------------------------" << endl;
	}
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
}
void search()
{
	int temp;
	cout << "Введиет год\n";
	cin >> temp;
	for (int i = 0; i < ::i; i++)
		if (temp == arr[i].year)
		{
			cout << "\nИмя " << arr[i].name;
			cout << "\nФамилия " << arr[i].surName;
			cout << "\nОтчество " << arr[i].lastName;
			if (arr[i].pol)cout << "\nмужской";
			else cout << "\nженский";
			cout << "\nдень " << arr[i].day;
			cout << "\nмесяц " << arr[i].month;
			cout << "\nгод " << arr[i].year;
			cout << "\nадрес " << arr[i].adress;
			cout << "\n-------------------------------------------" << endl;
		}
		else
			cout << "Недостаточно информации!" << endl;
}
