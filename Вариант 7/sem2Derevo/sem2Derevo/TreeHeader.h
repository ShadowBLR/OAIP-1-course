
#pragma once
#include <iostream>
using namespace std;


struct Element {
	int x; //ключ
	Element* left, * right; //потомки 
	char* s;//строка
};

struct Tree {
	Element* root; //корень
	Tree() //конструктор
	{
		root = NULL;
	}
	void Push(int A, char* b);
	void Load(char* s);
};

void sum_c(Element* E); //расчитывает сумму и кол-во элементов
Element* Search(Element* root, int A, Element** p, bool output = false); //поиск вершины по ключу
int depth(Element* E); //губина дерева, начиная с узла E (самая длинная ветвь)
void show_level(Element* E, int d, int i); //d - текущая глубина, i - требуемая глубина
void ScanDown(Element* E, void f(Element*));
void ScanMixed(Element* E, void f(Element*)); //смешанный обход
void ScanPrev(Element* E, void f(Element*));
void Print(Element* E);
int HeightTree(Element* E);
void Delete(Element* E, Element** p, Element** r); //указатель на родит. и указат. на корень
bool IsBalanced(Element* E); //функция проверки сбалансиров. дерева

