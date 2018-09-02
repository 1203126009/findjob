//http://exercise.acmcoder.com/online/online_judge_ques?ques_id=4396&konwledgeId=41
#include <stdio.h>
#define maxn 100
using namespace std;//概率dp，定义状态前i个题目对j个的概率，递推求解
int n,a[maxn];
double dp[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=dp[i-1][0]*(100.0-a[i])/100;
		for(int j=1;j<=i;j++)
			dp[i][j]=dp[i-1][j]*(100.0-a[i])/100+dp[i-1][j-1]*1.0*a[i]/100;
	}
	int low=ceil(n*0.6);
	double ans=0;
	for(int i=low;i<=n;i++)
		ans+=dp[n][i];
	printf("%.5f\n",ans);
	//system("pause");
	return 0;
}
