#include "string.h"
#include "stdio.h"     
#include<iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
typedef char TElemType;

struct BiTNode  /* ���ṹ */
{
	TElemType data;		/* ������� */
	 BiTNode *lchild, *rchild; /* ���Һ���ָ�� */
} ;
typedef BiTNode * BiTree;

/* ��ǰ������������н���ֵ��һ���ַ��� */
/* #��ʾ������������������ʾ������T�� */
int index = 0;
char s[1000];

void CreateBiTree(BiTree *T)//����ǰ��������������
{
	TElemType ch;
	  scanf("%c",&ch); 
   //ch = s[index++];    //index��Ϊȫ�ֱ�����д��2

	if (ch == '#')
		*T = NULL;
	else
	{
		//*T = (BiTree)malloc(sizeof(BiTNode));
		*T = new BiTNode;
		if (!*T)
			exit(OVERFLOW);
		(*T)->data = ch; /* ���ɸ���� */
		CreateBiTree(&(*T)->lchild); /* ���������� */
		CreateBiTree(&(*T)->rchild); /* ���������� */
	}
}

/* ��ʼ����: ������T���� */
/* �������: ��TΪ�ն�����,�򷵻�TRUE,����FALSE */
bool BiTreeEmpty(BiTree T)
{
	if (T)
		return 0;
	else
		return 1;
}


/* ��ʼ����: ������T���ڡ��������: ����T����� */
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

/* ��ʼ����: ������T���ڡ��������: ����T�ĸ� */
TElemType Root(BiTree T)
{
	char c =' ';//���淵���ÿ��ַ�
	if (BiTreeEmpty(T))
		return c;
	else
		return T->data;
}

/* ��ʼ����: ������T���� */
/* �������: ǰ��ݹ����T */
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	PreOrderTraverse(T->lchild); /* ��������������� */
	PreOrderTraverse(T->rchild); /* ���������������� */
}

/* ��ʼ����: ������T���� */
/* �������: ����ݹ����T */
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild); /* ������������� */
	printf("%c", T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	InOrderTraverse(T->rchild); /* ���������������� */
}

/* ��ʼ����: ������T���� */
/* �������: ����ݹ����T */
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild); /* �Ⱥ������������  */
	PostOrderTraverse(T->rchild); /* �ٺ������������  */
	printf("%c", T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
}


//�����������
//����ջ���ֽ�������ѹջ�ٽ�������ѹջ
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

//�����������������
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
	// ������㼶������
	if (NULL == T || level < 1)
		return;
	if (1 == level)
	{
		cout << T->data;
		return;
	}

	// �������� level - 1 ��
	PrintNodeAtLevel(T->lchild, level - 1);

	// �������� level - 1 ��
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

	//gets(s);//д��2
	//����ǰ��������ABDH#K###E##CFI###G#J##
	CreateBiTree(&T);

	printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
	e1 = Root(T);
	printf("�������ĸ�Ϊ: %c\n", e1);
	printf("\nǰ�����������:");
	PreOrderTraverse(T);
	printf("\n�������������:");
	InOrderTraverse(T);
	printf("\n�������������:");
	PostOrderTraverse(T);

	cout << endl<<"������ȱ���:" ;
	DepthFirstSearch( T);
	cout << endl;
	cout << "�����������" ;
	 BreadthFirstSearch(T);
	 cout << endl;
	 cout << "��α�����";//�͹����������һ��
	 LevelTraverse(T);
	system("pause");
	return 0;
}

