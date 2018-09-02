https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52?tpId=85&tqId=29862&tPage=2&rp=2&ru=/ta/2017test&qru=/ta/2017test/question-ranking
//考虑负数
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	while (cin>>n>>m)
	{
		int ans[1000];
		bool flag;
		flag = true;//表示正负
		if (n<0)
		{
			flag = false;
			n = -n;
		}
		int k = 0;
		while (n)
		{
			ans[k++] = n%m;
			n /= m;
		}
		if (flag == false)
			printf("-");
		for (int i = k - 1; i >= 0; i--)
		{
			if (ans[i]>9)
				printf("%c", 'A' + ans[i] - 10);
			else
				printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}