//https://www.nowcoder.com/practice/cc727473d1e248ccb674eb31bd8683dc?tpId=85&tqId=29865&tPage=2&rp=2&ru=/ta/2017test&qru=/ta/2017test/question-ranking
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	vector<int> vec;
	while (cin >> n){
		vec.push_back(n);
	}
	int len = vec.size();
	int k = vec[len - 1];
	sort(vec.begin(), vec.end() - 2);
	for (int i = 0; i < k - 1; i++)
		cout << vec[i] << " ";
	cout << vec[k - 1] << endl;
	//system("pause");
}