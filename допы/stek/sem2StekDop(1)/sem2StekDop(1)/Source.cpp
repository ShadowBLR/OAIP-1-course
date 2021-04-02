#include <iostream>
#include "header.h"
#include <fstream>
using namespace std;
void push(char x, Stack* myStk, int count)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� v 
	e->next = myStk->head;   //������� ������� �� ��������� ������� 
	myStk->head = e;         //����� ������� �� ������� ������
}
int pop(Stack* myStk)   //���������� (��������) �������� �� �����
{
	if (myStk->head == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;               //���� ���� ���� - ������� -1 
	}
	else
	{
		Stack* e = myStk->head;   //� - ���������� ��� �������� ������ ��������
		int a = myStk->head->data;   //������ ����� �� ���� data � ���������� a 
		myStk->head = myStk->head->next; //������� �������
		delete e;                        //�������� ��������� ����������
		return a;                        //������� �������� ���������� ��������
	}
}
void show(Stack* myStk)    //����� �����
{
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		a = e->data;          //������ �������� � ���������� a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}
void showNewStack(Stack*myStk,int count)
{

	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	if (e == NULL)
		cout << "���� ����!" << endl;
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
	cout << "���� ������\n";
}
void removeMoreThan100(Stack* myStk)
{
	Stack* e = myStk->head;
	Stack* pointer = myStk->head;
	if (myStk->head == NULL)
	{
		cout << "���� ����\n";
		return;
	}
	if (myStk->head->data > 100)
	{
		myStk->head = myStk->head->next;
		cout << "������ ������� " << e->data << endl;
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
				cout << "������ ������� " << temp->data << endl;
				delete temp;
				return;
			}
			e = pointer;
			pointer = pointer->next;
		} while (pointer != NULL);

	}
	cout << "������ �������� ���\n";
}
void writeToFile(Stack* myStk)
{
	Stack* e = myStk->head;
	Stack buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	while (e != NULL)
	{
		buf = *e;
		frm.write((char*)& buf, sizeof(Stack));
		e = e->next;
	}
	frm.close();
	cout << "������ ������� � ���� mList.dat\n";

}
/*void readFromFile(Stack* myStk)
{
	Stack buf, * e = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
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
	cout << "\n������ ������ �� ����� mList.dat\n";
}*/
