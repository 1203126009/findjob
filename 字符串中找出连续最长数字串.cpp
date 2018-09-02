
//https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=85&tqId=29864&tPage=2&rp=2&ru=/ta/2017test&qru=/ta/2017test/question-ranking
#include<bits/stdc++.h>
using namespace std;
string remove_surplus_spaces(string &src){//方法1
	src.erase(0, src.find_first_not_of('*'));
	src.erase(src.find_last_not_of('*') + 1);
	//src.erase(src.find_last_not_of("*") + 1, src.size() - src.find_last_not_of("*") -1);
	string result = "";
	for (int i = 0; src[i] != '\0'; i++){
		if (src[i] != '*'){
			result.append(1, src[i]);
		}
		else{
			if (src[i + 1] != '*')
				result.append(1, src[i]);
		}
	}
	return result;
}
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (!(s[i] >= '1'&&s[i] <= '9'))
			s[i] ='*';
	}
	string s1 = remove_surplus_spaces(s);
	vector<string> str;
	string tempt = "";
	for (int i = 0; i < s1.size(); i++){
		if (s1[i] != '*'){
			tempt.append(1, s1[i]);
		}
		else{
			str.push_back(tempt);
			tempt = "";
		}
		if (i == s1.size() - 1) str.push_back(tempt);
	}
	//数字字符串存到str中
	int maxlen = 0;
	for (int i = 0; i < str.size(); i++){
		if (str[i].size()>maxlen)
			maxlen = str[i].size();
	}
	for (int i = 0; i < str.size(); i++){
		if (str[i].size() == maxlen)
			cout << str[i] << endl;
	
	}
	//system("pause");
}


