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
//����ʵ�ֶ�λ��������
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
string charToString(char s){//char תΪstring
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
    for (int i = 0; i <s.size(); i++)//��ÿһ���ַŵ�����������
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*')
            A[j++] = i;//����A��¼ÿ������λ��,һ��j��
    }
        S.push_back(s.substr(0, A[0] ));
        S.push_back(charToString(s[A[0]]));//Ҳ����ͨ��substrʵ��
        for (int i = 0; i < j - 1; i++)
        {
            S.push_back(s.substr(A[i]+1, A[i + 1] - A[i] - 1));
            S.push_back(charToString(s[A[i+1]]));
        }
        S.push_back(s.substr(A[j-1]+1, s.size()-A[j-1] -1));

    int ans = stoi(*(S.begin()));
     vector <string>::iterator iter2;
     for (iter2 = S.begin() + 1; iter2 !=S.end(); iter2=iter2+2)//������iter2 !=S.end()������S.end()-1.��ʱ�����
     {

         if (*(iter2) == "+")
            ans =  ans+ stoi(*(iter2 + 1));//stoi������string תint
        if (*(iter2 ) == "-")
             ans= ans-stoi(*(iter2 + 1));
         if((*(iter2 ) == "*"))
             ans=  ans* stoi(*(iter2 + 1));
    }
     cout << ans<< endl;
        //system("pause");
    return 0;
}
