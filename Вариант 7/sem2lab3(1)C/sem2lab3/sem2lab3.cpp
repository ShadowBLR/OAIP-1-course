﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
void showArr(int* arr)
{
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int a; errno_t err;
	int A1[10], B1[10], C1[10],D1[10];
	FILE* A, * B, * C, * D;
	/*err = fopen_s(&A, "A.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	fopen_s(&B, "B.txt", "w");
	fopen_s(&C, "C.txt", "w");
	for (int i = 0; i < 10; i++)
	{
		fprintf(A, "%d", rand() % 10);
		fprintf(B, "%d", rand() % 10);
		fprintf(C, "%d", rand() % 10);
	}
	fclose(A);
	fclose(B);
	fclose(C);*/
	fopen_s(&A, "A.txt", "r");
	fopen_s(&B, "B.txt", "r");
	fopen_s(&C, "C.txt", "r");
	for (int i = 0; i < 10; i++)
	{
		fscanf(A, "%d", &A1[i]);
		fscanf(B, "%d", &B1[i]);
		fscanf(C, "%d", &C1[i]);
	}
	showArr(A1);
	showArr(B1);
	showArr(C1);
	fclose(A);
	fclose(B);
	fclose(C);
	int temp;
	for (int i = 0; i < 10; i++)
	{
		temp = 0;
		if (A1[i] > temp)
			temp = A1[i];
		if (B1[i] > temp)
			temp = B1[i];
		if (C1[i] > temp)
			temp = C1[i];
		D1[i] = temp;
	}

	fopen_s(&D, "D.txt", "w");
	for (int i = 0; i < 10; i++)
	{
			fprintf(D, "%d",D1[i]);

	}
	fclose(D);
}
