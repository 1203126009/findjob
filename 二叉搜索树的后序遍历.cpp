
//https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if(len == 0)
            return false;
        int *seq=new int[len];
        for(int i=0;i<len;i++)
            seq[i]=sequence[i];
        return IsBST(seq,len);//修改接口和剑指offer书上一样
        delete[]seq;
    }
    bool IsBST(int *s,int len){
        //if(!s || len == 0)
        //    return false;
        int root = s[len-1];
        int i=0;
        for(;i<len-1;++i){
            if(s[i] > root)
                break;
        }
        for(int j=i;j<len-1;++j){
            if(s[j] < root)
                return false;
        }
        bool left = true;bool right = true;
        if(i > 0)
            left = IsBST(s,i);
        if(len-i-1 > 0)
            right = IsBST(s+i,len-i-1);
        return (left && right);
    }
};