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
		
		
		//只适合有序的去重，去掉重复字母时重复情况，自己添加的//
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
	vector<string> res = solution1. Permutation(s);//之前算法不能去重复
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	system("pause");
} */