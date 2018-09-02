
//https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:

int TreeDepth(TreeNode* pRoot)
{
    if(pRoot == nullptr)
        return 0;

    int nLeft = TreeDepth(pRoot->left);
    int nRight = TreeDepth(pRoot->right);

    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

bool IsBalanced_Solution(TreeNode* pRoot)
{
    if(pRoot == nullptr)
        return true;

    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);
    int diff = left - right;
    if(diff > 1 || diff < -1)
        return false;

    return IsBalanced_Solution(pRoot->left) 
        && IsBalanced_Solution(pRoot->right);
}
};