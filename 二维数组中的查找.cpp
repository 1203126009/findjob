//https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		 bool found = false;
		if (array.size() != 0)
		{
			int row = 0;
			int col = array[0].size() - 1;//获取列数
			//array.size()为行数
			while (row < array.size() && col >= 0)
			{
				if (array[row][col] == target)
					return true;
				else if (array[row][col] > target)
					--col;
				else
					++row;
			}

		}
		return false;

	}
};

/* int main(){
	vector<vector<int>> test;
	vector<int> v;
	int temp, n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		v.clear(); //每次记得clear:)
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			v.push_back(temp);
		}
		test.push_back(v);
	}
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << test[i][j] << " ";
		}
		cout << endl;
	}
	Solution A;
	bool p = A.Find(7,test);
	cout << p << endl;
	system("pause");
	return 0;
	
} */