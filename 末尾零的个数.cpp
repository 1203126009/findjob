https://www.nowcoder.com/practice/6ffdd7e4197c403e88c6a8aa3e7a332a?tpId=85&tqId=29861&tPage=2&rp=2&ru=/ta/2017test&qru=/ta/2017test/question-ranking
//算多少个5
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(j%5==0)
        {
            count++;
            j=j/5;
        }
    }
    cout<<count<<endl;
    return 0;
}