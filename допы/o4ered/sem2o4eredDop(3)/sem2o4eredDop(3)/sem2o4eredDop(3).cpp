#include<iostream>
#include <stdio.h>
using namespace std;
struct Number {
	char info;
	Number* next;
};
FILE* f1, * f2;
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
		while (temp != NULL)
		{
			cout << temp->info << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}
void addElement(char n)
{
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
char delEndQueue()
{
	char tmp;
	if (::begin == NULL)
	{
		cout << "Очереддь  пуста\n";
		return ' ';
	}
	Number* pHead = ::begin;
	if (::begin->next == NULL)
	{
		tmp = ::begin->info;
		::begin = NULL;
		tail = NULL;
		delete[]pHead;
		return tmp;
	}
	
	tmp = ::begin->info;
	::begin = ::begin->next;
	delete[]pHead;
	return tmp;
}
int main()
{
	setlocale(LC_ALL, "ru");
	char buf[100]; int count = 0;
	errno_t err;
	err = fopen_s(&f1, "f.txt", "r");
	if (err != NULL)
	{
		printf("Ошибка открытия файла f.txt\n");
		return -1;
	}
	while (fgets(buf, sizeof(buf), f1) != NULL)
		count++;
	cout << count;
	fclose(f1);
	err = fopen_s(&f1, "f.txt", "r");
	if (err != NULL)
	{
		printf("Ошибка открытия файла f.txt\n");
		return -1;
	}
	err = fopen_s(&f2, "g.txt", "w");
	if (err != NULL)
	{
		printf("Ошибка открытия файла g.txt\n");
		return -1;
	}
	int i = 0;
	fgets(buf, sizeof(buf), f1);
	for(int j=0;j<count;j++)
	{
	while (buf[i+1] != '\0')
	{
		if (buf[i] == '0' || buf[i] == '1' || buf[i] == '2' || buf[i] == '3' || buf[i] == '4' || buf[i] == '5'
			|| buf[i] == '6' || buf[i] == '7' || buf[i] == '8' || buf[i] == '9')
			addElement(buf[i]);
		else fprintf(f2, "%c", buf[i]);
		i++;
	}
	while (::begin != NULL)
	{
		fprintf(f2, "%c", delEndQueue());
	}
	fprintf(f2, "%c", '\n');
	count1 = 0;
	i = 0;
	fgets(buf, sizeof(buf), f1);
	}
	fclose(f1);
	fclose(f2);		
	return 0;

}


