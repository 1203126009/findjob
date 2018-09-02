//https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1
class Solution {
public:
    int rectCover(int number) {
        if (number==0)return 0;
        if (number==1)return 1;
        if (number==2)return 2;
        int f1 = 1;
        int f2 = 2;
        int fn;
        for (int i = 3; i<=number; i++){
            fn = f1+f2;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
};