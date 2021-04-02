#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE* f;
	errno_t err;
	err = fopen_s(&f, "text.txt", "w");
	if (err != NULL)
	{
		printf("Ошибка открытия файла\n"); return -1;
	}


	int size;
	cout << "Введите кол-во чисел\n";
	cin >> size;
	int* mas = new int[size];
	for (int i = 0; i < size; i++)
	{
		fprintf(f, "%d\n", rand() % 50 + 1);
	}
	int number1, a = 0, b = 1;
	fclose(f);
	err = fopen_s(&f, "text.txt", "r");
	for (int i = 0; i < size; i++)
	fscanf_s(f, "%d", &mas[i]);
	cout << "Введите число\n"; cin >> number1;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if ((abs(abs((mas[j] + mas[i]) / 2) - number1) < abs(abs((mas[a] + mas[b]) / 2) - number1)) && j != i)
			{
				a = i; b = j;
			}
	cout << mas[a] << " " << mas[b];
	delete[]mas;

}