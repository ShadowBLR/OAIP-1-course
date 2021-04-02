#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream f1("f1.txt");// дает записывать в файл
	f1 << "1234" << "\n";// записываем строки в файл
	f1 << "aaa" << "\n";
	f1 << "jjjc" << "\n";
	f1 << "ajjugc" << "\n";
	f1 << "abc ahc" << "\n";
	f1 << "afc" << "\n";
	f1.close();

	ifstream f2("f1.txt");//дает просматривать файл(открываем его),считывать
	ofstream f3("f2.txt");// записывает в файл

	char buff[20];//буфер промежуточного хранения считываемого из файла текста

	int c = 0;

	for (int i = 0; i < 20; i++)
	{
		f2.getline(buff, 20);// берет из файла ф1 и записывает в буфере 20 символов(cчитывает строку из файла)
		int n = strlen(buff);// считает кол-во символов в буфере
		if (buff[0] == 'a')
		{
			f3 << buff << "\n";
			if (buff[n] == ' ')
				c++;
		}
	}
	cout << c + 1 << endl;

	f2.close();
	f3.close();
	return 0;
}

