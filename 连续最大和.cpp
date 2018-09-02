//https://www.nowcoder.com/practice/5a304c109a544aef9b583dce23f5f5db?tpId=85&tqId=29858&tPage=2&rp=2&ru=/ta/2017test&qru=/ta/2017test/question-ranking
#include<bits/stdc++.h>
using namespace std;
int FindGreatestSumOfSubArray(vector<int> array)
{
	int cursum = array[0];
	int maxsum = array[0];
	for (int i = 1; i<array.size(); i++){
		cursum += array[i];
		if (cursum<array[i])
			cursum = array[i];
		if (cursum>maxsum)
			maxsum = cursum;
	}
	return maxsum;
}
int main()
{
	int n, tempt;
	while (cin >> n)
	{
		vector<int> array;
			array.clear();
		for (int i = 0; i<n; i++)
		{
			cin >> tempt;
				array.push_back(tempt);
		}
		cout << FindGreatestSumOfSubArray(array) << endl;
	}
	//system("pause");
}
