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
        memset(n2, 0, sizeof(n2));//��n2ȫ����ֵ0
        for (int j = 0; j < n; j++){
            for (int k = 0; k < 10; k++){
                if (isdigit(s[i]) && s[i] - '0' != k) continue;//isdigit(s[i]�ж��Ƿ�������
                n2[((j * 10) + k) % n] += n1[j];
            }
        }
        memcpy(n1, n2, sizeof(n1));
        /*����ԭ��
        void *memcpy(void*dest, const void *src, size_t n);
        ����
            ��srcָ���ַΪ��ʼ��ַ������n���ֽڵ����ݸ��Ƶ���destinָ���ַΪ��ʼ��ַ�Ŀռ��ڡ�
    */
    }
    cout << n1[0] << endl;
    //system("pasue");
    return 0;
}