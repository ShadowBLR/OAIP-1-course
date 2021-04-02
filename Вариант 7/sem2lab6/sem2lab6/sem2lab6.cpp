﻿#include <iostream>
#define size 10
using namespace std;
struct sklad
{
	string name;
	int price;
	int counter;
	enum nadbavka{
		nad1=5, nad2=7,nad3=11,
		nad4=20,nad5=25,nad6=30
	} dop;
}obj[size];
int counter = 0;
void addObj(sklad* obj)
{
	cout << "Введите наименование\n";
	cin >> obj[counter].name;
	cout << "Введите цену\n";
	cin >> obj[counter].price;
	if(obj[counter].price<100)
	obj[counter].dop = obj[counter].nad1;
	else if (obj[counter].price < 200)
		obj[counter].dop = obj[counter].nad2;
	else if (obj[counter].price < 300)
		obj[counter].dop = obj[counter].nad3;
	else if (obj[counter].price < 400)
		obj[counter].dop = obj[counter].nad4;
	else if (obj[counter].price < 500)
		obj[counter].dop = obj[counter].nad5;
	else if (obj[counter].price < 600)
		obj[counter].dop = obj[counter].nad6;
	counter++;
}
void showAllObj(sklad* obj)
{
	for (int i = 0; i < counter; i++)
	{
		cout << "Наименование:" << obj[i].name<<endl;
		cout << "Цена с надбавкой:" << obj[i].price+obj[i].dop<<endl;
	}
}
void searchToPrice(sklad*obj)
{
	int price;
	cout << "Введите цену\n";
	cin >> price;
	for(int i=0;i<counter;i++)
		if (price == obj[i].price + obj[i].dop)
		{
			cout << "Наименование:" << obj[i].name << endl;
			cout << "Цена с надбавкой:" << obj[i].price + obj[i].dop << endl;
		}
}
void deleteObj(sklad* obj,int number)
{
	for (int i = number-1; i <counter; i++)
	{
		obj[i] = obj[i+1];
	}
	counter--;
}
int main(void)
{
	
	setlocale(LC_CTYPE, "Russian");
	int choice,number;
	do {
		cout << "Меню\n";
		cout << "1-добавить\n";
		cout << "2-вывести все\n";
		cout << "3-поиск по цене\n";
		cout << "4-удалить\n";
		cout << "0-выход\n";
		cin >> choice;
		system("cls");
		switch (choice)
			{
		case 1: {addObj(obj); break; }
		case 2: {showAllObj(obj); break; }
		case 3: {searchToPrice(obj); break; }
		case 4: {cout << "Введите номер элемента\n"; cin >> number;deleteObj(obj,number); break; }
		case 0: {break; }
			}
		
		} while (choice != 0);
}

