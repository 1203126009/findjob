/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > result;
            vector<int> temp;
            if(pRoot == NULL)
                return result;
            queue<TreeNode*> nodes;
            nodes.push(pRoot);
            int nextLevel = 0;
            int toBePrinted = 1;
            while(!nodes.empty()){
                TreeNode* pNode = nodes.front();
                temp.push_back(pNode->val);//  vector<int> temp;//
                if(pNode->left != NULL){
                    nodes.push(pNode->left);
                    ++nextLevel;
                }
                if(pNode->right != NULL){
                    nodes.push(pNode->right);
                    ++nextLevel;
                }
                nodes.pop();
                --toBePrinted;
                if(toBePrinted == 0){
                    result.push_back(temp);//保存结果
                    temp.clear();//清空vector
                    toBePrinted = nextLevel;
                    nextLevel = 0;
                }
            }
            return result;
        }
     
};