#include <iostream>
#include <fstream>
using namespace std;
struct list
{
	float var;
	list* next;
};
list* head = NULL;
list* tail = NULL;
void addToEnd(float value)
{
	if (head == NULL)
	{
		head = new list();
		head->var = value;
		tail = head;
		tail->next = NULL;
	}
	else
	{
		tail->next = new list();
		tail = tail->next;
		tail->var = value;
		tail->next = NULL;

	}
}
void addToStart(float value)
{
	list* pointer = new list();
	pointer->var = value;
	pointer->next = head;
	head = pointer;
	pointer = pointer->next;
}
void showList()
{

	if (head != NULL)
	{
		list* pointer;
		pointer = head;
		while (pointer != NULL)
		{
			cout << "число " << pointer->var << endl;
			pointer = pointer->next;

		}
	}
	else cout << "Список пуст\n";
}
void deleteToValue(float value)
{
	list* pointer = head;
	list* temp;
	if (pointer != NULL)
	{
		if (pointer->var == value)
		{
			head = head->next;
			delete[]pointer;
			return;
		}
		while (pointer != NULL)
		{
			if (pointer->next != NULL && pointer->next->var == value)
			{
				temp = pointer->next;
				temp = temp->next;
				delete[]pointer->next;
				pointer->next = temp;
				return;
			}
			pointer = pointer->next;

		}
	}
	else { cout << "Список пуст\n"; return; }

	cout << "Такого элемента нет\n";
}
void saveToFile()
{
	list* pointer = head;
	list buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (pointer != NULL)
	{
		buf = *pointer;
		frm.write((char*)& buf, sizeof(list));
		pointer = pointer->next;
	}
	frm.close();
	cout << "Список записан в файл mList.dat\n";

}
void readFromFile()
{
	list buf, * pointer = NULL;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read((char*)& buf, sizeof(list));
	while (!frm.eof())
	{
		addToEnd(buf.var);
		cout << "-->" << buf.var;
		frm.read((char*)& buf, sizeof(list));
	}
	cout << "-->NULL" << endl;
	frm.close();
	cout << "\nСписок считан из файла mList.dat\n";

}
void multipl()
{
	float mult = 1;
	list* pointer = head;
	while (pointer != 0)
	{
		if (pointer->var < 10)
		{
			mult *= pointer->var;
		}
		pointer = pointer->next;
	}
	if (mult == 1)
		cout << "Таких элементов нет\n";
	else cout << "Произведение = " << mult << endl;

}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int choice;
	float value;
	do {
		cout << "Меню" << endl;
		cout << "1-добавить элемент в конец списка" << endl;
		cout << "2-добавить элемент в начало списка" << endl;
		cout << "3-вывести весь список" << endl;
		cout << "4-удалить элемент по значению" << endl;
		cout << "5-сохранить в файл" << endl;
		cout << "6-считать из файла" << endl;
		cout << "7-найти произведение" << endl;
		cout << "0-выход" << endl;
		cin >> choice;
		system("cls");
		switch (choice) {
		case 1: {
			cout << "Введите число\n";
			cin >> value;
			addToEnd(value); break;
		}
		case 2: {
			cout << "Введите число\n";
			cin >> value;
			addToStart(value); break;
		}
		case 3: {showList(); break; }
		case 4: {cout << "Введите значение\n";
			cin >> value;
			deleteToValue(value); break; }
		case 5: {saveToFile(); break; }
		case 6: {readFromFile(); break; }
		case 7: {multipl(); break; }
		case 0:break;
		}
	} while (choice != 0);

}
