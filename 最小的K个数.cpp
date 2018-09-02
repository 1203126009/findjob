//https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        sort(input.begin(),input.end());
        int length = input.size();
        if(k>length)
            return result;
        for(int i=0;i<k;i++){
            result.push_back(input[i]);
        }
        return result;
    }
};
class Solution2 {
public:
     
    vector<int> GetLeastNumbers_Solution(vector<int> input,int k)
    {
        int length=input.size();
        int end=length-1;
        int result=0;
        int flag=k-1;
        int start=0;
        vector<int> result_numbers;
        if(input.empty()||k<=0||k>length)
            return result_numbers;
        if(length==k)
            return input;
        result=Partition(input,start,end);
        while(result!=flag)
        {
            if (result>flag)
            {
                end=result-1;
                result=Partition(input,start,end);
            }
            else
            {
                start=result+1;
                result=Partition(input,start,end);
            }
                
        }
        for(int i=0;i<=result;i++)
            result_numbers.push_back(input[i]);
        
        return result_numbers;
    }
     
    int Partition(vector<int> &numbers,int start,int end)
    {
 
        int low=start;
        int high=end;
        int key=numbers[low];
        while(low<high)
        {
            while(low<high&&key<numbers[high])
                high--;
            numbers[low]=numbers[high];
            while(low<high&&key>=numbers[low])
                low++;
            numbers[high]=numbers[low];
        }
        numbers[low]=key;
        return low;
    }
 
};
class Solution3 {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> result;
        int len = input.size();
        if(input.empty() || k<=0 || len < k) return result;
         
        multiset<int, greater<int> > leastNumbers; // 从大到小排序
        multiset<int, greater<int> >::iterator iterGreater; // 定义迭代器
         
        vector<int>::iterator iter = input.begin();
        for(; iter != input.end(); ++iter)
        {
            // 将前k个数直接插入进multiset中，注意是小于K
            if(leastNumbers.size() < k)
            {
                leastNumbers.insert(*iter);
            }
            else
            {
                // 因为设置的从大到小排序，故multiset中第一个位置的元素即为最大值
                iterGreater = leastNumbers.begin();
                 
                // 如果input中当前元素比multiset中最大元素小，则替换；即保持multiset中这k个元素是最小的。
                if(*iter < *(leastNumbers.begin()))
                {
                    // 替换掉当前最大值
                    leastNumbers.erase(iterGreater); 
                    leastNumbers.insert(*iter);
                }
            }
        }
         
        for(iterGreater = leastNumbers.begin();iterGreater!=leastNumbers.end();++iterGreater)
        {
            result.push_back(*iterGreater); // 将multiset中这k个元素输出
        }
         
        return result;
    }
};

