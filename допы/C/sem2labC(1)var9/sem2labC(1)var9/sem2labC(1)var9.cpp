#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE* f, * f2;
	errno_t err;
	char buff[50]; int counter = 0;
	err = fopen_s(&f, "text.txt", "r");
	if (err != NULL)
	{
		printf("Ошибка открытия файла\n"); return -1;
	}
	else
		while (!feof(f))
		{
			fgets(buff, 50, f);
			counter++;
		}
	cout << "Count = " << counter << endl;
	int* mas = new int[counter];
	fclose(f);
	err = fopen_s(&f, "text.txt", "r");
	if (err != NULL)
	{
		printf("Ошибка открытия файла\n"); return -1;
	}
	else
	{
		int i = 0;
		while (!feof(f))
		{
			fscanf(f, "%d", &mas[i]);
			cout << mas[i] << " ";
			i++;
		}
	}
	fclose(f);
	for (int i = 0; i < counter; i++)
		for (int j = 0 + i; j < counter; j++)
			if (mas[i] == mas[j] && i != j)
			{
				mas[i] = 0;
			}
	cout << endl;
	for (int i = 0; i < counter; i++)
		if (mas[i] != 0)
			cout << mas[i] << " ";

	err = fopen_s(&f2, "text2.txt", "w");
	if (err != NULL)
	{
		printf("Ошибка открытия файла\n"); return -1;
	}
	else
	{
		for (int i = 0; i < counter; i++)
			if (mas[i] != 0)
				fprintf(f2, "%d\n", mas[i]);
	}
	fclose(f2);
	delete[]mas;

}
