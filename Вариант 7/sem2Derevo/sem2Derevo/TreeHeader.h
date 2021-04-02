
#pragma once
#include <iostream>
using namespace std;


struct Element {
	int x; //����
	Element* left, * right; //������� 
	char* s;//������
};

struct Tree {
	Element* root; //������
	Tree() //�����������
	{
		root = NULL;
	}
	void Push(int A, char* b);
	void Load(char* s);
};

void sum_c(Element* E); //����������� ����� � ���-�� ���������
Element* Search(Element* root, int A, Element** p, bool output = false); //����� ������� �� �����
int depth(Element* E); //������ ������, ������� � ���� E (����� ������� �����)
void show_level(Element* E, int d, int i); //d - ������� �������, i - ��������� �������
void ScanDown(Element* E, void f(Element*));
void ScanMixed(Element* E, void f(Element*)); //��������� �����
void ScanPrev(Element* E, void f(Element*));
void Print(Element* E);
int HeightTree(Element* E);
void Delete(Element* E, Element** p, Element** r); //��������� �� �����. � ������. �� ������
bool IsBalanced(Element* E); //������� �������� �����������. ������

