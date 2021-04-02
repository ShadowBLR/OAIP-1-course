#include<iostream>
using namespace std;
struct Number {
	float info;
	Number* next;
};
int count1 = 0;
Number* begin = NULL;
Number* tail = NULL;
Number* Queue = NULL;
using namespace std;
void showQueue()
{
	Number* temp;
	temp = ::begin;
	if (temp == NULL)
		cout << "Очередь  пуста\n";
	else
	{
		cout << "Очередь :\n";
		while(temp!=NULL)
		{
			cout << temp->info << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}
void addElement()
{
	float n;
	cout << "Введите число\n";
	cin >> n;
	if (count1 == 0)
	{
		Queue = new Number[1];
		Queue->info = n;
		Queue->next = NULL;
		::begin = tail = Queue;
	}
	else
	{
		Number* t = new Number();
		t->info = n;
		t->next = NULL;
		tail->next = t;
		tail = t;
	}
	count1++;
}
void delEndQueue()
{
	if (::begin == NULL)
	{
		cout << "Очереддь  пуста\n";
		return;
	}
	Number* pHead = ::begin;
	if (::begin->next == NULL)
	{
		::begin = NULL;
		tail = NULL;
		delete[]pHead;
		return;
	}
	while (pHead->next != ::tail)
	{
		pHead = pHead->next;
	}
	tail = pHead;
	pHead = pHead->next;
	tail->next = NULL;
	delete[]pHead;
}
void cyclicShift(float max)
{
	if (::begin == NULL)
	{
		cout << "Очередь пуста\n";
		return;
	}
	if (::begin->info == max)
		return;

	while (::begin->info != max)
	{
		tail->next = ::begin;
		::begin = ::begin->next;
		tail=tail->next;
		tail->next = NULL;
		
	}
}	
float searchMaxValue()
{
	float max = 0;
	Number* pHead=::begin;
	while (pHead != NULL)
	{
		if (pHead->info > max)
			max = pHead->info;
		pHead = pHead->next;
	}
	return max;
}
int main()
{
	setlocale(LC_ALL, "ru");
	float max;
	int choice;
	do {
		cout << "Меню\n";
		cout << "1 - добавить\n";
		cout << "2 - вывод на экран\n";
		cout << "3 - удалить последний элемент\n";
		cout << "4 - циклический сдвиг\n";
		cout << "0 - выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1:addElement(); break;
		case 2:showQueue(); break;
		case 3:delEndQueue(); break;
		case 4:cyclicShift(searchMaxValue()); break;
		case 0: break;
		}
	} while (choice != 0);
	return 0;
}
