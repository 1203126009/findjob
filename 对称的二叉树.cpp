//https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&tqId=11211&tPage=3&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymmetrical(pRoot,pRoot);
    }
    bool isSymmetrical(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if(pRoot1==nullptr&&pRoot2==nullptr)
            return true;
        if(pRoot1==nullptr||pRoot2==nullptr)
            return false;
        if(pRoot1->val!=pRoot2->val)
            return false;
        return isSymmetrical(pRoot1->left,pRoot2->right)&& isSymmetrical(pRoot1->right,pRoot2->left);
    }
 
};