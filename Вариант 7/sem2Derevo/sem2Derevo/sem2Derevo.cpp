#include <iostream>
#include "TreeHeader.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

FILE* f;//Глобальная переменная, для записи  в файл
void Vsev(Element* E)//Сохранине в файл
{
	char buf[10];
	_itoa_s(E->x, buf, 10, 10);
	fwrite(buf, sizeof(char), strlen(buf), f); //запись ключа в файл
	fwrite("\t", sizeof(char), 1, f);
	fwrite(E->s, sizeof(char), strlen(E->s), f);
	fwrite("\n", sizeof(char), 1, f);
}

Tree t;//объявили дерево t. глобальная переменная
void Copy(Element* E)
{
	t.Push(E->x, E->s); //вставляем копию элемента е в дерево t
}

void Balance(Element** E)
{
	if (*E != NULL)
	{
		//if (!IsBalanced(*E)) //пока дерево не сбалансиров.
		for (int i = 0; i < depth(*E) - 1; i++)
		{
			//рекурсивно балансируем левое поддерево
			Balance(&((*E)->left));//берем указатель по двойному указателю, берем указатель на левого потомка и от него(от указат) берем двойной указатель
			Balance(&((*E)->right)); //рекурсивно балансируем правое поддерево
			int l = depth((*E)->left);
			int r = depth((*E)->right);
			if (l - r >= 2) //если левое дерево больше
			{
				Element* old_E = *E;
				*E = (*E)->left; //в качестве нового корня задаём левого потомка
				Element* old_r = (*E)->right; //запоминаем правого потомка нового корня
				(*E)->right = old_E;//задаём новому корню в качестве правого потомка старый корень
				old_E->left = NULL;
				ScanDown(old_r, Copy); //Заполняет дерево элементами старого правого потомка
				old_E = NULL;
				Element* old_r2 = old_r;
				Delete(old_r, &old_E, &old_r2);

			}
			else if ((r - l) >= 2)
			{
				Element* old_E = *E;
				*E = (*E)->right; //в качестве нового корня задаём правого потомка
				Element* old_l = (*E)->left; //запоминаем левого потомка нового корня
				(*E)->left = old_E;//задаём новому корню в качестве левого потомка старый корень
				old_E->right = NULL;
				ScanDown(old_l, Copy); //Заполняет дерево элементами старого левого потомка
				old_E = NULL;
				Element* old_l2 = old_l;
				Delete(old_l, &old_E, &old_l2);
			}
		}
	}
}

std::ostream& operator << (std::ostream& out, FILE* t) //перегрузка
{
	out << t;
	return out;
}
void  numberOfLeaves(Element* temp,int&count)
{
	if (temp == NULL)
	{
		return ;
	}
	if (temp->left == NULL && temp->right == NULL)
	{
		count++;
		return;
	}
	else
	{
		numberOfLeaves(temp->left, count);
		numberOfLeaves(temp->right, count);
	}
	
}
int main()
{
	system("chcp 1251");
	setlocale(LC_CTYPE, "Russian");
	//system("chcp 1251"); system("CLS"); //очистка консол. окна
	int k = -1; //ключ для поиска
	char buf[255];
	Element* p;
	Element* E;
	for (;;)
	{
		cout << "1. Добавление элементов" << endl;
		cout << "2. Загрузка дерева из файла" << endl;
		cout << "3. Запись дерева в файл" << endl;
		cout << "4. Нисходящий обход дерева с выводом элементов" << endl;
		cout << "5. Смешанный обход дерева с выводом элементов" << endl;
		cout << "6. Обратный обход дерева с выводом элементов" << endl;
		cout << "7. Вывод пути до ближайшего элемента с заданным ключом" << endl;
		cout << "8. Удаление элемента дерева по ключу" << endl;
		cout << "9. Проверка сбалансированости дерева" << endl;
		cout << "10. Высота дерева дерева" << endl;
		cout << "11. Насильная балансировка дерева" << endl;
		cout << "12. Подсчет листьев" << endl;
		cout << "0. Выход" << endl;

		int count = 0;
		cin >> k;
		switch (k)
		{
		case 1:
			while (k != 0) //цикл ввода элементов
			{
				cout << "Введите число. 0 - конец ввода. " << endl;
				cin >> k; //вводим ключ для поиска
				if (k != 0)
				{
					cout << "Введите строку " << endl;
					cin >> buf;
					t.Push(k, buf); //вставляем введённый элемент в дерево
				}
			}
			break;
		case 2: cout << "Введите имя файла" << endl;
			cin >> buf;
			t.Load(buf);
			fopen_s(&f, buf, "r");
			break;
		case 3: cout << "Введите имя файла" << endl;
			cin >> buf;
			fopen_s(&f, buf, "w");
			ScanDown(t.root, Vsev);
			fclose(f);
			break;

		case 4: cout << "Прямой (нисходящий) обход дерева" << endl;
			ScanDown(t.root, Print);
			break;
		case 5: cout << "Симметричный (смешанный) обход дерева" << endl;
			ScanMixed(t.root, Print);
			break;

		case 6: cout << "Обратный обход дерева" << endl;
			ScanPrev(t.root, Print);
			break;

		case 7:
			cout << "Введите ключ для поиска " << endl;
			cin >> k;
			if (Search(t.root, k, &p))
			{
				cout << "Путь до ближайшегоэлемента с заданным ключом: " << endl;
				E = Search(t.root, k, &p, true);
				cout << "Элемент с заданным ключом " << E->x << "\t" << E->s << endl;
			}
			else
				cout << "Заданный ключ не найден." << endl;
			break;

		case 8:
			cout << "Введите ключ для удаления " << endl;
			cin >> k;
			E = Search(t.root, k, &p);
			if (E != NULL)
			{
				Delete(E, &p, &(t.root));
			}
			else
				cout << "Заданный ключ не найден." << endl;
			break;
		case 9:
			if (IsBalanced(t.root))
				cout << "Дерево сбалансировано " << endl;
			else
				cout << "Дерево не сбалансировано " << endl;
			break;
		case 10:
			cout << "Высота дерева: ";
			cout << HeightTree(t.root);
			cout << endl;
			break;
		case 11:
			Balance(&(t.root));
			break;
		case 12:
			numberOfLeaves(t.root,count);
			cout << "Число листьев:" << count<<endl;
			break;
		case 0:exit(0); break;
		default:
			cout << k << "= неизвестная команда" << endl;

			break;
		}
	}
	system("pause");
	return 0;
}
