#include<iostream>  
using namespace std;
#define MAXSIZE 10000  /* 用于要排序数组个数最大值，可根据需要修改 */
void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; k++)  /*对1...m与m+1...n中等长的数组比较大小，并且保存较小元素*/
	{
		if (SR[i]<SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= m)  /*将SR[1...m]中多余中的部分添加到TR中*/
	{
		for (l = 0; l <= m - i; l++)
			TR[k + l] = SR[i + l];
	}
	if (j <= n)    /*将SR[m+1...n]中多余中的部分添加到TR中*/
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];
	}
}
/* 递归法 */
/* 将SR[s..t]归并排序为TR1[s..t] */
void MSort(int SR[], int TR1[], int s, int t)
{
	int m = 0;
	int TR2[MAXSIZE + 1] = { 0 };
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		m = (s + t) / 2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);
	}
}
void MergeSort(int a[],int n)
{
	MSort(a, a, 0, n-1);
}
int main()
{
	int n;
	cin >> n;
	int a[1000] = { 0 };
	for (int j = 0; j<n; j++)
		cin >> a[j];//10 2 4 76 7 3 6 32 35 99 100
	MergeSort(a, n);
	for (int i = 0; i<n - 1; i++)
		cout << a[i] << " ";
	cout << a[n - 1] << endl;
	system("pause");
}
//#include<iostream>  using namespace std;