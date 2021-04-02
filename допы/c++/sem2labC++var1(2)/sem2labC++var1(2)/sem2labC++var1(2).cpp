#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{

	int k;
	int n1, n2;
	FILE* fin;
	ofstream fout("FILE2");

	static char buf[255] = "";
	gets_s(buf);
	fout << buf;
	fout.close();

	fopen_s(&fin, "FILE2", "r");
	int a = 0;
	int q = 1;
	char str[80];
	while (q != -1)
	{
		q = fscanf_s(fin, "%d", &a); //0 когда считало строку
		if (a % 2 != 0 && q == 1)
			cout << a << ' ';
		if (q == 0)
		{
			fscanf_s(fin, "%s", str, 20);
		}

	};
	fclose(fin);
	return 0;
}