//https://www.nowcoder.com/questionTerminal/5f2186b48691435388ceccc1269e212a

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int len=s.size();
    int sum=s[0]-'0';
    for(int i=1;i<=len-2;i+2){
        if(s[i]=='+')
            sum=sum+(s[i+1]-'0');

        if(s[i]=='-')
            sum=sum-(s[i+1]-'0');
        if(s[i]=='*')
            sum=sum*(s[i+1]-'0');
    }
    cout<<sum<<endl;
    return 0;
}


/**/
//可以实现多位数的运算
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
string charToString(char s){//char 转为string
    stringstream ss;
    string str;
    ss << s;
    ss >> str;
    return str;
}
int main(){
    string s;
    vector <string> S;
    cin >> s;
    int A[1000],j=0;
    for (int i = 0; i <s.size(); i++)//把每一部分放到迭代器里面
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*')
            A[j++] = i;//数组A记录每个符号位置,一共j个
    }
        S.push_back(s.substr(0, A[0] ));
        S.push_back(charToString(s[A[0]]));//也可以通过substr实现
        for (int i = 0; i < j - 1; i++)
        {
            S.push_back(s.substr(A[i]+1, A[i + 1] - A[i] - 1));
            S.push_back(charToString(s[A[i+1]]));
        }
        S.push_back(s.substr(A[j-1]+1, s.size()-A[j-1] -1));

    int ans = stoi(*(S.begin()));
     vector <string>::iterator iter2;
     for (iter2 = S.begin() + 1; iter2 !=S.end(); iter2=iter2+2)//必须是iter2 !=S.end()，不能S.end()-1.这时溢出了
     {

         if (*(iter2) == "+")
            ans =  ans+ stoi(*(iter2 + 1));//stoi函数，string 转int
        if (*(iter2 ) == "-")
             ans= ans-stoi(*(iter2 + 1));
         if((*(iter2 ) == "*"))
             ans=  ans* stoi(*(iter2 + 1));
    }
     cout << ans<< endl;
        //system("pause");
    return 0;
}
