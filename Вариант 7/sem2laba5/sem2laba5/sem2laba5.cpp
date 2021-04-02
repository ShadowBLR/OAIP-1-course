#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
struct List
{
	int	numbreRice;
	char punctNaznach[50];
	char time[50];
	char date[50];
	int price;
};
void addElement(int&count);
void showAll(const int count);
void deleteElement(int &counter);
void searchToPunctNaznach(const int count);
void saveToFile(const int count);
void readFromFile(int&count);
void read(int& count);
List* Rice;
List* tempRice;
FILE* f;
int main()
{
	setlocale(LC_ALL, "ru");
	int count = 0;
	int n;
	do
	{
		printf("Меню\nВвыберите пункт\n");
		printf("1-Добавить элемент\n");
		printf("2-показать все элементы\n");
		printf("3-поиск по пункту назначения\n");
		printf("4-удалить рейс\n");
		printf("5-записать в файл\n");
		printf("6-считать из файла\n");
		printf("0-выход\n");
		std::cin >> n;
		switch (n)
		{
		case 1: 
			addElement(count); break;
		case 2: 
			showAll(count); break;
		case 3:
			searchToPunctNaznach(count); break;
		case 4:
			deleteElement(count);break;
		case 5:
			saveToFile(count); break;
		case 6:
			readFromFile(count); break;
	
		}
	} while (n != 0);

}
void addElement(int&count)
{
	if (count == 0)
	{
		Rice = new List[1];
		printf("Введите номер рейса\n");
		std::cin >> Rice[0].numbreRice;
		printf("Введите пункт назначения\n");
		std::cin >> Rice[0].punctNaznach;
		printf("Введите время отправления\n");
		std::cin >> Rice[0].time;
		printf("Введите дату отправления\n");
		std::cin >> Rice[0].date;
		printf("Введите цену\n");
		std::cin >> Rice[0].price;
	}
	else
	{
		tempRice = new List[count];
		for (int i = 0; i < count; i++)
		{
			tempRice[i] = Rice[i];
		}
		delete[]Rice;
		Rice = new List[count + 1];
		for (int i = 0; i < count; i++)
		{
			Rice[i] = tempRice[i];
		}
		delete[]tempRice;
		std::cout << "Введите номер рейса\n";
		std::cin >> Rice[count].numbreRice;
		std::cout << "Введите пункт назначения\n";
		std::cin >> Rice[count].punctNaznach;
		std::cout << "Введите время отправления\n";
		std::cin >> Rice[count].time;
		std::cout << "Введите дату отправления\n";
		std::cin >> Rice[count].date;
		std::cout << "Введите цену\n";
		std::cin >> Rice[count].price;

	}
	count++;
}
void showAll(const int count)
{
	if (count != 0)
		for (int i = 0; i < count; i++)
		{
			std::cout << "Номер рейса:\n" << Rice[i].numbreRice << std::endl;
			std::cout << "Пункт назначения:\n" << Rice[i].punctNaznach << std::endl;
			std::cout << "Время отправления:\n" << Rice[i].time << std::endl;
			std::cout << "Дата отправления:\n" << Rice[i].date << std::endl;
			std::cout << "Цена:\n" << Rice[i].price << std::endl;
		}
	else std::cout << "\nЭлементов еще нет\n";

}
void searchToPunctNaznach(const int count)
{
	std::string temp;
	std::cout << "Введите пункт назначения\n";
	std::cin >> temp;
	for(int i=0;i<count;i++)
		if (temp == Rice[i].punctNaznach)
		{
			std::cout << "Номер рейса:\n" << Rice[i].numbreRice << std::endl;
			std::cout << "Пункт назначения:\n" << Rice[i].punctNaznach << std::endl;
			std::cout << "Время отправления:\n" << Rice[i].time << std::endl;
			std::cout << "Дата отправления:\n" << Rice[i].date << std::endl;
			std::cout << "Цена:\n" << Rice[i].price << std::endl;
		}
}
void deleteElement(int&count)
{
	int number,flag=0;
	std::cout << "Введите номер рейса\n";
	std::cin >> number;
	for (int i = 0; i < count; i++)
		if (Rice[i].numbreRice == number)
			flag = 1;
	if(flag==1)
	{count--;
		List* tempMas = new List[count];
		for (int i = 0, j = 0; j < count; i++, j++)
		{
			if (Rice[i].numbreRice == number)
			{
				i++;
			}
			tempMas[j] = Rice[i];
		}
		delete[]Rice;
		Rice = new List[count];
		for (int i = 0; i < count; i++)
			Rice[i] = tempMas[i];
		delete[]tempMas;
		std::cout << "Рейс успешно удален\n";
	}
	else std::cout << "Такого рейса не существует\n";
}
void read(int&count)
{
	std::ifstream fin("acplus.dat");
	if (fin.fail())
	{
		std::cout << "\n Ошибка открытия файла";
		exit(1);
	}

	while (!fin.eof())
	{
		if (count == 0)
		{
			Rice = new List[1];
			fin.read((char*)& Rice[count], sizeof(List));

		}
		else
		{
			tempRice = new List[count];
			for (int i = 0; i < count; i++)
			{
				tempRice[i] = Rice[i];
			}
			delete[]Rice;
			Rice = new List[count + 1];
			for (int i = 0; i < count; i++)
			{
				Rice[i] = tempRice[i];
			}
			fin.read((char*)& Rice[count], sizeof(List));
			
			delete[]tempRice;
		}
		count++;
	}
}
void saveToFile(const int count)
{
	if (!fopen_s(&f, "base.bin", "wb"))
	{
		fwrite(&count, sizeof(count), 1, f);
		for (int i = 0; i < count; i++)
		{
			fwrite(&Rice[i], sizeof(List), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}


}
void readFromFile(int &count)
{
	
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		fread(&count, sizeof(int), 1, f);
		Rice = new List[count];
		for (int i = 0; i < count; i++)
			fread(&Rice[i], sizeof(List), 1, f);
		fclose(f);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}


}

