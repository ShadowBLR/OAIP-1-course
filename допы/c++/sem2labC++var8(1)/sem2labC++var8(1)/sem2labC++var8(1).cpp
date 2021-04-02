#include <fstream>
#include <iostream>
using namespace std;
int count(char* arr, int len)
{
	int ans = 0;
	char chars[] = { 'a', 'e', 'i', 'o', 'u', 'y' };
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 6; j++)
			if (arr[i] == chars[j])
			{
				ans++;
				break;
			}
	}
	return(ans);
}

int main()
{
	int k; FILE* fin;
	fopen_s(&fin, "FILE1", "rt");
	ofstream fout("FILE2");
	static char buf[255] = "";
	int bufi = 0;
	int si = 0;
	while (!feof(fin))
	{
		char s[255] = "";
		if (buf[0] == 0)
		{
			fgets(buf, 254, fin);
			bufi = count(buf, strlen(buf));
			continue;
		}
		fgets(s, 254, fin);
		si = count(s, strlen(s));
		if (si <= bufi)
		{
			fout << s;
		}
		else
		{
			fout << buf;
			for (int i = 0; i < strlen(s) + 1; i++)
			{
				buf[i] = s[i];
			}
			bufi = si;

		}
	}
	fclose(fin);
	fout.close();
	return 0;
}