#include <fstream>
#include <iostream>
using namespace std;
int main()
{

	ifstream fin("FILE1");
	ofstream fout("FILE2");
	static char buf[255] = "";
	do
	{
		fin >> buf;
		fin >> buf;
		fout << buf << '\n';
	} while (buf[0] != '\0');
	FILE* f;



	fin.close();
	fout.close();
	fopen_s(&f, "FILE1", "r");
	fseek(f, 0L, SEEK_END);
	cout << ftell(f) << '\n';
	fclose(f);
	fopen_s(&f, "FILE2", "r");
	fseek(f, 0L, SEEK_END);
	cout << ftell(f) << '\n';
	fclose(f);
	return 0;
}