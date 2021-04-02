#include "Hash.h"
#include <iostream>
#include <time.h>
using namespace std;
struct AAA
{
	char key[10];
	string mas;
	AAA(char* k, char* z)
	{
		int i = 0;
		while (k[i++] != '\0')
			key[i] = k[i];
		mas = z;
	} AAA() {}
};
char* key(void* d)
{
	AAA* f = (AAA*)d;   return f->key;//возврат ключа
}
void AAA_print(void* d)
{
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;//вывод ключа и значения
}
int main()
{
	setlocale(LC_ALL, "rus");
	int siz = 10, choice;
	char k[10];
	cout << "Введите размер хеш-таблицы" << endl; 	cin >> siz;
	Object H = create(siz, key);
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;   cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: H.scan(AAA_print);  break;
		case 2: { AAA* a = new AAA;
			char* str = new char[10];
			cout << "введите ключ" << endl;
			cin >> k;
			int i = 0;
			while (k[i] != '\0')
			{
				a->key[i] = k[i];
				i++;
			}
			a->key[i] = '\0';
			cout << "введите строку" << endl; cin >> str;
			a->mas = str;
			if (H.N == H.size)
				cout << "Таблица заполнена" << endl;
			else
				H.insert(a);
		} break;
		case 3: {  cout << "введите ключ для удаления" << endl;
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4: {
			
			cout << "введите ключ для поиска" << endl;
			cin >> k;
			if (H.search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(H.search(k));
			unsigned int t1 = clock();
			H.search(k);
			unsigned int t2 = clock();
			cout << "Вермя " << t2 - t1 << endl;
		}  break;
		}
	}
	return 0;
}
