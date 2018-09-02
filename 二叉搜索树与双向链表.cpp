//https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;
           
        convertHelper(pRootOfTree, pre);
           
        TreeNode* res = pRootOfTree;
        while(res ->left)
            res = res ->left;
        return res;
    }
       
    void convertHelper(TreeNode* cur, TreeNode*& pre)
    {
        if(cur == nullptr) return;
           
        convertHelper(cur ->left, pre);
           
        cur ->left = pre;
        if(pre) pre ->right = cur;
        pre = cur;
           
        convertHelper(cur ->right, pre);
    }
};