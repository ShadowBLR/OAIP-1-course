#include <iostream>
#include "myStack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	

	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Очистить стек" << endl;
		cout << "5 - Удалить число больше 100" << endl;
		cout << "6 - Записать в файл\n";
		cout << "7 - Прочесть из файла\n";
		cout << "0 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "Извлеченный элемент: " << choice << endl;
			break;
		case 3: cout << "Весь стек: " << endl;
			show(myStk);
			break;
		case 4: clear(myStk);
			break;
		case 5:removeMoreThan100(myStk);
			break;
		case 6:writeToFile(myStk);
			break;
		case 7:readFromFile(myStk);
			break;
		case 0: return 0;
			break;
		}
	}
	return 0;
}

