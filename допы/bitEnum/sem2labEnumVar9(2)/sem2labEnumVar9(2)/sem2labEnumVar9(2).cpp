#include<iostream>	
#include<Windows.h>
using namespace std;
#define size 4
union fly2 {
	fly2()
	{};
	~fly2()
	{};
	string name;
	string surName;
	string lastName;
	string classSchool;
	int fiz;
	int math;
	int langue;
	float srBall = (fiz + math + langue) / 3;
};
fly2 flyy;
struct student {
	string name;
	string surName;
	string lastName;
	string classSchool;
	int fiz;
	int math;
	int langue;
	float srBall = (fiz + math + langue) / 3;
};
student arr[size];
int i = 0;
int oper;

void input();
void remove();
void output();
void search();

int main()
{
	setlocale(LC_ALL, "ru");
	do {
		cout << "Что вы хотите сделать?\n";
		cout << "1 - Ввод данных в структуру\n";
		cout << "2 - Удаление данных из структуры\n";
		cout << "3 - Вывод данных на экран\n";
		cout << "4 - Поиск по фамилии\n";
		cout << "5 - Для завершения работы\n";
		cin >> oper;
		switch (oper)
		{
		case 1:  input(); break;
		case 2:  remove(); break;
		case 3:  output(); break;
		case 4:  search(); break;
		default:break;
		}
	} while (oper != 5);
	system("pause");
}

void input()
{
	if (i < size)
	{
		cout << "Имя";
		cin >> flyy.name;
		arr[i].name = flyy.name;
		cout << "Фамилия";
		cin >> flyy.surName;
		arr[i].surName = flyy.surName;
		cout << "Отчество";
		cin >> flyy.lastName;
		arr[i].lastName = flyy.lastName;
		cout << "класс";
		cin >> flyy.classSchool;
		arr[i].classSchool = flyy.classSchool;
		cout << "физика";
		cin >> flyy.fiz;
		arr[i].fiz = flyy.fiz;
		cout << "математика";
		cin >> flyy.math;
		arr[i].math = flyy.math;
		cout << "по руссокому языку";
		cin >> flyy.langue;
		arr[i].langue = flyy.langue;
		arr[i].srBall = (arr[i].fiz + arr[i].math + arr[i].langue) / 3;
		i++;
		cout << "-------------------------------------------" << endl;
	}
	else
		cout << "Введено максимальное кол-во строк!\n";
}
void output()
{
	for (int i = 0; i < ::i; i++)
	{
		cout << "\nИмя "<<arr[i].name;
		cout << "\nФамилия " << arr[i].surName;
		cout << "\nОтчество " << arr[i].lastName;
		cout << "\nкласс" << arr[i].classSchool;
		cout << "\nфизика "<<arr[i].fiz;
		cout << "\nматематика " << arr[i].math;
		cout << "\nпо руссокому языку " << arr[i].langue;
		cout << "\nсредний балл " << arr[i].srBall;
		cout << "\n-------------------------------------------" << endl;
	}
}
void remove()
{
	if (i > 0)
	{
		int d;
		cout << "Номер записи, которую нужно удалить: "; cin >> d;
		for (int de1 = (d - 1); de1 < i; de1++)
			arr[de1] = arr[de1 + 1];
		i--;
		cout << "Запись удалена" << endl;
	}
	else
		cout << "Недостаточно информации!" << endl;
	cout << "-------------------------------------------" << endl;
}
void search()
{
	string temp;
	cout << "Введиет фамилию\n";
	cin >> temp;
	for (int i = 0; i < ::i; i++)
		if (temp == arr[i].surName)
		{
			cout << "\nИмя " << arr[i].name;
			cout << "\nФамилия " << arr[i].surName;
			cout << "\nОтчество " << arr[i].lastName;
			cout << "\nкласс" << arr[i].classSchool;
			cout << "\nфизика " << arr[i].fiz;
			cout << "\nматематика " << arr[i].math;
			cout << "\nпо руссокому языку " << arr[i].langue;
			cout << "\nсредний балл " << arr[i].srBall;
			cout << "\n-------------------------------------------" << endl;
		}
		else
			cout << "Недостаточно информации!" << endl;
}
