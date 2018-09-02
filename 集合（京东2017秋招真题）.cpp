/*
http://exercise.acmcoder.com/online/online_judge_ques?ques_id=3374&konwledgeId=41
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int a[10000],b[20000];
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<m; i++)
            cin>>b[i];
        for(int i=0; i<n; i++)
            b[m+i]=a[i];
        sort(b,b+m+n);//排序
        int res[10000],j=0;//保存结果的数组
        //去重
        for(int i=0; i<m+n; i++)
        {
            if(i!=0&&b[i]==b[i-1]) continue;
            else
                res[j++]=b[i];
        }
        for(int i=0; i<j-1; i++)
            cout<<res[i]<<' ';
        cout<<res[j-1]<<endl;
    }
    return 0;
}
