//http://exercise.acmcoder.com/online/online_judge_ques?ques_id=4400&konwledgeId=41
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int i = n, count = 0;
	for (int j = 0; j < i; j++){
		if (s[j] >= '0'&&s[j] <= '9' && s[j] != 'X'&&s[j] != '#') {
			int a = s[j] - '0';
			int a1 = j - a;
			int a2 = j + a;
			if (a1 < 0) a1 = 0;
			if (a2 > i - 1) a2 = i - 1;
			for (int k = a1; k <= a2; k++){
				if (s[k] == 'X') s[k]='P',count++;
			}
		}
	
	}
	cout<<count << endl;
	system("pause");
	return 0;

}