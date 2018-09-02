//n皇后问题
#include<stdio.h>
#include<math.h>
int place(int k,int x[])
{
    int i;
    for(i=1;i<k;i++)
        if(fabs(k-i)==fabs(x[i]-x[k])||x[i]==x[k]) return 0;
    return 1;
}
void backtrack(int t,int n,int x[],int *sum)
{
    int i;
    if(t>n) (*sum)++;
    else
        for(i=1;i<=n;i++)
    {
        x[t]=i;
        if(place(t,x)) backtrack(t+1,n,x,sum);
    }
}
int main()
{
    int i,sum=0,x[100];
    int n;
    scanf("%d",&n);
    for(i=0;i<=n;i++)  x[i]=0;
    backtrack(1,n,x,&sum);
    printf("%d\n",sum);
    return 0;
}
