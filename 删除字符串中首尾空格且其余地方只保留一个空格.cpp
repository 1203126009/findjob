//删除字符串中所有前导空格和所有后导空格，单词之间最多只留一个空格
#include<iostream>
#include<string>
using namespace std;
/*
erase函数的原型如下：
（1）string& erase ( size_t pos = 0, size_t n = npos );
（2）iterator erase ( iterator position );
（3）iterator erase ( iterator first, iterator last );
也就是说有三种用法：
（1）erase(pos,n); 删除从pos开始的n个字符，比如erase(0,1)就是删除第一个字符
（2）erase(position);删除position处的一个字符(position是个string类型的迭代器)
（3）erase(first,last);删除从first到last之间的字符（first和last都是迭代器）
*/
string remove_surplus_spaces( string &src){//方法1
	src.erase(0,src.find_first_not_of('*'));
	src.erase(src.find_last_not_of('*')+1);
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

void deblank(char  *str)
{
	char *p = str;
	//去掉首部空格
	while (*p == '*') {
		p++;
	}
	//去掉中间多余空格
	int j = 0;
	while (*p != '\0')
	{
		str[j++] = *p++;
		while (str[j - 1] == '*'&&*p == '*')
		{
			p++;
		}
	}
	//去掉最后一个可能的空格
	if (str[j - 1] == '*')
		str[j - 1] = '\0';
	else
		str[j] = '\0';
}


int main(){
	string s;
	char s1[100];
	gets(s1);
	getline(cin, s);
	string res2 = remove_surplus_spaces(s);
	deblank(s1);
	cout << s1 << endl;
	cout << res2<< endl;//***123**12***

	system("pause");
	return 0;

}

string resString(string src){//去掉多余分号(前面所有、后面所有、中间只保留一个)
    string result = "";
    int len=src.size();
    int k=0;
    for (int i = 0; i < len; i++)
        if (src[i] != ';') {
           k=i;
           break;
    }
    for(int i =k; i<= len-2; i++){
        if (src[i] != ';'){
            result.append(1,src[i]);
        }
        else{
            if (src[i + 1] != ';')
                result.append(1,src[i]);
        }
    }
    if (src[len - 1] != ';') result.append(1, src[len - 1]);
    return result;
}

