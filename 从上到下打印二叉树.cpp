//https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;//队列
        vector<int> v;
         if(root == NULL) return v;
        q.push(root);//插入一个新元素在队尾
        while(!q.empty())
        {
		    root = q.front();//取队列首部元素
             q.pop();//移除队首元素
             v.push_back(root->val);
             if(root->left)
                 q.push(root->left);
             if(root->right)
                 q.push(root->right);
        }
        return v;
    }
};