//https://www.nowcoder.com/questionTerminal/0d241147265d4f64aacd1e2d3e46abc6
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int a[1000] = { 0 };
    int b[50] = { 0 }, i = 0,n;
    cin >> n;
    while (n--){
        cin >> b[i++];
    }
    vector<int> S;
    for (int j = i - 1; j >= 0; j--)
    {
        if (a[b[j]] == 0){
            S.push_back(b[j]);//存到vector里面
            a[b[j]]++;
        }
    }
        vector<int>::iterator  iter;
        for (iter = S.end() - 1; iter != S.begin(); iter--)
            cout << *iter << ' ';
        cout << *(S.begin()) << endl;
    //system("pause");
    return 0;
}


/*2*/
//不使用vector
#include<iostream>
#include<string>
using namespace std;
int main(){
    int a[10000] = { 0 };
    int b[50] = { 0 }, i = 0,n;
    cin >> n;
    while (n--){
        cin >> b[i++];
    }//结束后i等于之前的n
    int k=0;
    int res[50] = {0};//res存结果，然后逆序输出
    for (int j = i - 1; j >= 0; j--)
    {
        if (a[b[j]] == 0){
            res[k++]=b[j];
            a[b[j]]++;
        }
    }
     for(int j=k-1;j>0;j--)
            cout<<res[j]<<' ';
     cout<<res[0]<<endl;
    //system("pause");
    return 0;
}


