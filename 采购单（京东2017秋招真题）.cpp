//http://exercise.acmcoder.com/online/online_judge_ques?ques_id=3378&konwledgeId=41
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool Compare(int a,int b){
	return a > b;
}
int main(){
	int n, m;
	while (cin >> n >> m){
		int A[1000];
		for (int i = 0; i < n; i++)
			cin >> A[i];
		sort(A, A + n);//给每个排序
		string s[1000];
		for (int i = 0; i < m; i++)
			cin >> s[i];
		sort(s, s + m);
		vector<string> s1;
		for (int i = 0; i < m; i++)
		{
			if (i != 0 && s[i] == s[i - 1]) continue;
			else
				s1.push_back(s[i]);
		}
		int k = s1.size();
		int num[1000] = { 0 };//存放不重复的个数；
		for (int i = 0; i < k; i++){
			string temp = s1[i];
			for (int j = 0; j < m; j++){
				if (s[j] == temp) num[i]++;
			}
		}
		int min = 0, max = 0;
		sort(num, num + k, Compare);
		for (int i = 0; i < k; i++){
			min += num[i] * A[i];
		}
		for (int i = n - 1; i >= n - k; i--){
			max += num[n - 1 - i] * A[i];
		}
		cout << min << ' ' << max << endl;
	}
	system("pause");
	return 0;
}
