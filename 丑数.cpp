//https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution1 {
public:
    int GetUglyNumber_Solution(int index) {
        if (index<=0) return 0;
        if (index==1) return 1;
        vector<int>k(index);k[0]=1;
        int t2=0,t3=0,t5=0;
        for (int i=1;i<index;i++) {
            k[i]=min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if (k[i]==k[t2]*2) t2++;
            if (k[i]==k[t3]*3) t3++;
            if (k[i]==k[t5]*5) t5++;
        }
        return k[index-1];
    }
};
class Solution2 {
public:
    int GetUglyNumber_Solution(int index)
{
    if(index <= 0)
        return 0;
  
    int *pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;
  
    int *pMultiply2 = pUglyNumbers;
    int *pMultiply3 = pUglyNumbers;
    int *pMultiply5 = pUglyNumbers;
  
    while(nextUglyIndex < index)
    {
        int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
        pUglyNumbers[nextUglyIndex] = min;
  
        while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply2;
        while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply3;
        while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply5;
  
        ++nextUglyIndex;
    }
  
    int ugly = pUglyNumbers[nextUglyIndex - 1];
    delete[] pUglyNumbers;
    return ugly;
}
  
int Min(int number1, int number2, int number3)
{
    int min = (number1 < number2) ? number1 : number2;
    min = (min < number3) ? min : number3;
  
    return min;
}
};

