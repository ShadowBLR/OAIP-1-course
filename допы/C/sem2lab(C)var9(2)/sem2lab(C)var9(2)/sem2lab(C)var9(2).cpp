#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE* f, * f2;
	errno_t err;
	char buff[200]; int counter = 0;
	err = fopen_s(&f, "text.txt", "r");
	if (err != NULL)
	{
		printf("Ошибка открытия файла\n"); return -1;
	}
	else
	while (!feof(f))
		{
			fgets(buff, 200, f);
			counter++;
		}
	fclose(f);
	char** mas = new char*[counter];
	for (int i = 0; i < counter; i++)
		mas[i] = new char[200];
	err = fopen_s(&f, "text.txt", "r");
	int i = 0;
	if (err != NULL)
	{
		printf("Ошибка открытия файла\n"); return -1;
	}
	else
		while (!feof(f))
		{
			fgets(mas[i],200,f);
			cout << mas[i] << " ";
			i++;
			
		}
	fclose(f);
	err = fopen_s(&f2, "text2.txt", "w");
	int number;
	if (err != NULL)
	{
		printf("Ошибка открытия файла\n"); return -1;
	}
	else
	{
		cout << "Введите число символов\n";
		cin >> number;
		for (int i = 0; i < counter; i++)
		{
			if (strlen(mas[i]) > number)
				fprintf(f2, "%s", mas[i]);
		}
	}
	for (int i = 0; i < counter; i++)
		delete mas[i];
	delete[]mas;
}