#include <iostream>
using namespace std;
struct nation
{
	char name[30];
	char capital[30];
	unsigned int strength;
	unsigned int area;
	enum formsOfGuvernment
	{
		constitutionalMonarchy = 1, republic,
		absoluteMonarchy
	};
	formsOfGuvernment forms;
};
nation *newNation = NULL;
nation* tempNation = NULL;
void addNation(int&count)
{
	int n;
	if (count == 0)
	{
		newNation = new nation[1];
		printf("\nНазвание государства\n");
		std::cin >> newNation[0].name;
		printf("Столица\n");
		std::cin >> newNation[0].capital;
		printf("население\n");
		std::cin >> newNation[0].strength;
		printf("Площадь\n");
		std::cin >> newNation[0].area;
		printf("форма правления \n1-Конс.монархия\n2-Республика\n3-Абсолютная монархия\n\n");
		cin >> n;
		switch (n)
		{
		case 1:newNation[0].forms = nation::constitutionalMonarchy; break;
		case 2:newNation[0].forms = nation::republic; break;
		case 3:newNation[0].forms = nation::absoluteMonarchy; break;
		}
	}
	else
	{
		tempNation = new nation[count];
		for (int i = 0; i < count; i++)
		{
			tempNation[i] = newNation[i];
		}
		delete[]newNation;
		newNation = new nation[count + 1];
		for (int i = 0; i < count; i++)
		{
			newNation[i] = tempNation[i];
		}
		delete[]tempNation;
		printf("Название государства\n");
		std::cin >> newNation[count].name;
		printf("Столица\n");
		std::cin >> newNation[count].capital;
		printf("население\n");
		std::cin >> newNation[count].strength;
		printf("Площадь\n");
		std::cin >> newNation[count].area;
		printf("форма правления 1-Конс.монархия\n2-Республика\n3-Абсолютная монархия\n\n");
		cin >> n;
		switch (n)
		{
		case 1:newNation[count].forms = nation::constitutionalMonarchy; break;
		case 2:newNation[count].forms = nation::republic; break;
		case 3:newNation[count].forms = nation::absoluteMonarchy; break;
		}

	}
	count++;
}
void showAllNation(const int count)
{
	if (count == 0)
	{
		cout << "элементов нет\n";
		return;
	}
	for (int i = 0; i < count; i++)
	{
		printf("\nНазвание государства\n");
		std::cout << newNation[i].name;
		printf("\nСтолица\n");
		std::cout << newNation[i].capital;
		printf("\nнаселение\n");
		std::cout << newNation[i].strength;
		printf("\nПлощадь\n");
		std::cout << newNation[i].area;
		printf("\nформа правления \n");
		switch(newNation[i].forms)
		{
		case 1:cout << "\nКонституционная монархия\n"; break;
		case 2:cout << "\nРеспублика\n"; break;
		case 3:cout << "\nАбсолютная монархия\n"; break;
		}
	}
}
void searchNationByArea(const int count)
{
	int tempArea;
	cout << "\nВведите площадь\n";
	cin >> tempArea;
	for (int i = 0; i < count; i++)
	{
		if (newNation[i].area > tempArea)
		{
			printf("\nНазвание государства\n");
			std::cout << newNation[i].name;
			printf("\nСтолица\n");
			std::cout << newNation[i].capital;
			printf("\nнаселение\n");
			std::cout << newNation[i].strength;
			printf("\nПлощадь\n");
			std::cout << newNation[i].area;
			printf("\nформа правления \n");
			switch (newNation[i].forms)
			{
			case 1:cout << "\nКонституционная монархия\n"; break;
			case 2:cout << "\nРеспублика\n"; break;
			case 3:cout << "\nАбсолютная монархия\n"; break;
			}
		}
	}
}
void deleteNationByStrength(int &count)
{
	int number, flag, temp = -1;
	std::cout << "Введите численность населения\n";
	std::cin >> number;
	for (int i = 0; i < count; i++)
		if (newNation[i].strength == number)
			temp = i;
	if (temp != -1)
	{
		count--;
		nation* tempMas = new nation[count];
		for (int i = 0, j = 0; j < count; i++, j++)
			if (i == temp)
			{
				i++;
				tempMas[j] = newNation[i];
			}
			else tempMas[j] = newNation[i];
		delete[]newNation;
		newNation = new nation[count];
		for (int i = 0; i < count; i++)
			newNation[i] = tempMas[i];
		delete[]tempMas;
		std::cout << "государство успешно удалено\n";
	}
	else std::cout << "Такого государства не существует\n";
}
int main()
{
	setlocale(LC_ALL, "ru");
	int count = 0;
	int choice;
	do {
		printf("Меню\nВвыберите пункт\n");
		printf("1-Добавить элемент\n");
		printf("2-показать все элементы\n");
		printf("3-поиск по площади\n");
		printf("4-удаление по населению\n");
		printf("0-выход\n");
		cin >> choice;
		switch (choice)
		{
		case 1:addNation(count); break;
		case 2:showAllNation(count); break;
		case 3:searchNationByArea(count); break;
		case 4:deleteNationByStrength(count); break;
		default: exit;
		}

	} while (choice != 0);
	
}

