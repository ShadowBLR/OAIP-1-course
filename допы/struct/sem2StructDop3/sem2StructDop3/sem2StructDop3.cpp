# include <iostream> 
#include <string>
# define str_len 30                               
# define size 30  
using namespace std;

struct SANAT
{
	string name;
	string adress;
	string prof;
	int count;
};
struct SANAT list_of_sanat[size];
struct SANAT bad;
int current_size = 0;

void enter_new()
{
	setlocale(LC_CTYPE, "Russian");
	cout << endl;
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Название санатория: ";
		cin >> list_of_sanat[current_size].name;
		cout << "Адрес санатория: ";
		cin >> list_of_sanat[current_size].adress;
		cout << "Лечебный профиль: ";
		cin >> list_of_sanat[current_size].prof;
		cout << "Число путевок: ";
		cin >> list_of_sanat[current_size].count;
		current_size++;
		cout << endl;
	}
	else
		cout << "Введено максимальное кол-во строк\n";
	
}

void del()
{
	setlocale(LC_CTYPE, "Russian");
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_sanat[de1] = list_of_sanat[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
		{
			list_of_sanat[i] = bad;
		}
	cout << endl;
}

void change()
{
	setlocale(LC_CTYPE, "Russian");
	int n, per;
	cout << "\nВведите номер строки: "; 	cin >> n;
	do
	{
		cout << endl;
		cout << "Введите: " << endl;
		cout << "1-для изменения названия санатория" << endl;
		cout << "2-для изменения адреса санатория" << endl;
		cout << "3-для изменения лечебного профиля" << endl;
		cout << "4-для изменения числа путевок" << endl;
		cout << "5-конец\n" << endl;
		cin >> per;
		switch (per)
		{
		case 1: cout << "Новое название санатория: ";
			cin >> list_of_sanat[n - 1].name;   break;
		case 2: cout << "Новый адрес санатория: ";
			cin >> list_of_sanat[n - 1].adress;   break;
		case 3: cout << "Новый лечебный профиль: ";
			cin >> list_of_sanat[n - 1].prof;   break;
		case 4: cout << "Новое число путевок: ";
			cin >> list_of_sanat[n - 1].name;   break;
		}
	} while (per != 5);
	cout << endl;
}

void out()
{
	setlocale(LC_CTYPE, "Russian");
	int sw, n;
	cout << "1-вывод информации про 1 санаторий" << endl;
	cout << "2-вывод информации про все санатории" << endl;
	cout << "3-поиск информации о санатории" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << endl;
		cout << "Номер выводимой строки: ";   cin >> n;  cout << endl;
		cout << "Название санатория: ";
		cout << list_of_sanat[n - 1].name << endl;
		cout << "Адрес санатория: ";
		cout << list_of_sanat[n - 1].adress << endl;
		cout << "Лечебный профиль: ";
		cout << list_of_sanat[n - 1].prof << endl;
		cout << "Число путевок: ";
		cout << list_of_sanat[n - 1].count << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
			for (int j = 0; j < current_size; j++)
			{
				if ((i != j) && (list_of_sanat[i].prof == list_of_sanat[j].prof))
				{
					list_of_sanat[current_size] = list_of_sanat[j];
					list_of_sanat[j] = list_of_sanat[i + 1];
					list_of_sanat[i + 1] = list_of_sanat[current_size];
					list_of_sanat[current_size] = bad;
				}
			}
		for (int k = 0; k < current_size; k++)
		{
			if ((list_of_sanat[k].name[0] > list_of_sanat[k + 1].name[0]) && (list_of_sanat[k].prof == list_of_sanat[k + 1].prof))
			{
				list_of_sanat[current_size] = list_of_sanat[k];
				list_of_sanat[k] = list_of_sanat[k + 1];
				list_of_sanat[k + 1] = list_of_sanat[current_size];
				list_of_sanat[current_size] = bad;
			}
		}
		cout << "Название санатория: | Адрес санатория: | Лечебный профиль: | Число путевок: " << endl;
		for (int j = 0; j < current_size; j++)
		{
			cout << list_of_sanat[j].name;
			cout << "                  ";
			cout << list_of_sanat[j].adress;
			cout << "              ";
			cout << list_of_sanat[j].prof;
			cout << "               ";
			cout << list_of_sanat[j].count << endl;
		}
		cout << endl;
	}
	if (sw == 3)
	{
		string search; int nsearch = 0;
		cout << endl;
		cout << "Введите какую-либо информацию: " << endl; cin >> search;
		for (int i = 0; i < current_size; i++)
		{
			if ((search == list_of_sanat[i].name) || (search == list_of_sanat[i].adress) || (search == list_of_sanat[i].prof))
			{
				nsearch = i;
			}
		}
		cout << "Название санатория: ";
		cout << list_of_sanat[nsearch].name << endl;
		cout << "Адрес санатория: ";
		cout << list_of_sanat[nsearch].adress << endl;
		cout << "Лечебный профиль: ";
		cout << list_of_sanat[nsearch].prof << endl;
		cout << "Число путевок: ";
		cout << list_of_sanat[nsearch].count << endl;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int choice;
	do
	{
		cout << "Введите:" << endl;
		cout << "1-для удаления записи" << endl;
		cout << "2-для ввода новой записи" << endl;
		cout << "3-для изменения записи" << endl;
		cout << "4-для вывода записи(ей)" << endl;
		cout << "5-для выхода" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  change();  break;
		case 4:  out();	break;
		}
	} while (choice != 5);
}
