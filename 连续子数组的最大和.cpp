//https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking//
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
         
        int cursum=array[0];
        int maxsum=array[0];
        for(int i=1;i<array.size();i++){
            cursum+=array[i];
            if(cursum<array[i])
                cursum=array[i];
            if(cursum>maxsum)
                maxsum=cursum;           
        }
    return maxsum;
    }
};