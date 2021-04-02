#include <iostream>
#include <fstream>
using namespace std;
struct Element
{
	string s;
	Element()
	{
		s[0] = '\0';
	}
};
int size;
int Hash(string c)
{
	int sum=0;
	for (int i = 0; i < c.length(); i++)
	{
		sum += c[i]^'a';
	}
	return sum % ::size;
}
int newHash(string c, int& i)
{
	int sum = 0;
	for (int i = 0; i < c.length(); i++)
	{
		sum += c[i] ^ 'a';
	}
	return (sum+i) % ::size;
}
void add(Element*& Head, string c)
{
	if (Head[Hash(c)].s[0] == '\0')
		Head[Hash(c)].s = c;
	else {
		int count = 0;
		while (Head[newHash(c, ++count)].s[0] != '\0')
		{
			if (count > ::size)
				break;
		}
		Head[newHash(c,count)].s = c;
	}
}
void search(Element* head, string c)
{
	if (head[Hash(c)].s == c)
	{
		cout << "number " << Hash(c) << " slovo " << c << endl;
		return;
	}
	else {
		int count = 0;
		while (head[newHash(c, ++count)].s != c)
		{
			if (count > ::size)
			{
				cout << "Такого элемента нет\n";
				return;
			}
		}
		cout << "number " << newHash(c,count) << " slovo " << c << endl;
		
	}
}
void printTable(Element* head)
{
	for (int i = 0; i < ::size; i++)
		cout << i << " " << head[i].s  << endl;
}
void deleteElementForSymbol(Element* &head, char ch)
{
	for (int i = 0; i < ::size; i++)
		if (head[i].s[0] == ch)
			head[i].s.clear();
}
Element* create(Element* head, int size)
	{
	head = new Element[::size];
	return head;
}
void readFromFile(Element*&head)
{
	ifstream fin("test.txt");
	string str;
	while(!fin.eof())
	{
	fin >> str;
	add(head, str); 
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	Element* Head = NULL;
	cout << "Введите размер "; cin >> ::size;
	Head = create(Head, ::size);
	readFromFile(Head);
	printTable(Head);
	string str;
	cout << "введите слово ";
	cin >> str;
	search(Head, str);
	char ch;
	cout << "Введите 1 букву ";
	cin >> ch;
	deleteElementForSymbol(Head, ch);
	printTable(Head);


}