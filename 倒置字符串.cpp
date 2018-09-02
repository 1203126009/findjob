
//https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&tqId=29867&tPage=2&rp=2&ru=/ta/2017test&qru=/ta/2017test/question-ranking
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    vector<string> S;
    while(cin>>s){
        S.push_back(s);
    }
     vector<string>::iterator iter;
     for(iter=S.end()-1;iter>S.begin();iter--)
              cout<<*iter<<' ';
    cout<<*(S.begin())<<endl;
    return 0;
}