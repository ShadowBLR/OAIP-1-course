#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int k;
	int n1, n2;
	ofstream fout("FILE2");

	static char buf[255] = "";
	gets_s(buf);
	fout << buf;
	fout.close();

	ifstream fin("FILE2");
	fin >> buf;
	static int letter_count, letter_count_buf = 999999, i;
	int q = 0;
	int n = 0, c = 0;
	while (q != 2)
	{
		if (buf[i] == '\0')
			q++;
		if (buf[i] != ' ' && buf[i] != '\0')
		{
			letter_count++;
		}

		else
		{
			n++;
			if (letter_count < letter_count_buf)
			{
				letter_count_buf = letter_count;
				c = n;
			}

			letter_count = 0;
		}
		i++;
	}
	cout << "Слово номер " << c << " букв " << letter_count_buf;
	return 0;
}