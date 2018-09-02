#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> res,res1;
		int len = str.size();
		if (len <= 0)
			return res;

		perSub(res, str, 0);
		sort(res.begin(), res.end());
		
		
		//ֻ�ʺ������ȥ�أ�ȥ���ظ���ĸʱ�ظ�������Լ���ӵ�//
		for (int i = 0; i<res.size(); i++){
			if (i != 0 && res[i] == res[i - 1]){
				continue;
			}
			res1.push_back(res[i]);
		}

		return res1;

	}
	void perSub(vector<string> &res, string str, int begin) {
		if (begin < 0 || str.size() == 0)
			return;

		if (begin == str.size() - 1) {
			res.push_back(str);
		}
		else {
			for (int i = begin; i<str.size(); i++) {
				if (i != begin && str[i] == str[begin])
					continue;
				swap(str[begin], str[i]);
				perSub(res, str, begin + 1);
				swap(str[begin], str[i]);
			}
		}
	}
};
/* int main(){
	Solution solution1;
	string s;
	cin >> s;
	vector<string> res = solution1. Permutation(s);//֮ǰ�㷨����ȥ�ظ�
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	system("pause");
} */