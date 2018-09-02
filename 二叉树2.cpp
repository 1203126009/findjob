//剑指offer中的写法
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int                    val;
	TreeNode*        left;
	TreeNode*        right;
};
TreeNode* CreateTreeNode(int value)//生成节点
{
	TreeNode* pNode = new TreeNode();
	pNode->val = value;
	pNode->left = nullptr;
	pNode->right = nullptr;

	return pNode;
}

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->left = pLeft;
		pParent->right = pRight;
	}
}

void PrintTreeNode(const TreeNode* pNode)//打印节点
{
	if (pNode != nullptr)
	{
		printf("value of this node is: %d\n", pNode->val);

		if (pNode->left != nullptr)
			printf("value of its left child is: %d.\n", pNode->left->val);
		else
			printf("left child is nullptr.\n");

		if (pNode->right != nullptr)
			printf("value of its right child is: %d.\n", pNode->right->val);
		else
			printf("right child is nullptr.\n");
	}
	else
	{
		printf("this node is nullptr.\n");
	}

	printf("\n");
}

void PrintTree(const TreeNode* pRoot)//打印二叉树
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->left != nullptr)
			PrintTree(pRoot->left);

		if (pRoot->right != nullptr)
			PrintTree(pRoot->right);
	}
}
/*
void DestroyTree(TreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		TreeNode* pLeft = pRoot->left;
		TreeNode* pRight = pRoot->right;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}
*/
int main(){


	// 树结构
	//                  8                
	//              /       \          
	//             8         7         
	//           /   \
	//          9     2
	//               / \
	//              4   7
	TreeNode* pNodeA1 = CreateTreeNode(8);
	TreeNode* pNodeA2 = CreateTreeNode(8);
	TreeNode* pNodeA3 = CreateTreeNode(7);
	TreeNode* pNodeA4 = CreateTreeNode(9);
	TreeNode* pNodeA5 = CreateTreeNode(2);
	TreeNode* pNodeA6 = CreateTreeNode(4);
	TreeNode* pNodeA7 = CreateTreeNode(7);

	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);
	
	PrintTree(pNodeA1);
	system("pause");

}

