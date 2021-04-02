#include<iostream> 
#include "header.h"
int count1 = 0, count2 = 0, count3 = 0;
Number* Queue1 = NULL;
Number* Queue2 = NULL;
Number* Queue3 = NULL;
using namespace std;
void showQueue(Number** begin)
{
	Number** temp = new Number * [3];
	for (int i = 0; i < 3; i++)
		temp[i] = begin[i];
	if (temp[0] == NULL)
		cout << "Очередь 1 пуста\n";
	else
	{
		cout << "Очередь 1:\n";
		for (int i = 0; i < count1; i++)
		{
			cout << temp[0]->info << " ";
			temp[0] = temp[0]->next;
		}
		cout << endl;
	}
	if (temp[1] == NULL)
		cout << "Очередь 2 пуста\n";
	else {
		cout << "Очередь 2:\n";
		for (int i = 0; i < count2; i++)
		{
			cout << temp[1]->info << " ";
			temp[1] = temp[1]->next;
		}
		cout << endl;
	}
	if (temp[2] == NULL)
		cout << "Очередь 3 пуста\n";
	else {
		cout << "Очередь 3:\n";;
		for (int i = 0; i < count3; i++)
		{
			cout << temp[2]->info << " ";
			temp[2] = temp[2]->next;
		}
		cout << endl;
	}
}
void addElement(Number** begin, Number** tail)
{
	int n;
	cout << "Введите число\n";
	cin >> n;
	if (n < 0)
	{
		if (count1 == 0)
		{
			Queue1 = new Number[1];
			Queue1->info = n;
			Queue1->next = NULL;
			begin[0] = tail[0] = &Queue1[0];
		}
		else
		{
			Number* pTail = tail[0];
			Number* t = new Number;
			t->info = n;
			t->next = NULL;
			pTail->next = t;
			tail[0] = t;
		}
		count1++;
	}
	else if (n == 0)
	{
		if (count2 == 0)
		{
			Queue2 = new Number[1];
			Queue2->info = n;
			Queue2->next = NULL;
			begin[1] = tail[1] = &Queue2[0];

		}
		else
		{
			Number* pTail = tail[1];
			Number* t = new Number;
			t->info = n;
			t->next = NULL;
			pTail->next = t;
			tail[1] = t;
		}
		count2++;
	}
	else {
		if (count3 == 0)
		{
			Queue3 = new Number[1];
			Queue3->info = n;
			Queue3->next = NULL;
			begin[2] = tail[2] = &Queue3[0];
		}
		else
		{
			Number* pTail = tail[2];
			Number* t = new Number;
			t->info = n;
			t->next = NULL;
			pTail->next = t;
			tail[2] = t;
		}
		count3++;
	}
}
void delEndQueue(Number** begin, Number** tail, int number)
{
	if (begin[number] == NULL)
	{
		cout << "Очереддь " << number + 1 << " пуста\n";
		return;
	}
	else
	{
		if (number == 0)
			count1--;
		else if (number == 1)
			count2--;
		else if (number == 2)
			count3--;
		else { cout << "Ввели некорректные данные\n"; return; }
		Number* tBeg = begin[number];
		if (tBeg->next != 0)
		{
			while (tBeg->next != tail[number])
			{
				tBeg = tBeg->next;
			}
			tail[number] = tBeg;
			tail[number]->next = NULL;
			tBeg = tBeg->next;
		}
		else {
			begin[number] = NULL;
			tail[number] = NULL;
		}
		delete[]tBeg;
	}
}