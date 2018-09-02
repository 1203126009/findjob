//https://www.nowcoder.com/questionTerminal/3897c2bcc87943ed98d8e0b9e18c4666
#include<iostream>
using namespace std;
struct A{
    char s;
    int a1;
    int a2;
};
int main(){
    int N,M;
   while(cin>>N>>M){
      int  a[30000]={0};
     A Way[5000];
    for(int i=1;i<=N;i++)
        cin>>a[i];
    for(int i=1;i<=M;i++)
        cin>>Way[i].s>>Way[i].a1>>Way[i].a2;

    for(int i=1;i<=M;i++){
        if(Way[i].s=='Q'){
            int max=0,k1,k2;
           if(Way[i].a1>Way[i].a2){
            k1=Way[i].a2;k2=Way[i].a1;
           }
           else{
            k2=Way[i].a2;k1=Way[i].a1;
           }

          for(int j=k1;j<=k2;j++){
                    if(a[j]>max)  max=a[j];
           }
        cout<<max<<endl;
        }

     else if(Way[i].s=='U'){
            a[Way[i].a1]=Way[i].a2;
          }
    }
   }
  return 0;
}
