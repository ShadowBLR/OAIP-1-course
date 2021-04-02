//1 лаба
#include <iostream>
#include <stdio.h>.
using namespace std;

void func(char* arr1, char* arr2, int size)
{
	int q = 0;
	for (int i = 0, y = size - 1; i <= y; i++, y--)
	{
		arr2[q] = arr1[i];
		q++;
		arr2[q] = arr1[y];
		q++;
	}
}

int main()
{
	setlocale(LC_ALL, "");
	int a; errno_t err;
	FILE* f;
	err = fopen_s(&f, "a.txt", "r");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	int size;
	fseek(f, 0L, SEEK_END);
	size = ftell(f);
	fseek(f, 0L, SEEK_SET);
	char* arr, * out_arr;
	arr = new char[size];
	out_arr = new char[size];
	fread(arr, sizeof(char), size, f);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
	}
	cout << '\n';
	func(arr, out_arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << out_arr[i];
	}
	fclose(f);

	err = fopen_s(&f, "a.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	fwrite(out_arr, sizeof(char), size, f);
	fclose(f);
	return 0;
}
