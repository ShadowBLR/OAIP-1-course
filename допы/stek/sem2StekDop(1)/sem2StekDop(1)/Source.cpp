#include <iostream>
#include "header.h"
#include <fstream>
using namespace std;
void push(char x, Stack* myStk, int count)   //Добавление элемента х в стек	
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
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}
void showNewStack(Stack*myStk,int count)
{

	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	for (int i = 0; i < count/2;i++)
		e = e->next;
	while(e!=NULL)
	{
		cout << e->data;
		e = e->next;
	}
	e = myStk->head;
	for (int i = 0; i < count / 2;i++)
	{
		cout << e->data;
		e = e->next;
	}
}
void clear(Stack* myStk)
{

	while (myStk->head != NULL)
	{
		Stack* e = myStk->head;
		myStk->head = myStk->head->next;
		delete e;
	}
	cout << "Стек очищен\n";
}
void removeMoreThan100(Stack* myStk)
{
	Stack* e = myStk->head;
	Stack* pointer = myStk->head;
	if (myStk->head == NULL)
	{
		cout << "Стек пуст\n";
		return;
	}
	if (myStk->head->data > 100)
	{
		myStk->head = myStk->head->next;
		cout << "Удален элемент " << e->data << endl;
		delete e;
		return;
	}
	else
	{
		do {
			Stack* temp;
			if (pointer->data > 100)
			{
				temp = pointer;
				e->next = pointer->next;
				pointer = pointer->next;
				cout << "Удален элемент " << temp->data << endl;
				delete temp;
				return;
			}
			e = pointer;
			pointer = pointer->next;
		} while (pointer != NULL);

	}
	cout << "Такого элемента нет\n";
}
void writeToFile(Stack* myStk)
{
	Stack* e = myStk->head;
	Stack buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (e != NULL)
	{
		buf = *e;
		frm.write((char*)& buf, sizeof(Stack));
		e = e->next;
	}
	frm.close();
	cout << "Список записан в файл mList.dat\n";

}
/*void readFromFile(Stack* myStk)
{
	Stack buf, * e = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read((char*)& buf, sizeof(Stack));
	while (!frm.eof())
	{
		push(buf.data, myStk,count);
		cout << "-->" << buf.data;
		frm.read((char*)& buf, sizeof(Stack));
	}
	frm.close();
	cout << "\nСписок считан из файла mList.dat\n";
}*/
