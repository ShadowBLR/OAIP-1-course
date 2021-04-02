#include <iostream>
using namespace std;

enum Epoint
{
	Moskow, New_York, Los_Ageleas, Minsk, Yale, Oxford, Canberra, Tokio, Antananrivu
};

struct date
{
	char day : 6;
	char month : 5;
}date;
struct Race
{
	int number;
	Epoint end_point;
	string time_out;
	struct date date_out;
	int ticket_cost;
	int place_count;
};

void show(Race rice)
{

	cout << "Номер: " << rice.number << endl;
	cout << "Конечная точка (Moskow - 1, New_York- 2, Los_Ageleas - 3, Minsk - 4, Yale - 5, Oxford - 6, Canberra - 7, Tokio - 8, Antananrivu): " << rice.end_point << endl;
	cout << "Время вылета: " << rice.time_out << endl;
	cout << "День вылета: " << (int)rice.date_out.day << endl;
	cout << "Месяц вылета: " << (int)rice.date_out.month << endl;
	cout << "Цена билета: " << rice.ticket_cost << endl;
	cout << "Количество посадочных мест: " << rice.place_count << endl;
}

Race add()
{

	Race rice;
	int a;
	cout << "Введите номер ";
	cin >> a;
	rice.number = a;
	cout << "Введите номер конечной точки (Moskow - 1, New_York- 2, Los_Ageleas - 3, Minsk - 4, Yale - 5, Oxford - 6, Canberra - 7, Tokio - 8, Antananrivu) ";
	cin >> a;
	rice.end_point = (Epoint)a;
	string qq;
	cout << "Введите время ";
	cin >> qq;
	rice.time_out = qq;
	cout << "Введите День вылета ";
	cin >> a;
	rice.date_out.day = a;
	cout << "Введите месяц вылета ";
	cin >> a;
	rice.date_out.month = a;
	cout << "Введите стоимость билета ";
	cin >> a;
	rice.ticket_cost = a;
	cout << "Введите кол-во мест ";
	cin >> a;
	rice.place_count = a;
	return rice;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int q;
	do {
		cout << "Выберите опцию:\n1 - ввод элементов структуры с клавиатуры\n2 - вывод элементов структуры в консольное окно\n3 - удаление заданной структурированной переменной\n4 - поиск информации\n";
		cin >> q;
		switch (q)
		{
		case 1:
		{
			int count;
			//enter
			cout << "Сколько элементов введете ";
			cin >> count;
			Race* races = new Race[count];
			FILE* f;
			fopen_s(&f, "base.bin", "wb");
			fwrite(&count, sizeof(count), 1, f);

			for (int i = 0; i < count; i++)
			{
				races[i] = add();
				fwrite(&races[i], sizeof(Race), 1, f);
			}
			fclose(f);
			break;
		}
		case 2:
		{
			FILE* f3;

			fopen_s(&f3, "base.bin", "rb");
			int count;
			fread(&count, sizeof(count), 1, f3);
			Race* races = new Race[count];

			for (int i = 0; i < count; i++)
			{
				fread(&races[i], sizeof(Race), 1, f3);
				show(races[i]);
			}
			fclose(f3);
			break;
		}
		case 3:
		{
			FILE* f, * fr;
			fopen_s(&f, "base.bin", "rb");
			int count;
			fread(&count, sizeof(count), 1, f);
			Race* races = new Race[count];

			for (int i = 0; i < count; i++)
			{
				fread(&races[i], sizeof(Race), 1, f);
				cout << i << ":\n";
				show(races[i]);
			}
			fclose(f);
			cout << "Введите номер элемента для удаления ";
			int del;
			cin >> del;
			del--;
			fopen_s(&fr, "base.bin", "wb");
			count--;
			fwrite(&count, sizeof(count), 1, fr);
			for (int i = 0; i < count + 1; i++)
			{
				if (i != del)
					fwrite(&races[i], sizeof(Race), 1, fr);
			}
			fclose(fr);
			break;
		}
		case 4:
		{
			string time;
			cout << "Введите время ";
			cin >> time;
			FILE* f;
			int count;
			fopen_s(&f, "base.bin", "rb");
			fread(&count, sizeof(count), 1, f);
			Race* races = new Race[count];
			for (int i = 0; i < count; i++)
			{
				bool b = true;
				fread(&races[i], sizeof(Race), 1, f);
				int j = 0;
				while (time[j] != '\0')
				{
					if (time[j] != races[i].time_out[j])
					{
						b = false;
						break;
					}
					j++;
				}
				if (b)
					show(races[i]);
				cout << "-------------\n";
			}
			break;
		}
		default:
		{
			break;
		}
		}
	}while (q != 0);
}
