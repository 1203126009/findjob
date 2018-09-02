//https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    int StrToInt(string str) {
        int n = str.size(), s ;
        if(!n) return 0;
        int res = 0;
        if(str[0] == '+') s = 1;
        if(str[0] == '-') s = -1;
        for(int i = (str[0] ==  '-' || str[0] == '+') ? 1 : 0; i < n; ++i){
            if(!('0' <= str[i] && str[i] <= '9')) return 0;
            res=res*10+str[i]-'0';
        } 
        return res * s;
    }
};
