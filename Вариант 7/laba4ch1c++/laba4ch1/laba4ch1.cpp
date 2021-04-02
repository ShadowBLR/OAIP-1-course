#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>


using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	ifstream in("f1.txt");
	if (!in) {
		cout << "Failure to open input file" << endl;
		return 1;
	}
	ofstream out("f2.txt");
	if (!out) {
		cout << "Failure to open output file" << endl;
		return 1;
	}
	string str,buff;
	int counter = 0;
	while (getline(in, str))
	{
		counter++;
	}
	string* mas = new string[counter];
	in.clear();
	in.seekg(0);
	for (int i = 0; i < counter; i++)
	{
		getline(in, mas[i]);
		cout << mas[i] << endl;
	}
	in.clear();
	in.seekg(0);
	for (int i = 0; i < counter; i++)
	{
		in >> str;
		getline(in, buff);
		if (str == mas[i])
			out << str<<endl;
	}
	in.close();
	out.close();
	delete[]mas;
	ifstream in2("f2.txt");
	if (!in) {
		cout << "Failure to open input file" << endl;
		return 1;
	}
	counter = 0;
	while (getline(in2, str))
	{
		counter++;
	}
	string* arr = new string[counter];
	in2.clear();
	in2.seekg(0);
	for(int i=0;i<counter;i++)
		in2 >> arr[i];
	int size=100,number=0;
	for (int i = 0; i < counter; i++)
		if (arr[i].size() < size)
		{
			size = arr[i].size();
			number = i;
		}
	cout <<"\nСамое короткое слово:"<<arr[number] << endl;
	delete[]arr;

}
