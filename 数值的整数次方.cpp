//https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    double Power(double base, int exponent) {
    double result = 1.0;
       int i=0;
        if(exponent==0)result=1;
        else if(exponent>0){
            while(i<exponent)
                {
                result*=base;
                i++;
            }
        }
        else{
            while(i<(-exponent))
                {
                result=result/base;
                i++;
            }
        }
        return result;
 
    }
};

class Solution2 {
public:
    double Power(double base, int exponent) {
        
        return pow(base,exponent);
    
    }
};