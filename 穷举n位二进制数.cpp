#include<stdio.h>
#include<string.h>
int N,a[20]={0};
void search(int m)
{
    int i;
    if(m==N)
    {
        for(i=0;i<N;i++)
            printf("%d",a[i]);  
        printf("\n");
    }
    else
    {
        a[m]=0;
        search(m+1);
        a[m]=1;
        search(m+1);
    }
}
int main()
{
     scanf("%d",&N);
     search(0);
     return 0;
}
