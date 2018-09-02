//https://www.nowcoder.com/practice/a6a656249f404eb498d16b2f8eaa2c60?tpId=85&tqId=29898&tPage=4&rp=4&ru=/ta/2017test&qru=/ta/2017test/question-ranking
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string PrintMaxNumber(vector<int> numbers) {
        int len = numbers.size();
        if(len == 0) return "";
        sort(numbers.begin(), numbers.end(), cmp);
        string res;
        for(int i = 0; i < len; i++){
            res += to_string(numbers[i]);
        }
        return res;
    }
    static bool cmp(int a, int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A >B;
    }
};
int main(){
    int n,tempt;
    while(cin>>n){
        vector<int> numbers;
        Solution solution1;
        numbers.clear();
        for(int i=1;i<=n;i++){
            cin>>tempt;
            numbers.push_back(tempt);  
        }
        string s=solution1.PrintMaxNumber(numbers);
        cout<<s<<endl;
    }

}