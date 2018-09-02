//https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&tPage=2&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int len=str.size();
        int num[256]={0};
        for(int i=0;i<len;i++){
            num[str[i]]++;
        }
        for(int i=0;i<len;i++)
            {
            if(num[str[i]]==1)
                return i ;
            }
    }
};