#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	int k;
	//fopen_s(&fin, "FILE1", "rt");
	ofstream fout("FILE2");
	static char buf[255] = "";
	cin >> buf;
	//cout << buf<<endl;
	fout << buf;
	fout.close();
	ifstream fin("FILE2");
	fin >> buf;
	fin.close();
	//cout << buf;
	bool bol = true;
	for (int i = 0; i < strlen(buf); i++)
	{
		if (buf[i] >= '0' && buf[i] <= '9')
			cout << buf[i];
		if ((buf[i] == ',' || buf[i] == '.') && bol)
		{
			cout << buf[i];
			bol = false;
		}
	}
	return 0;
}