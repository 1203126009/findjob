//https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 2) return number;
        int fib1 = 1, fib2 = 2;
        int res = 0;
        for (int i = 3; i <= number; i++) {
            res = fib1 + fib2;
            fib1 = fib2;
            fib2 = res;
        }
        return res;
    }
        
};