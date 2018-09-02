//https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    string LeftRotateString(string &str, int n)
    {
        int nLength = str.size();
        if(!str.empty() && n >= 0&&n <= nLength)
        {
                int pFirstStart = 0;
                int pFirstEnd = n - 1;
                int pSecondStart = n;
                int pSecondEnd = nLength - 1;
 
                // 翻转字符串的前面n个字符
                reverse(str, pFirstStart, pFirstEnd);
                // 翻转字符串的后面部分
                reverse(str, pSecondStart, pSecondEnd);
                // 翻转整个字符串
                reverse(str, pFirstStart, pSecondEnd);
        }
        return str;
 
    }
    void reverse(string &str, int begin, int end)//翻转字符串中的一段
    {
        while(begin < end)
        {
            char tmp = str[begin];
            str[begin] = str[end];
            str[end] = tmp;
            begin++;
            end--;
        }
    }
};