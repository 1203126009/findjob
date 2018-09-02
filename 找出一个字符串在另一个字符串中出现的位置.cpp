#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str("swfghswghhjswsw");
	int num = 0;
	size_t fi = str.find("sw", 0);//第一个位置
	while (fi != str.npos)
	{
		cout << fi << "   ";
		num++;
		fi = str.find("sw", fi + 1);
	}
	if (0 == num)
		cout << "not find!";
	cout << endl;
	system("pause");
	return 0;
}