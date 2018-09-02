
//https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&tPage=3&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) 
    {
        vector<int> tempt;
        vector<vector<int> > res;
        if(sum < 3)
        return res;

    int small = 1; 
    int big = 2;
    int middle = (1 + sum) / 2;
    int curSum = small + big;

    while(small < middle)
    {
        if(curSum == sum)
		{
            for(int i = small; i <= big; ++ i)
                tempt.push_back(i);
            res.push_back(tempt);
            tempt.clear();
        }
            

        while(curSum > sum && small < middle)
        {
            curSum -= small;
            small ++;

            if(curSum == sum)
           {
              for(int i = small; i <= big; ++ i)
                tempt.push_back(i);
                 res.push_back(tempt);
                 tempt.clear();   
           }
        }

        big ++;
        curSum += big;
    }
        return res;  
    }
};