//https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
   int numof1(int n){
        int num=0;
        while(n){
            if(n%10==1)
                num++;
            n/=10;
        }
        return num;
    }
    int NumberOf1Between1AndN_Solution(int n){
        int num=0;
        for(int i=1;i<=n;i++){
            num+=numof1(i);
        }
    return num;
    }
};