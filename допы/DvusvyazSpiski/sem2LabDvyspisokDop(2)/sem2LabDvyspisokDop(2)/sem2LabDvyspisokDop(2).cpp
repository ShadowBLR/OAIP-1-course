#include <iostream>
using namespace std;
#define str_len 10
#define size 10
struct Node
{
	string surname;
	string name;
	string lastname;
	unsigned int date;
	unsigned short cours;
	unsigned short group;
	unsigned short mark[5];
};
struct Node student[size];
struct Node bad;
int current_size = 0;
void searchMidMarkByGroup()
{
	float* arrMark = new float[5];
	for (int i = 0; i < 5; i++)
		arrMark[i] = 0;
	for (int i = 0; i < current_size; i++)
	{
		arrMark[0] += student[i].mark[0];
		arrMark[1] += student[i].mark[1];
		arrMark[2] += student[i].mark[2];
		arrMark[3] += student[i].mark[3];
		arrMark[4] += student[i].mark[4];
	}
	arrMark[0] /= current_size;
	arrMark[1] /= current_size;
	arrMark[2] /= current_size;
	arrMark[3] /= current_size;
	arrMark[4] /= current_size;
	cout << "Балл по 1 предмету " << arrMark[0] << endl;
	cout << "Балл по 2 предмету " << arrMark[1] << endl;
	cout << "Балл по 3 предмету " << arrMark[2] << endl;
	cout << "Балл по 4 предмету " << arrMark[3] << endl;
	cout << "Балл по 5 предмету " << arrMark[4] << endl;
}
void enter_new()
{
	setlocale(LC_CTYPE, "Russian");
	cout << endl;
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << endl << "Имя: ";
		cin >> student[current_size].name;
		cout << "фамилия: ";
		cin >> student[current_size].surname;
		cout << "Отчество: ";
		cin >> student[current_size].lastname;
		cout << "курс: ";
		cin >> student[current_size].cours;
		cout << "группа: ";
		cin >> student[current_size].group;
		cout << "дата рождения: ";
		cin >> student[current_size].date;
		cout << "Оценки: ";
		for(int i=0;i<5;i++)
		cin >> student[current_size].mark[i];
		current_size++;
		cout << endl;
	}
	else
		cout << "Введено максимальное кол-во строк\n";

}
Node searchOlderStudent()
{
	int index=0;
	int dd=0,mm=0,yy=0;
	dd = student[0].date / 1000000;
	mm = (student[0].date - dd * 1000000) / 10000;
	yy = student[0].date - dd * 1000000 - mm * 10000;
	for (int i = 0; i < current_size; i++)
	{
		if (student[i].date - dd * 1000000 - mm * 10000<yy|| 
			(student[i].date - dd * 1000000 - mm * 10000 == yy&& (student[i].date - dd * 1000000) / 10000>mm)||
			(student[i].date - dd * 1000000 - mm * 10000 == yy && (student[i].date - dd * 1000000) / 10000 == mm&& student[i].date / 1000000>dd))
		{
			dd = student[i].date / 1000000;
			mm = (student[i].date - dd * 1000000) / 10000;
			yy = student[i].date - dd * 1000000 - mm * 10000;
			index = i;
		}
	}
		return student[index];
}
Node searchYoungerStudent()
{
	int index = 0;
	int dd = 0, mm = 0, yy = 0;
	dd = student[0].date / 1000000;
	mm = (student[0].date - dd * 1000000) / 10000;
	yy = student[0].date - dd * 1000000 - mm * 10000;
	for (int i = 0; i < current_size; i++)
	{
		if (student[i].date - dd * 1000000 - mm * 10000 > yy ||
			(student[i].date - dd * 1000000 - mm * 10000 == yy && (student[i].date - dd * 1000000) / 10000 < mm )||
			(student[i].date - dd * 1000000 - mm * 10000 == yy && (student[i].date - dd * 1000000) / 10000 == mm && student[i].date / 1000000 < dd))
		{
			dd = student[i].date / 1000000;
			mm = (student[i].date - dd * 1000000) / 10000;
			yy = student[i].date - dd * 1000000 - mm * 10000;
			index = i;
		}
	}
	return student[index];
}
void searchNiceStudentByGroup()
{
	int group = 1, mark = 0;
	Node temp;
	for (int k = 0; k < current_size; k++)
	{
		for (int i = 0; i < current_size; i++)
			if (student[i].group == group)
			{
				if (student[i].mark[0] + student[i].mark[1] + student[i].mark[2] + student[i].mark[3] + student[i].mark[4] > mark)
				{
					temp = student[i];
					mark = student[i].mark[0] + student[i].mark[1] + student[i].mark[2] + student[i].mark[3] + student[i].mark[4];
				}
			}
		if (mark != 0)
		{
			cout << endl << "Имя: ";
			cout << temp.name << endl;
			cout << "фамилия: ";
			cout << temp.surname << endl;
			cout << "Отчество: ";
			cout << temp.lastname << endl;
			cout << "курс: ";
			cout << temp.cours << endl;
			cout << "группа: ";
			cout << temp.group << endl;
			cout << "дата рождения: ";
			cout << temp.date << endl;
			cout << "Оценки: ";
			for (int i = 0; i < 5; i++)
				cout << temp.mark[i] << " ";
			cout << endl;
		}
		group++;
		mark = 0;
	}
}
void print()
{
	for (int i = 0; i < current_size; i++)
	{
		cout << endl << "Имя: " << endl;
		cout << student[i].name;
		cout << "фамилия: " << endl;
		cout << student[i].surname;
		cout << "Отчество: " << endl;
		cout << student[i].lastname;
		cout << "курс: " << endl;
		cout << student[i].cours;
		cout << "группа: " << endl;
		cout << student[i].group;
		cout << "дата рождения: " << endl;
		cout << student[i].date;
		cout << "Оценки: " << endl;
		for (int j = 0; j < 5; j++)
			cout << student[i].mark[j];
		cout << endl;
	}
}
void out()
{
	setlocale(LC_CTYPE, "Russian");
	for (int j = 0; j < current_size; j++)
		for (int i = 0; i < current_size; i++)
			if (j < i && student[j].cours > student[i].cours)
				swap(student[j], student[i]);
	for (int j = 0; j < current_size; j++)
		for (int i = 0; i < current_size; i++)
			if (student[j].cours == student[i].cours && j<i && student[j].surname[0]>student[i].surname[0])
				swap(student[i], student[j]);
	print();
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int choice;
	do
	{
		cout << "Введите:" << endl;
		cout << "1-для вывода лучших студентов по группам" << endl;
		cout << "2-для ввода новой записи" << endl;
		cout << "3-для среднего балла" << endl;
		cout << "4-для вывода записи(ей)" << endl;
		cout << "5-для поиска старшего студента" << endl;
		cout << "6-для поиска младшего студента" << endl;
		cout << "0-для выхода" << endl;
		cin >> choice;
		Node temp;
		switch (choice)
		{
		case 1:searchNiceStudentByGroup(); break;
		case 2:  enter_new();  break;
		case 3:searchMidMarkByGroup(); break;
		case 4:  out();	break;
		case 5: temp=searchOlderStudent();
			cout << endl << "Имя: ";
			cout << temp.name << endl;
			cout << "фамилия: ";
			cout << temp.surname << endl;
			cout << "Отчество: ";
			cout << temp.lastname << endl;
			cout << "курс: ";
			cout << temp.cours << endl;
			cout << "группа: ";
			cout << temp.group << endl;
			cout << "дата рождения: ";
			cout << temp.date << endl;
			cout << "Оценки: ";
			for (int i = 0; i < 5; i++)
				cout << temp.mark[i] << " ";
			cout << endl;
			break;
		case 6:temp = searchYoungerStudent();
			cout << endl << "Имя: " ;
			cout << temp.name<<endl;
			cout << "фамилия: " ;
			cout << temp.surname << endl;
			cout << "Отчество: " ;
			cout << temp.lastname << endl;
			cout << "курс: " ;
			cout << temp.cours << endl;
			cout << "группа: " ;
			cout << temp.group << endl;
			cout << "дата рождения: " ;
			cout << temp.date << endl;
			cout << "Оценки: ";
			for (int i = 0; i < 5; i++)
				cout << temp.mark[i]<<" ";
			cout << endl;
			break;
		}
		
	} while (choice != 0);
}