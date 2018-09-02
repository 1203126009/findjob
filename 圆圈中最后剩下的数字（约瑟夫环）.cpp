https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=13&tqId=11199&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n==0) return -1;
        int s=0;
        for(int i=2;i<=n;i++){
            s=(s+m)%i;
        }
        return s;
    }
};