//http://exercise.acmcoder.com/online/online_judge_ques?ques_id=3383&konwledgeId=42

#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string a, b, c;
	while(cin >> a >> b >> c)
	{
		string ans("YES");
		a += b;
		a += c;
		for(int i = 0; i < 4; i++)
		{
			if(a[i] != a[8-i])
				ans = "NO";
		}
		cout << ans << endl;
	}
	return 0;
}