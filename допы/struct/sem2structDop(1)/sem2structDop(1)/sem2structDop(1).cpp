
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct List
{
	char nameSurname[50];
	int size;
	int *grade;
};
List* student;
List* tempStudent;
void addElement(int& count);
void showAll(const int count);
bool isExcellent(const int number);
int main()
{
	setlocale(LC_ALL, "ru");
	int count = 0; int choice;
	do {
		cout << "МЕНЮ\n";
		cout << "1 - добавить студента\n";
		cout << "2 - вывести на экран всех студентов\n";
		cout << "3 - проверка на отличника\n";
		cout << "4 - соотношение  отличников\n";
		cout << "0 - выход\n";
		std::cin >> choice;
		switch (choice) {
		case 1:addElement(count); break;
		case 2:showAll(count); break;
		case 3:int num; 
			cout << "Введите номер студента\n";
			std::cin >> num;
			if (num > count|| num <1)
				cout << "Такого студента еще нет\n";
			else
			{
				if (isExcellent(num))
					cout << "Отличник! =)\n";
				else cout << "Не отличник! =(\n";
			}
			break;
		case 4:int number=0;
			for (int i = 0; i < count; i++)
				if ((isExcellent(i + 1)))
					number++;
			float res = number*100 / count;
			cout << "Отношение отличников ко всем = "<<res<<"%\n";
		}
	} while (choice != 0);

}
void addElement(int&count)
{
	if (count == 0)
	{
		student = new List[1];
		printf("Введите ФИО\n");
		cin.ignore();
		cin.getline(student[0].nameSurname,50);
		printf("Введите число экзаменов\n");
		std::cin >> student[0].size;
		student[0].grade = new int[student[0].size];
		for (int i = 0; i < student[0].size; i++)
		{
			cout << "Введите оценку по " << i + 1 << " предмету\n";
			cin >> student[0].grade[i];
		}
	}
	else
	{
		tempStudent = new List[count];
		for (int i = 0; i < count; i++)
		{
			tempStudent[i] = student[i];
		}
		delete[]student;
		student = new List[count + 1];
		for (int i = 0; i < count; i++)
		{
			student[i] = tempStudent[i];
		}
		delete[]tempStudent;
		printf("ФИО\n");
		cin.ignore();
		cin.getline(student[count].nameSurname, 50);
		printf("Введите число экзаменов\n");
		std::cin >> student[count].size;
		student[count].grade = new int[student[count].size];
		for (int i = 0; i < student[count].size; i++)
		{
			cout << "Введите оценку по " << i + 1 << " предмету\n";
			cin >> student[count].grade[i];
		}
		
	}
	count++;
}
void showAll(const int count)
{
	if (count != 0)
		for (int i = 0; i < count; i++)
		{
			cout << "ФИО\n"<<student[i].nameSurname;
			cout << "\nЧисло предметов\n"<<student[i].size;
			cout << "\nОценки:";
			for (int j = 0; j < student[i].size;j++)
				cout << student[i].grade[j]<<" ";
			cout << "\n";
		}
	else std::cout << "\nЭлементов еще нет\n";

}
bool isExcellent( int number)
{
	--number;
	int counter = 0;
	for (int i = 0; i < student[number].size; i++)
		if (student[number].grade[i] == 4 || student[number].grade[i] == 5)
			counter++;
	return counter == student[number].size ? true : false;
}


