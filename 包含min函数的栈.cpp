//https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1
class Solution {
public:
    void push(int value) {
        if(minData.empty()){
            minData.push(value);
        }
        else{
            if(minData.top()<value)
            minData.push(minData.top());
            else minData.push(value);
        }
        data.push(value);
    }
    void pop() {
        data.pop();
        minData.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return minData.top();
    }
private:
    stack<int> data,minData;
     
};