#include <fstream>
#include <iostream>
using namespace std;
int main()
{

	int k; FILE* fin;
	int n1, n2;


	cin >> n1 >> n2;
	fopen_s(&fin, "FILE1", "rt");
	ofstream fout("FILE2");
	static char buf[255] = "";
	int bufi = 0;
	int si = 0;
	for (int i = 0; i < n1; i++)
	{
		if (feof(fin))
			break;
		fgets(buf, 254, fin);
	}
	bool q = true;
	for (int i = n1; i < n2; i++)
	{
		if (feof(fin))
			break;
		fgets(buf, 254, fin);
		if (buf[0] == 'C' || buf[0] == 'c')
		{
			if (q)
			{
				q = false;
				static int coutt;
				for (int j = 0; j < strlen(buf); j++)
				{
					if (buf[j] == ' ')
						coutt++;
				}
				cout << ++coutt;
			}
			fout << buf;
		}
	}
	fclose(fin);
	fout.close();
	return 0;
}