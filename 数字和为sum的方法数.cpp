https://www.nowcoder.com/practice/7f24eb7266ce4b0792ce8721d6259800?tpId=85&tqId=29863&tPage=2&rp=2&ru=/ta/2017test&qru=/ta/2017test/question-ranking
#include<bits/stdc++.h>
using namespace std;
long long dp[1002][1002];
int main()
{
    int n;
    int A[1002];
    int sum;
    while (scanf("%d %d", &n, &sum) != EOF)
    {
        for (int i = 0; i<n; i++)
            scanf("%d", A + i);
        for (int i = 0; i <= sum; i++)
            dp[0][i] = 0;
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= A[i-1])
                    dp[i][j] += dp[i - 1][j - A[i-1]];
            }
        }
        printf("%lld\n", dp[n][sum]);
    }
    return 0;
}