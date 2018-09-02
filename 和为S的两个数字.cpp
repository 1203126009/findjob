//https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
          vector<int> result;
        int length = array.size();
        int start = 0;
        int end = length - 1;
        while (start < end)
        {
            if (array[start] + array[end] == sum)
            {
                result.push_back(array[start]);
                result.push_back(array[end]);
                break;
            }
            else if (array[start] + array[end] < sum)
                start++;
            else
                end--;
        }
        return result;
    }
};