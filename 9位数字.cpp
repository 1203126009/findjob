//1~9��9�����֣�ÿ������ֻ�ܳ���һ�Σ�Ҫ������һ��9λ��������
//���һλ�ܱ�1������ǰ��λ�ܱ�2������ǰ��λ�ܱ�3����������
//�Դ����ƣ�ǰ9λ�ܱ�9����
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