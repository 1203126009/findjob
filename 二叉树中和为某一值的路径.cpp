//https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
     vector<vector<int>> res;
     vector<int> path;
    void find(TreeNode* root,  int sum)
    {
        if (root == NULL)return;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == root->val)
            res.push_back(path);
        else
        {
            if (root->left)
                find(root->left, sum - root->val);
            if (root->right)
                find(root->right, sum - root->val);
        }
        path.pop_back();
    }
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        find(root, expectNumber);
        return res;
    }
};

class Solution2 {
	vector<int> path;
	vector<vector<int> > res;
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		FindPath1(root, expectNumber);
		return res;
	}
	//更改接口
	void FindPath1(TreeNode* pRoot, int expectedSum)
	{
		if (pRoot == nullptr)
			return;

		//std::vector<int> path;
		int currentSum = 0;
		FindPath(pRoot, expectedSum, path, currentSum);
	}

	void FindPath(TreeNode*   pRoot,int  expectedSum,std::vector<int>& path,int& currentSum)
	{
		currentSum += pRoot->val;
		path.push_back(pRoot->val);

		// 如果是叶结点，并且路径上结点的和等于输入的值
		// 打印出这条路径
		bool isLeaf = pRoot->left == nullptr && pRoot->right == nullptr;
		if (currentSum == expectedSum && isLeaf)
		{
			res.push_back(path);
			/*
			
			printf("A path is found: ");
			std::vector<int>::iterator iter = path.begin();
			for (; iter != path.end(); ++iter)
				printf("%d\t", *iter);
			printf("\n");
			*/
		}

		// 如果不是叶结点，则遍历它的子结点
		if (pRoot->left != nullptr)
			FindPath(pRoot->left, expectedSum, path, currentSum);
		if (pRoot->right != nullptr)
			FindPath(pRoot->right, expectedSum, path, currentSum);

		// 在返回到父结点之前，在路径上删除当前结点，
		// 并在currentSum中减去当前结点的值
		currentSum -= pRoot->val;
		path.pop_back();
	}

};
