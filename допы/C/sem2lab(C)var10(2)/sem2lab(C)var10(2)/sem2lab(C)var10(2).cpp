#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "ru");
	int a; errno_t err;
	FILE* f1, *f2;
	err = fopen_s(&f1, "f1.txt", "r");
	if (err != 0)
	{
		perror("ошибка открытия f1.txt");
		return;
	}
	char buff[150];
	int count = 0;
	while (!feof(f1))
	{
		fgets(buff,150,f1);
		count++;
	}
	cout << count;
	fclose(f1);
	err = fopen_s(&f1, "f1.txt", "r");
	if (err != 0)
	{
		perror("ошибка открытия f1.txt");
		return;
	}
	char** mas = new char* [count];
	for (int i = 0; i < count; i++)
		 mas[i] = new char[200];
	int i = 0;
	while (!feof(f1))
	{
		fgets(mas[i], 150, f1);
		cout << mas[i];
		i++;
	}
	fclose(f1);
	err = fopen_s(&f2, "f2.txt", "w");
	if (err != 0)
	{
		perror("ошибка открытия f2.txt");
		return;
	}
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		while (mas[i][j] != '\0')
		{
			if (mas[i][j] <= '9' && mas[i][j] >= '0')
				break;
			if (mas[i][j+1] == '\0')
				fputs(mas[i], f2);
				j++;
		}
		j = 0;
	}
	for (int i = 0; i < count; i++)
		delete mas[i];
	delete[] mas;


}

