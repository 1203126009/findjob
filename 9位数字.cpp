//1~9的9个数字，每个数字只能出现一次，要求这样一个9位的整数：
//其第一位能被1整除，前两位能被2整除，前三位能被3整除。。。
//以此类推，前9位能被9整除
#include "iostream"   
#include "vector"  
using namespace std;

bool used[10] = { false };
vector<long long> vec;
void NumOf9Bits(int k, long long num)
{
	if (k && num%k != 0)
		return;
	if (9 == k)
	{
		vec.push_back(num);
		return;
	}

	for (int i = 1; i <= 9; i++)
		if (!used[i])
		{
			used[i] = true;
			NumOf9Bits(k + 1, num * 10 + i);
			used[i] = false;
		}

}

int main()
{
	NumOf9Bits(0, 0);
	for (int i = 0; i < vec.size(); i++)
		printf("%lld\n", vec[i]); //381654729   
	system("pause");
	return 0;
}