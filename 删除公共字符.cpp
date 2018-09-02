#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	string s1,s2;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s2.size();i++)
	{
		int index ;
		while ((index = s1.find(s2[i])) != -1)//没找到时返回-1
		{
			s1.erase(index,1);
		}
	}
	cout << s1 << endl;
	

	/*
	string s;
	getline(cin, s);
	int index = s.find('b');
	s.erase(index,1);
	cout << s << endl;
	*/
	system("pause");
}


