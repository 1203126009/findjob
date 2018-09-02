//https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() || popV.empty() || pushV.size()!=popV.size())
            return false;
        stack<int> s;
        int j=0;
        for(int i=0;i<pushV.size();++i){
            s.push(pushV[i]);
            while(!s.empty()&&s.top()==popV[j]){
                s.pop();
                ++j;
            }
        }
        if(s.empty())
            return true;
        return false;
    }
};