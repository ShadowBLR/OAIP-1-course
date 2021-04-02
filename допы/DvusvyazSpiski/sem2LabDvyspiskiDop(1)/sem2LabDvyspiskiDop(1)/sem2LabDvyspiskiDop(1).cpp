#include "List.h"
#include <iostream>
#include "List.h"

using namespace std;
 struct Person
{
	unsigned short number;
	char pNaznach[20];
	char timeVileta[6];
	char dataVileta[9];
	unsigned int price;
	unsigned int countPlace;
	Person* next;
};

void print(void* b)       //Функция используется при выводе 
{
	if (b != NULL)
	{
		Person* a = (Person*)b;
		cout << "Номер рейса "<< a->number << endl;
		cout << "Пункт назначения " << a->pNaznach<<endl;
		cout << "Время вылета " << a->timeVileta << endl;
		cout << "Дата вылета  " << a->dataVileta << endl;
		cout << "Цена  " << a->price << endl;
		cout << "Количество мест " << a->countPlace << endl;
		cout << "=======================================\n";

	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int size = 0;
	bool rc; int choice;
	Person mas[20];
	Object L1 = Create();
	do {
		cout << "2.добавить элемент \n";
		cout << "3.Вывод на экран \n";
		cout << "4.Подсчет элементов  \n";
		cout << "5.Удалить список  \n";
		cout << "6.Поиск по пункту назначения  \n";
		cout << "0.Выход \n";
		cin >> choice;
		switch (choice)
		{
		case 2:
			cout << "Введите номер рейса "; cin >> mas[size].number;
			cout << "Введите пункт назначения "; cin >> mas[size].pNaznach;
			cout << "Введите время вылета "; cin >> mas[size].timeVileta;
			cout << "Введите дату вылета "; cin >> mas[size].dataVileta;
			cout << "Введите цену  "; cin >> mas[size].price;
			cout << "Введите количество мест "; cin >> mas[size].countPlace;
			L1.Insert(&mas[size]); size++; break;
		case 3:if (L1.Head != NULL)
			L1.PrintList(print);
			   else cout << "Список пуст\n";
			break;
		case 4:
			cout << L1.CountList() << endl; break;
		case 5:L1.DeleteList(); break;
		case 6:Person *temp = (Person*)L1.Head->Data;
			char mas[20];
			cout << "Введите пункт назначения "; cin >> mas;
			int flag = 0;
			while (temp != NULL)
			{
				for (int i = 0; i < strlen(mas); i++)
				{
					if (mas[i] != temp->pNaznach[i])
						break;
					else if (mas[strlen(mas) - 1] == temp->pNaznach[strlen(mas) - 1]&&i==strlen(mas)-1)
					{
						print(temp);
						flag = 1;
					}
				}
				if (flag)
					break;
				temp = temp->next;
			}
		}
	} while(choice!=0);
	
	
	return 0;
}
