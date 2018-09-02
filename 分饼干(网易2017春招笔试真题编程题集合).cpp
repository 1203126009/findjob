//https://www.nowcoder.com/profile/4108707/codeBookDetail?submissionId=10540494
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
    string s;
    int n;
    long long n1[10001], n2[10001];
    cin >> s >> n;
    long long ret = 0;
    n1[0] = 1;
    for (int i = 0; i < s.size(); i++){
        memset(n2, 0, sizeof(n2));//将n2全部赋值0
        for (int j = 0; j < n; j++){
            for (int k = 0; k < 10; k++){
                if (isdigit(s[i]) && s[i] - '0' != k) continue;//isdigit(s[i]判断是否是数字
                n2[((j * 10) + k) % n] += n1[j];
            }
        }
        memcpy(n1, n2, sizeof(n1));
        /*函数原型
        void *memcpy(void*dest, const void *src, size_t n);
        功能
            由src指向地址为起始地址的连续n个字节的数据复制到以destin指向地址为起始地址的空间内。
    */
    }
    cout << n1[0] << endl;
    //system("pasue");
    return 0;
}