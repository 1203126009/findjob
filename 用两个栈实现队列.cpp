//https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution
{
public:
   void push(int node) {
            stack1.push(node);
    }
 
    int pop() {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
            stack2.push(stack1.top());
            stack1.pop();
            }
        }
        int t=stack2.top();
        stack2.pop();
        return t;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};