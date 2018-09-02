//https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&tPage=3&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == nullptr)
            return nullptr;
        TreeLinkNode* pNext = nullptr;
         
        if (pNode->right != nullptr)
        {
            TreeLinkNode* pr = pNode->right;
            while(pr->left != nullptr)
                pr = pr->left;
             
            pNext = pr;
        }
        else if(pNode->next!=nullptr)
        {
            TreeLinkNode* pc = pNode;
            TreeLinkNode* pp = pNode->next;
            while(pp != nullptr&&pc == pp->right)
            {
                pc = pp;
                pp = pp->next;
            }
            pNext = pp;
        }
        return pNext;
         
    }
};