//https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> res;
        for(int i = 0; i < array.size(); i++)
        {
            if(array[i] % 2 == 1)
                res.push_back(array[i]);
        }
        for(int i = 0; i < array.size(); i++)
        {
            if(array[i] % 2 == 0)
                res.push_back(array[i]);
        }
        array = res;
         
    }
};