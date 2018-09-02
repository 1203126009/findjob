//https://www.nowcoder.com/practice/635ff765d4af45b5bf8e3756ed415792?tpId=85&tqId=29879&tPage=3&rp=3&ru=/ta/2017test&qru=/ta/2017test/question-ranking
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int a[100000],b[200000];
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<m; i++)
            cin>>b[i];
        for(int i=0; i<n; i++)
            b[m+i]=a[i];
        sort(b,b+m+n);//排序
        int res[100000],j=0;//保存结果的数组
        int num[100000]={0};
        //去重
        for(int i=0; i<m+n; i++)
        {
            if(num[b[i]]==0){
                res[j++]=b[i];
                num[b[i]]++;
            }
               
        }
        for(int i=0; i<j-1; i++)
            cout<<res[i]<<' ';
        cout<<res[j-1]<<endl;
    }
    return 0;
}