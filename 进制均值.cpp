//https://www.nowcoder.com/practice/215881ffac304a52812eff45aea8330d?tpId=85&tqId=29880&tPage=3&rp=3&ru=/ta/2017test&qru=/ta/2017test/question-ranking
#include<iostream>
using namespace std;
int gcd(int n, int m){
	int temp;//n放大数
	if (n < m){
		temp = n;
		n = m;
		m = temp;
	}
	if (n%m == 0) return m;
	else 
        return gcd(m,n%m);
}
int res(int n,int i){//n用i进制表示
	int a[1000] = { 0 };
	int sum = 0;
	while (n){
		sum += n%i;
		n = n / i;
	}
	return sum;
}
int main(){
	int n;
	while (cin >> n){
		int sum1 = 0;
        if (n == 1 || n == 2)
				cout << 1 << '/' << 1 << endl;
		else
        {
			for (int i = 2; i <= n - 1; i++){

				int temp = res(n, i);
				sum1 += temp;
			}
			int sum2 = n - 2;
			int g = gcd(sum1, sum2);
			cout << sum1 / g << '/' << sum2 / g << endl;
			
		}
	}
	//system("pause");
	return 0;
}