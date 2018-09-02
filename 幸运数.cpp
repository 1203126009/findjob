//https://www.nowcoder.com/practice/4d1afe11171c44a385287e29092cdb3f?tpId=85&tqId=29881&tPage=3&rp=3&ru=/ta/2017test&qru=/ta/2017test/question-ranking
#include<iostream>
#include<vector>
using namespace std;
long f_sum(long n){
   long he=0;
   while(n){
      he+=n%10;
      n=n/10;
   }
   return he;
}
long g_sum(long n){
   long he=0;
   while(n>0){
      he++;
      n=n&(n-1);
   }
   return he;
}
  int main()
{
   int n;   
      while(   cin>>n ){
          
  int num[100001]={0};
  for(int i=1;i<=100000;i++)
  {
    if(f_sum(i)==g_sum(i))
      num[i]=num[i-1]+1;
    else
      num[i]=num[i-1];
  }
    cout<<num[n]<<endl;
  }
  return 0;
}