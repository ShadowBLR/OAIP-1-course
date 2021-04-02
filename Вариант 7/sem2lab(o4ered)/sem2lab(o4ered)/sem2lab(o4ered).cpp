#include<iostream> 
#include "header.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	Number** begin = new Number * [3];
	Number** tail = new  Number * [3];
	for (int i = 0; i < 3; i++)
		begin[i] = tail[i] = NULL;
	int choice;
	do {
		cout << "Меню\n";
		cout << "1 - добавить\n";
		cout << "2 - вывод на экран\n";
		cout << "3 - удалить последний элемент\n";
		cout << "0 - выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1:addElement(begin, tail); break;
		case 2:showQueue(begin); break;
		case 3:cout << "Из какой очереди удалить элемент?";
			int number; cin >> number;
			delEndQueue(begin, tail, number-1);
			break;
		case 0: break;
		}
	} while (choice != 0);
	return 0;
}
