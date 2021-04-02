#include <iostream>
#include <string>
#include <windows.h>
#define NULL_BYTE '\0'
#define ENDL '\n'
using namespace std;
struct Element	//структура для хранения данных в хеш-таблице
{
	unsigned char c = NULL_BYTE;//буква, содержащаяся в строке
	int count=0;//число её вхождений в строку
};
int Hash(unsigned char c)//функция вычисления hash 
{
	return (c ^ 'a')%128;
}
int newHash(unsigned char c,int &i)//функция для повторного хеширования в случае возникновения коллизии
{
	return (c ^ 'a'+i++)%128;
}
void add(Element* &Head,unsigned char c)//добавление элемента в хеш-таблицу
{
	int tempHash;

	if (Head[tempHash=Hash(c)].c == NULL_BYTE)
	{
		Head[tempHash].c = c;
		Head[tempHash].count++;
	}
	else if (Head[tempHash].c == c)
		Head[tempHash].count++;
	else {
		int a = 0;
		while (Head[newHash(c,a)].c != NULL_BYTE || Head[newHash(c,a)].c == c);
		if (Head[newHash(c,--a)].c == NULL_BYTE)
			Head[newHash(c,a)].c = c;
		else if (Head[newHash(c,--a)].c == c)
			Head[newHash(c,a)].count++;
	}
}
void printElement(Element* head, int index)
{
	cout << "номер " << index << " символ " << head[index].c << " количество " << head[index].count << endl;
}
void search(Element *head,unsigned char c)//функция для поиска элемента в хеш-таблице по заданному символу
{
	int tempHash;
	if (head[tempHash=Hash(c)].c == c)
	{
		printElement(head, tempHash);
	}
	else 
	{
		int count = 0;
		while (head[tempHash=newHash(c, count)].c!=c)
		{
			if (count > 127)
			{
				cout << "Такого элемента нет\n";
				return ;
			}
			if (tempHash == 127)
				count = -127;
		}
		printElement(head, tempHash);
	}
}

void printTable(Element*head)//фнукция вывода элементов таблицы
{
	for (int i = 0; i < 128; i++)
		cout << i << " " << head[i].c<<" число вхождений "<<head[i].count<<endl;
}
Element* create(Element*head ,int size)//выделение памяти под таблицу указанного размера
{
	head = new Element[size];
	return head;
}
void deleteElement(Element* head)//очистка памяти 
{
	delete[]head;
}
int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "ru");
	Element* Head = NULL;
	unsigned char ch;
	Head = create(Head, 128);
	while((ch=getchar()) !=ENDL)
	{
		add(Head,ch);
	}

	printTable(Head);
	cout << "Введите символ "; 
	cin >> ch;
	search(Head, ch);
	deleteElement(Head);
}