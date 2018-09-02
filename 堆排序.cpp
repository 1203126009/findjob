#include<iostream>  
using namespace std;
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void HeapAdjust(int a[], int s, int m)
{
	int temp, j = 0;
	temp = a[s];
	for (j = 2 * s + 1; j<m; j = j * 2 + 1)
	{
		if (j<m && a[j]<a[j + 1])
			++j;
		if (j<m && temp >= a[j])
			break;
		a[s] = a[j];
		s = j;
	}
	a[s] = temp;
}
void HeapSort(int a[], int len)
{
	int i;
	for (i = (len) / 2 - 1; i >= 0; i--)
		HeapAdjust(a, i, len);
	for (i = len - 1; i >= 1; i--)
	{
		swap(&a[0], &a[i]);
		HeapAdjust(a, 0, i - 1);
	}
}
int main()
{
	int n;
	cin >> n;
	int a[1000] = { 0 };
	for (int j = 0; j<n; j++)
		cin >> a[j];//10 2 4 76 7 3 6 32 35 99 100
	HeapSort(a, n);
	for (int i = 0; i<n - 1; i++)
		cout << a[i] << " ";
	cout << a[n - 1] << endl;
	system("pause");
}
//#include<iostream>  using namespace std;