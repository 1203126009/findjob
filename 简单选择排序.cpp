#include<iostream>
using namespace std;
void SelectSort(int a[], int n)
{
	for (int i = 0; i<n - 1; i++)
	{
		int k = i;//记录最小的那个下标的  
		for (int j = i + 1; j<n; j++)
			if (a[j]<a[k])
				k = j;
		if (k != i)
		{
			int t = a[i];
			a[i] = a[k];
			a[k] = t;
		}

	}
}
int main()
{
	int n;
	cin >> n;
	int a[1000] = { 0 };
	for (int j = 0; j<n; j++)
		cin >> a[j];//10 2 4 76 7 3 6 32 35 99 100
	SelectSort(a, n);
	for (int i = 0; i<n - 1; i++)
		cout << a[i] << " ";
	cout << a[n - 1] << endl;
	system("pause");
}