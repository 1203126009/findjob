#include<bits/stdc++.h>
using namespace std;
string  charToString(char *s){//字符串转string
	string res(s);
	return res;
}
vector<string> AllSubstring3(char *str, char *arr)
{
	vector<string> res;
	//穿入的arr的长度为len+1，最后一个位置保存'\0'  
	int i, j;
	unsigned int len = strlen(str);
	strcpy(arr, str);
	for (i = len - 1; i >= 0; i--)
	{
		arr[i + 1] = '\0';
		for (j = i; j >= 0; j--){
			string tempt= charToString(&arr[j]);
			res.push_back(tempt);
		}
			//printf("%s\t", &arr[j]);
		//printf("\n");
	}
	return res;
}
int main(){
	char str[100];
	vector<string> res;
	vector<string> res1;
	res=AllSubstring3("bbc", str);
	sort(res.begin(), res.end());//按字典序输出
	//去重复
	for (int i = 0; i<res.size(); i++){
		if (i != 0 && res[i] == res[i - 1]){
			continue;
		}
		res1.push_back(res[i]);
	}
	for (int i = 0; i < res1.size(); i++)
		cout << res1[i]<<endl;
	system("pause");
		

}