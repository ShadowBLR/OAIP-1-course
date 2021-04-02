#include <iostream>
#include <fstream>
struct Stack
{
	int data;             //информационный элемент
	Stack* head;		 //вершина стека 
	Stack* next;		 //указатель на следующий элемент
};

using namespace std;
void push(int x, Stack* myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}
int pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
		int a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}
void show(Stack* myStk)    //Вывод стека
{
	int tCount=0,number= 0,temp=200;

	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		
		a = e->data;          //запись значения в переменную a 
		cout << a <<endl;
		tCount++;
		if (e->data < temp)
		{
			temp = e->data;
			number = tCount;
		}
		
		e = e->next;
		
	}
	cout << endl;
	cout << "Самая короткая строка номер " << number << " имееет " << temp << " символов\n";
}

void readFromFile(Stack* myStk,int &count)
{
	char buff[200]; int temp = 200;
	static char msa[200];
	ifstream fin("t.txt");
	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	else 
		while (!fin.eof())
		{
			fin.getline(buff, 200);
			push(strlen(buff), myStk);
			count++;
		}
	fin.close();
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	int count = 0;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	
	readFromFile(myStk,count);
	show(myStk);
	return 0;
}



