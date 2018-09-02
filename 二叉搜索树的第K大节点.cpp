//https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&tqId=11215&tPage=4&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
??//中序遍历的结果就是有序序列，第K个元素就是vec[K-1]存储的节点指针；
????TreeNode* KthNode(TreeNode* pRoot, int k)
????{
????????if(pRoot==NULL||k<=0) return NULL; 
????????vector<TreeNode*> vec;
????????Inorder(pRoot,vec);
????????if(k>vec.size())
????????????return NULL;
????????return vec[k-1];
????}
????//中序遍历，将节点依次压入vector中
????void Inorder(TreeNode* pRoot,vector<TreeNode*>& vec)
????{
????????if(pRoot==NULL) return;
????????Inorder(pRoot->left,vec);
????????vec.push_back(pRoot);
????????Inorder(pRoot->right,vec);
????}? 
};
