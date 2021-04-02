#include "TreeHeader.h"

void Tree::Push(int A, char* b)
{
	Element* E = root, * E1 = NULL; //указат. на нов. эл. - корень
	bool flag = true; //определяем, в качестве левого или в качестве правого 
	while (E != NULL) //пока не найдем позицию для вставки нового элемента
	{
		E1 = E; //E1 - указатель на тот элемент, который будет родителем для нового элемента
		if (A > E->x) //если вставляемый эл. больше текущего
		{
			E = E->right; //новый эл. становится правым потомком
			flag = true;
		}
		else
		{
			E = E->left; //новый эл. становится левым потомком
			flag = false;
		}
	}
	E = new Element(); //выделяем память
	if (root == NULL) //корень равен 0
		root = E; //новый элем. становится корнем
	if (E1 != NULL) //родитель нового элемента не равен 0
	{
		if (flag == true)
			E1->right = E; //нов. элем. становится правым потомком
		else E1->left = E;  //нов. элем. становится левым потомком
	}
	E->x = A; //запис. значение

	E->s = new char[strlen(b) + 1]; //выделение памяти
	strcpy_s(E->s, strlen(b) + 1, b); //копируем Е, размер, в b

	E->left = NULL; //левый узел равен 0
	E->right = NULL; //левые и правые узлы равны 0
}

void Tree::Load(char* s) //функция чтения из файла
{
	FILE* F;
	fopen_s(&F, s, "r");
	char buf[255];
	for (; !feof(F);) //пока не закончился файл
	{
		buf[0] = '\0'; //очистка буфера
		fgets(buf, 255, F);
		if (strlen(buf) > 0) //если прочитанная строка не пустая
		{
			int i = 0;
			for (; i < strlen(buf); i++) //менбше длины строки. ищем символ разделителя ключа и строки (\t)
			{
				if (buf[i] == '\t')
				{
					buf[i] = '\0';
					break;
				}
			}
			int key = atoi(buf); //преобразуем строку в число (ключ)
			buf[i] = '\t';
			int j = i + 1;
			for (; j < strlen(buf) - 1; j++) //i+1 - первый символ строки. j < strlen(buf)-1 - чтобы не копировать переход на новую строку
			{
				buf[j - (i + 1)] = buf[j]; //новая позиция элем.
			}
			buf[j - (i + 1)] = '\0'; //конец строки
			Push(key, buf); //добавление прочитанного элемента в дерево
		}
	}
	fclose(F);
}

int sum, c; //с - кол-во элементов, sum - сумма элементов


Element* Search(Element* root, int A, Element** p, bool output) //поиск вершины по ключу;  А - искомый ключ; *p - указатель на родит.
{
	if (root != NULL) //если корень не 0
	{
		Element* E = root; //указат. на элемент - это корень
		*p = NULL;
		while (E != NULL && E->x != A) //пока Е не 0 и ключ текущего элемента не равен искомому ключу
		{
			*p = E;
			if (output == true)
				cout << E->x << "\t" << E->s << endl; //ключ текущего элем. и строка текущего элем.
			if (A > E->x)
				E = E->right; //элем. становится правым потомком
			else E = E->left; //элем. становится левым потомком
		}
		return E;
	}
	else return NULL; //ничего не найдено
}


int depth(Element* E) //губина дерева, начиная с узла E (самая длинная ветвь)
{
	if (E == NULL) //если элем равен 0
		return 0;
	else
	{
		int A = depth(E->left); //ф-ция вызывает сама себя (рекурсия)
		int B = depth(E->right); //переменнная дл янахождения глубины справа
		if (A > B)
			return A + 1; //узлы +корень(1)
		else  return B + 1;
	}
}

int HeightTree(Element* E)
{
	int x = 0, y = 0;
	if (E == NULL) return 0;     //пустое дерево или дошли до листа
	if (E->left) x = HeightTree(E->left); //высота левого поддерева
	if (E->right) y = HeightTree(E->right);  //высота правого поддерева
	if (x > y) return x + 1;    //+1 от корня к левому поддереву
	else return y + 1;   //+1 от корня к правому поддереву
}

void show_level(Element* E, int d, int i) //d - текущая глубина, i - требуемая глубина //ф-ция для нахождения уровня
{
	if (E != NULL) //элем. не равен 0
	{
		if (d == i) //если дошли до нужной глубины
			cout << E->x << "\t" << E->s << endl;
		else {
			show_level(E->left, d + 1, i);//для левой ветки
			show_level(E->right, d + 1, i);//для правой ветки
		}
	}
}


void ScanDown(Element* E, void f(Element*)) //нисходящий обход
{
	if (E != NULL)
	{
		f(E); //обрабатываем текущей узел дерева
		ScanDown(E->left, f); //продолжаем обход левого поддерева
		ScanDown(E->right, f); //продолжаем обход правого поддерева
	}
}


void ScanMixed(Element* E, void f(Element*)) //смешанный обход
{
	if (E != NULL)
	{
		ScanMixed(E->left, f); //обход левого поддерева
		f(E);//текущ.элем.
		ScanMixed(E->right, f); //обход правого поддерева
	}
}

void ScanPrev(Element* E, void f(Element*)) //смешанный обход
{
	if (E != NULL)
	{
		ScanPrev(E->left, f); //обход левого поддерева
		ScanPrev(E->right, f); //обход правого поддерева
		f(E);//текущ.элем.
	}
}

void Print(Element* E)
{
	cout << E->x << "\t" << E->s << endl; //вывод одного элемента
}

void Delete(Element* E, Element** p, Element** r) //указатель на родит. и указат. на корень
{
	if (E != NULL)
	{
		Delete(E->left, &E, r); //удаляем левые потомки
		Delete(E->right, &E, r); //правые
								 //удаление самого элемента
		if (*p != NULL)//есть ли родительский элемент
		{
			if (E == (*p)->left) //является ли удаляемый элемент левым потомком
				(*p)->left = NULL; //удаляем
			else (*p)->right = NULL;
		}
		if (E == *r) //если удаляемый элем. является корнем
			(*r) = NULL;//корня нет. удаление
		delete E; //освобождаем память от текущего элемента
	}
}

bool IsBalanced(Element* E) //функция проверки сбалансиров. дерева
{
	if (E == NULL)
		return true;
	else if (IsBalanced(E->left) && IsBalanced(E->right)) //если сбалансированы правое и левое поддеревья
	{
		int l = depth(E->left); //расчитываем глубину левого поддерева
		int r = depth(E->right);
		if (abs(l - r) <= 1) //если модуль разницы глубин меньше либо равен 1
			return true; //дерево сбалансировано
		else return false;
	}
	else return false;
}
