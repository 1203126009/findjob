#include<iostream>
#include<string>
#include <sstream>
using namespace std;
string  charToString(char *s){//字符串转string
	string res(s);
	return res;
}

char *stringTochar(string s){//string转字符串
	char* c;
	int len = s.length();
	c = new char[len + 1];
	strcpy(c, s.c_str());
	return c;
}

int main(){
	//c风格字符串转int
	 int a=  atoi("1024");
	 cout << a << endl;

	//int转c风格字符串
	int number = 100;
	char str[7];
	_itoa(number, str, 10);
	cout << str << endl;

	//string 转int 
	
	/*方法1：atoi   c_str()   /
	string str2 = "1000";
	int n = atoi(str2.c_str());
		cout << n << endl;
	/*方法2： 流实现*/
		stringstream ss2;
		int n4;
		string str4="1235466";
		ss2 << str4;
		ss2 >> n4;
		cout << n4 << endl;


   //int 转string
/* 方法1：   to_string             */
		int i = 12;
		cout << std::to_string(i) << endl;


/* 方法2： 流实现*/
		stringstream ss;
		int n1 = 123;
		string str3;
		ss << n1;
		ss >> str3;

		cout << str3 << endl;
	system("pause");
}
