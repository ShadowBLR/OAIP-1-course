#include <iostream>
#include "Header.h"
using namespace std;

/*void splitStackByTwo(Stack* myStk, Stack* stk1, Stack* stk2)
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст\n";
		return;
	}
	Stack* temp = myStk->head;
	while (temp != NULL) {
		Stack* e = new Stack();
		if (temp->data > 50)
		{
			e->data = temp->data;
			e->next = stk1->head;
			stk1->head = e;
		}
		else {
			e->data = temp->data;
			e->next = stk2->head;
			stk2->head = e;
		}
		temp = temp->next;
		delete e;

	}
}*/
void tempFunct(Stack* myStk, Stack* stk1, Stack* stk2)
{
	if (myStk->head == NULL)
	{
		cout << "Начальный стек пуст\n";
		return;
	}
	Stack* tempStk = myStk->head;
	while (tempStk != NULL) {
		if (tempStk->data > 50)
			push(tempStk->data, stk1);
		else
			push(tempStk->data, stk2);
		tempStk = tempStk->next;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;  //инициализация первого элемента	
	Stack* stk1=new Stack, * stk2=new Stack;
	stk1->head =stk2->head= NULL;
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
		cout << "9 - Разделить стек на 2\n";
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
		case 3:  int n;
			cout << "1 - начальный стек\n";
			cout << "2 - первый стек\n";
			cout << "3 - второй стек\n";
			cin >> n;
			switch (n)
			{
			case 1:show(myStk); break;
			case 2:show(stk1); break;
			case 3:	show(stk2); break;
			}
			break;
		case 4: clear(myStk);
			break;
		case 5:removeMoreThan100(myStk);
			break;
		case 6:writeToFile(myStk);
			break;
		case 7:readFromFile(myStk);
			break;
		case 9:tempFunct(myStk,stk1,stk2); 
			break;
		case 0: return 0;
			break;
		}
	}
	return 0;
}

