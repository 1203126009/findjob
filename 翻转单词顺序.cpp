//https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    string ReverseSentence(string str) 
    {
        int len = str.length();
        if(len == 0) return "";
        int begin=0;
        int end=0;
        Reverse(str,0,len-1);
        begin=end=0;
        while(str[begin]!='\0')
            {
            if(str[begin]==' ')
                {
                begin++;
                end++;
            }
            else if(str[end]==' '||str[end]=='\0')
                {
                Reverse(str,begin,--end);
                begin=++end;
            }
            else end++;
        }
        return str;
}
    void Reverse(string &str,int begin,int end)
    {
        while(begin < end)
        {
            swap(str[begin++],str[end--]);
        }
    }
};