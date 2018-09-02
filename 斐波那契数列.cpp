//https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    int Fibonacci(int n) {
if(n==0||n==1)
    return n;
    int a=0,b=1;
    int sum=0;
    for(int i=2;i<=n;i++){
        sum=a+b;
        a=b;
        b=sum;
        
    }
    return sum;    
        
    }
};