#include <iostream>
#include <fstream>
using namespace std;
struct Element
{
	int c;
	Element()
	{
		c = 0;
	}
};
int count = 128;
int Hash(int c)
{
	return (c ^ 'a')%(::count);
}
int newHash(int c, int& i)
{
	return (c ^ 'a')%(::count) + i++;
}
void add(Element*& Head, int c)
{
	if (Head[Hash(c)].c == 0)
	{
		Head[Hash(c)].c = c;
	}
	else if (Head[Hash(c)].c == c)
		return;
	else {
		int a = 0;
		while (Head[newHash(c, ++a)].c != 0 )
		{
			if (a > 128)
				return;
		}
		Head[newHash(c, a)].c = c;	
	}
}
void search(Element* head, int c)
{
	if (head[Hash(c)].c == c)
	{
		cout << "номер " << Hash(c) << " число " << c  << endl;
		return;
	}
	else {
		int count = 0;
		while (head[newHash(c, ++count)].c != 0)
		{
			cout << "Не тот\n";
			if (count > 128)
				break;
		}
		cout << "Такого элемента нет\n";
	}
}
void printTable(Element* head)
{
	for (int i = 0; i < 128; i++)
	{
		if (head[i].c)
			cout << i << " " << head[i].c << endl;
		else
			cout << i << " " << "пусто\n";
	}
}
Element* create(Element* head, int size)
{
	head = new Element[size];
	return head;
}
void readFromFile(Element*& head)
{
	ifstream fin("test.txt");
	int i;
	while (!fin.eof())
	{
		fin >> i;
		add(head, i);
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	Element* Head = NULL;
	Head = create(Head, ::count);
	readFromFile(Head);
	printTable(Head);
	int i1; cout << "\nВведите число для поиска\n";
	cin >> i1;
	search(Head, i1);
}