//http://exercise.acmcoder.com/online/online_judge_ques?ques_id=3861&konwledgeId=42
#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	int L, R;
	cin >> L >> R;
	double theta =1.0* L / R;
	double a = R * cos(theta);
	double b = R * sin(theta);
	cout << fixed << setprecision(3) << a << ' ' << fixed << setprecision(3) << -1*b << endl;
	cout << fixed << setprecision(3) << a << ' ' << fixed << setprecision(3) << b << endl;
	system("pause");
	return 0;
}