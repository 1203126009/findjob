
//https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
        vector<vector<int>> vec;
        vector<int> med;//
        if(pRoot==NULL) return vec;
        stack<TreeNode*> level[2];
        int current=0;
        int next=1;
        level[0].push(pRoot);
        while(!level[0].empty()||!level[1].empty())
            {
            TreeNode* p=level[current].top();
            level[current].pop();
            med.push_back(p->val);
            if(current==0)
                {
                if(p->left)
                    level[next].push(p->left);
                if(p->right)
                    level[next].push(p->right);
            }
            else
                {
                if(p->right)
                    level[next].push(p->right);
                if(p->left)
                    level[next].push(p->left);
            }
            if(level[current].empty())
                {
                vec.push_back(med);//
                med.clear();//
                current=1-current;
                next=1-next;
            }
        }
        return vec;
    }
};