//https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution
{
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
    {
        return reConstructCore(pre,vin);
    }
    TreeNode* reConstructCore(const vector<int>& pre,const vector<int>& vin)
    {
        if(pre.empty())
            return NULL;
        int nodeVal = pre[0];                              //���������еĵ�һ�������������ĸ��ڵ�
        TreeNode* treePtr = new TreeNode(nodeVal);
        auto iter = find(vin.begin(),vin.end(),nodeVal);   //Ȼ���������������ҵ����ڵ��λ�ã����ڵ����������������ұ���������
        int leftNum = iter - vin.begin();
 
        treePtr->left = reConstructCore(vector<int>(pre.begin()+1,pre.begin()+1+leftNum),
                                            vector<int>(vin.begin(),vin.begin()+leftNum));
        treePtr->right= reConstructCore(vector<int>(pre.begin()+1+leftNum,pre.end()),
                                            vector<int>(vin.begin()+leftNum+1,vin.end()));
        return treePtr;
    }
};