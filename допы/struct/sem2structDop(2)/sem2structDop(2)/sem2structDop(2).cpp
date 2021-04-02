#include <iostream>
#include <stdio.h>
#include <string>

int choice;

struct TRAIN {
	int number = 0;
	char name[50];
	char time_out[6];
};

struct TRAIN a[3];
int count = 0;

void enter_new_train() {
	std::cout << "Ввод данных" << std::endl;
	if (count < 3) {
		std::cout << " Номер поезда: " << std::endl;
		std::cin >> a[count].number;
		std::cout << "Пункт назначения: " << std::endl;
		std::cin >> a[count].name;
		std::cout << "Время отправления: " << std::endl;
		std::cin >> a[count].time_out;
		count++;
	}
	else {
		std::cout << "Введено максимальное кол-во строк" << std::endl;
	}
}
void sort()
{
	TRAIN temp;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if (a[j].name[0] > a[j + 1].name[0]&&j+1<3)
			{
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
}

void out()
{


	for (int i = 0; i < 3; i++) {
		std::cout << "Номер поезда: " << std::endl;
		std::cout << a[i].number << std::endl;
		std::cout << "Пункт назначения: " << std::endl;
		std::cout << a[i].name << std::endl;
		std::cout << "Время отправления: " << std::endl;
		std::cout << a[i].time_out << std::endl;
		std::cout << std::endl;
	}
}

void inf() {
	
	char time[6];
	std::cout << "Время отправки: ";
	std::cin >> time;
	char ch1[5], ch2[5];
	ch1[0] = time[0];
	ch1[1] = time[1];
	ch1[2] = time[3];
	ch1[3] = time[4];
	int ach = atoi(ch1);
	for (int i = 0; i < 3; i++)
	{
		ch2[0] = a[i].time_out[0];
		ch2[1] = a[i].time_out[1];
		ch2[2] = a[i].time_out[3];
		ch2[3] = a[i].time_out[4];
		if (ach < atoi(ch2))
		{
			std::cout << "Номер поезда: " << std::endl;
			std::cout << a[i].number << std::endl;
			std::cout << "Пункт назначения: " << std::endl;
			std::cout << a[i].name << std::endl;
			std::cout << "Время отправления: " << std::endl;
			std::cout << a[i].time_out << std::endl;
			std::cout << std::endl;
		}
	}
		


}

void main() {
	setlocale(LC_ALL, "ru");	
	do
	{
		std::cout << "Введите:" << std::endl;
		std::cout << "1-для ввода новой записи" << std::endl;
		std::cout << "2-для вывода записей" << std::endl;
		std::cout << "3-для сортировки в алфавитном порядке" << std::endl;
		std::cout << "4-для выборки" << std::endl;
		std::cout << "5-для выхода" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1:  enter_new_train();	break;
		case 2:  out();	break;
		case 3:sort(); break;
		case 4:inf(); break;
		}
	} while (choice != 5);
}