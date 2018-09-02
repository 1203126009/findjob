#include "string.h"
#include "stdio.h"     
#include<iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
typedef char TElemType;

struct BiTNode  /* 结点结构 */
{
	TElemType data;		/* 结点数据 */
	 BiTNode *lchild, *rchild; /* 左右孩子指针 */
} ;
typedef BiTNode * BiTree;

/* 按前序输入二叉树中结点的值（一个字符） */
/* #表示空树，构造二叉链表表示二叉树T。 */
int index = 0;
char s[1000];

void CreateBiTree(BiTree *T)//根据前序结果创建二叉树
{
	TElemType ch;
	  scanf("%c",&ch); 
   //ch = s[index++];    //index设为全局变量，写法2

	if (ch == '#')
		*T = NULL;
	else
	{
		//*T = (BiTree)malloc(sizeof(BiTNode));
		*T = new BiTNode;
		if (!*T)
			exit(OVERFLOW);
		(*T)->data = ch; /* 生成根结点 */
		CreateBiTree(&(*T)->lchild); /* 构造左子树 */
		CreateBiTree(&(*T)->rchild); /* 构造右子树 */
	}
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
bool BiTreeEmpty(BiTree T)
{
	if (T)
		return 0;
	else
		return 1;
}


/* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
int BiTreeDepth(BiTree T)
{
	int i, j;
	if (!T)
		return 0;
	if (T->lchild)
		i = BiTreeDepth(T->lchild);
	else
		i = 0;
	if (T->rchild)
		j = BiTreeDepth(T->rchild);
	else
		j = 0;
	return i>j ? i + 1 : j + 1;
}

/* 初始条件: 二叉树T存在。操作结果: 返回T的根 */
TElemType Root(BiTree T)
{
	char c =' ';//后面返回用空字符
	if (BiTreeEmpty(T))
		return c;
	else
		return T->data;
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 前序递归遍历T */
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
	PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 中序递归遍历T */
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild); /* 中序遍历左子树 */
	printf("%c", T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 后序递归遍历T */
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild); /* 先后序遍历左子树  */
	PostOrderTraverse(T->rchild); /* 再后序遍历右子树  */
	printf("%c", T->data);/* 显示结点数据，可以更改为其它对结点操作 */
}


//深度优先搜索
//利用栈，现将右子树压栈再将左子树压栈
void DepthFirstSearch(BiTNode *root)
{
	stack<BiTNode*> nodeStack;
	nodeStack.push(root);
	while (!nodeStack.empty())
	{
		BiTNode *node = nodeStack.top();
		cout << node->data << ' ';
		nodeStack.pop();
		if (node->rchild)
		{
			nodeStack.push(node->rchild);
		}
		if (node->lchild)
		{
			nodeStack.push(node->lchild);
		}
	}
}

//广度优先搜索，队列
void BreadthFirstSearch(BiTNode *root)
{
	queue<BiTNode*> nodeQueue;
	 if(root == NULL) return ;
	nodeQueue.push(root);
	while (!nodeQueue.empty())
	{
		BiTNode *node = nodeQueue.front();
		cout << node->data << ' ';
		nodeQueue.pop();
		if (node->lchild)
		{
			nodeQueue.push(node->lchild);
		}
		if (node->rchild)
		{
			nodeQueue.push(node->rchild);
		}
	}
}
void PrintNodeAtLevel(BiTNode* T, int level)
{
	// 空树或层级不合理
	if (NULL == T || level < 1)
		return;
	if (1 == level)
	{
		cout << T->data;
		return;
	}

	// 左子树的 level - 1 级
	PrintNodeAtLevel(T->lchild, level - 1);

	// 右子树的 level - 1 级
	PrintNodeAtLevel(T->rchild, level - 1);
}

void LevelTraverse(BiTNode* T)
{
	if (NULL == T)
		return;
	int depth = BiTreeDepth(T);
	int i;
	for (i = 1; i <= depth; i++)
	{
		PrintNodeAtLevel(T, i);
	}
}

int main()
{
	BiTree T;
	TElemType e1;

	//gets(s);//写法2
	//输入前序遍历结果ABDH#K###E##CFI###G#J##
	CreateBiTree(&T);

	printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
	e1 = Root(T);
	printf("二叉树的根为: %c\n", e1);
	printf("\n前序遍历二叉树:");
	PreOrderTraverse(T);
	printf("\n中序遍历二叉树:");
	InOrderTraverse(T);
	printf("\n后序遍历二叉树:");
	PostOrderTraverse(T);

	cout << endl<<"深度优先遍历:" ;
	DepthFirstSearch( T);
	cout << endl;
	cout << "广度优先搜索" ;
	 BreadthFirstSearch(T);
	 cout << endl;
	 cout << "层次遍历：";//和广度优先搜索一致
	 LevelTraverse(T);
	system("pause");
	return 0;
}

