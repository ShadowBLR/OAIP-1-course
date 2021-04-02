#include<iostream> 
using namespace std;
struct Number
{
	int info;
	Number* next;
};
Number* Queue1 = NULL;
Number* Queue2 = NULL;
Number* Queue3 = NULL;
int count1 = 0, count2 = 0, count3 = 0;
void addElement(Number** begin, Number** tail);
void showQueue(Number** begin);
int main()
{
	setlocale(LC_ALL, "ru");
	Number** begin = new Number * [3];
	Number** tail = new  Number * [3];
	for (int i = 0; i < 3; i++)
		begin[i] = tail[i] = NULL;
	int choice;
	do {
		cout << "Меню\n";
		cout << "1 - добавить\n";
		cout << "2 - вывод на экран\n";
		cout << "0 - выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1:addElement(begin, tail); break;
		case 2:showQueue(begin); break;
		case 0:exit; break;
		}
	} while (choice != 0);
	return 0;
}
void showQueue(Number** begin)
{
	Number** temp = new Number * [3];
	for (int i = 0; i < 3; i++)
		temp[i] = begin[i];
	if (temp[0] == NULL)
		cout << "Очередь 1 пуста\n";
	else
	{
		cout << "Очередь 1:\n";
		while (temp[0] != NULL)
		{
			cout << temp[0]->info << " ";
			temp[0] = temp[0]->next;
		}
		
	}
}

void addElement(Number** begin, Number** tail)
{
	int n;
	cout << "Введите число\n";
	cin >> n;
	if (n < 0)
	{
		if (count1 == 0)
		{
			Queue1 = new Number[1];
			Queue1->info = n;
			Queue1->next = NULL;
			begin[0] = tail[0] = &Queue1[0];
		}
		else
		{
			Number* pTail = tail[0];
			Number* t = new Number;
			t->info = n;
			t->next = NULL;
			pTail->next = t;
			tail[0] = t;
		}
		count1++;
	}
	
}