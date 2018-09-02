//https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
    /*二分查找 找到第一个K 和 最后一个K 二者位置相减*/
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        int number = 0;
        int first = GetFirstIndex(data,k,0,data.size()-1);
        int last = GetLastIndex(data,k,0,data.size()-1);
        if(first>-1 && last>-1)
            number = last - first +1;
        return number;
         
    }
    int GetFirstIndex(vector<int> &data,int k,int start,int end){
        if(start > end)
            return -1;
        int mid = start+(end-start)/2;
        if(data[mid] == k){
            if((mid == start) || (data[mid-1] != k))
                return mid;
            else
                end = mid-1;
        }
        else{
            if(data[mid] > k)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return GetFirstIndex(data,k,start,end);
    }
    int GetLastIndex(vector<int> &data,int k,int start,int end){
        if(start > end)
            return -1;
        int mid = start+(end-start)/2;
        if(data[mid]==k){
            if((mid == end) || (data[mid+1] != k))
                return mid;
            else
                start = mid +1;
        }
        else{
            if(data[mid]>k)
                end = mid-1;
            else
                start = mid+1;
        }
        return GetLastIndex(data,k,start,end);
    }
};