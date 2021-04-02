#include <stdio.h>  
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
void saveToFile(char* str, int position)
{
	int currentPosition = 1, countProb = 0;
	ifstream fin("f1.txt");
	if (!fin.is_open())
		cout << "File not found is open\n";
	else {
		while (currentPosition <= position)
		{
			if (str[currentPosition - 1] == ' ' && currentPosition != 1)
				countProb++;

			if (currentPosition == position && str[position - 1] != ' ')
				countProb++;
			currentPosition++;
		}
		cout << "Слово на позии имеет номер " << countProb;
	}
}
int main()
{/*2. Ввести с клавиатуры строку символов, состоящую из цифр и слов, разделенных пробелами, и записать ее в файл.
 Прочитать из файла данные и вывести на экран номер слова, содержащего k-й по счету с начала символ.
 Если в k-й позиции пробел, то вывести номер предыдущего слова. */
	setlocale(LC_ALL, "ru");
	char buff[50];
	ofstream fout("f1.txt");
	char str[50];
	cin.getline(str, 49);
	fout << str;
	fout.close();
	int position;
	cout << "Введите позицию\n";
	cin >> position;
	saveToFile(str, position);


}