//https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
////如果题目要求得出最大的数字，可以将比较器转换成从大到小排序即可
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        if(len == 0) return "";
        sort(numbers.begin(), numbers.end(), cmp);
        string res;
        for(int i = 0; i < len; i++){
            res += to_string(numbers[i]);
        }
        return res;
    }
    static bool cmp(int a, int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }
};