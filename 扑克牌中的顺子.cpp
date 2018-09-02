//https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    bool IsContinuous( vector<int> numbers )
    {
       int size=numbers.size();
        if(size<=0)return false;
        sort(numbers.begin(),numbers.end());
        int numof0=0;
        int kong=0;
        for(int i=0;i<size;i++)
        {
            if(numbers[i]==0)numof0++;
              
        }
         for(int i=numof0+1;i<size;i++)
        {
            if(numbers[i]==numbers[i-1])return false;
            else kong+=numbers[i]-numbers[i-1]-1;
        }
        if(numof0>=kong)return true;
        return false;
    }
};