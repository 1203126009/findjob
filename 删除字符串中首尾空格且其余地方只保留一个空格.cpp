//ɾ���ַ���������ǰ���ո�����к󵼿ո񣬵���֮�����ֻ��һ���ո�
#include<iostream>
#include<string>
using namespace std;
/*
erase������ԭ�����£�
��1��string& erase ( size_t pos = 0, size_t n = npos );
��2��iterator erase ( iterator position );
��3��iterator erase ( iterator first, iterator last );
Ҳ����˵�������÷���
��1��erase(pos,n); ɾ����pos��ʼ��n���ַ�������erase(0,1)����ɾ����һ���ַ�
��2��erase(position);ɾ��position����һ���ַ�(position�Ǹ�string���͵ĵ�����)
��3��erase(first,last);ɾ����first��last֮����ַ���first��last���ǵ�������
*/
string remove_surplus_spaces( string &src){//����1
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
	//ȥ���ײ��ո�
	while (*p == '*') {
		p++;
	}
	//ȥ���м����ո�
	int j = 0;
	while (*p != '\0')
	{
		str[j++] = *p++;
		while (str[j - 1] == '*'&&*p == '*')
		{
			p++;
		}
	}
	//ȥ�����һ�����ܵĿո�
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

string resString(string src){//ȥ������ֺ�(ǰ�����С��������С��м�ֻ����һ��)
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

