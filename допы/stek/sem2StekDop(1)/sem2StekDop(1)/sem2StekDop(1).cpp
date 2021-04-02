#include <iostream>
#include "header.h"
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	
	int choice;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	
	char mas[100];
	cin.getline(mas, 100);
	int count = strlen(mas);
	for (int i = 0; i < count; i++)
		push(mas[i], myStk,count);
	showNewStack(myStk, count);
	
	return 0;
}