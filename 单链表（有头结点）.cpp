#include<iostream>
#include <stdlib.h>
using namespace std;
/*
typedef struct Node
{
	int data;
	struct Node *next;
}Node, *LinkList;
//typedef struct Node *LinkList;
*/
struct Node
{
	int data;
    Node *next;
};
typedef  Node *LinkList;//LinkListwei Node*类型

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
bool ListInsert(LinkList *L, int i, int e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i)     /* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return 0;   /* 第i个元素不存在 */
	s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
	s->data = e;
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;          /* 将s赋值给p的后继 */
	return 1;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
bool ListDelete(LinkList *L, int i, int *e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* 遍历寻找第i个元素 */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return 0;           /* 第i个元素不存在 */
	q = p->next;
	p->next = q->next;			/* 将q的后继赋值给p的后继 */
	*e = q->data;               /* 将q结点中的数据给e */
	free(q);                    /* 让系统回收此结点，释放内存 */
	return 1;
}

void CreateListHead(LinkList *L, int n,int *a)//头插法
{
	LinkList p;
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	int i;         
	for (i = 0; i<n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = a[i];            
		p->next = (*L)->next;
		(*L)->next = p;						/*  插入到表头 */
	}
}
void CreateListTail(LinkList *L, int n,int *a)//尾插法
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(Node));
	//(*L)->next = NULL;可以写也可以不写
	r = *L;                                /* r为指向尾部的结点 */
	for (i = 0; i<n; i++)
	{
		p = (Node *)malloc(sizeof(Node)); /*  生成新结点 */
		p->data =a[i] ;          
		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = NULL;                       /* 表示当前链表结束 */
}

bool ListTraverse(LinkList L)//输出所有节点值
{
	LinkList p = L->next;
	if (p == NULL) return 0;
	while (p&&p->next)//可以去掉最后一个数字的后的空格
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("%d", p->data);
	printf("\n");
	return 1;
}

int ListLength(LinkList L)//链表长度
{
	int i = 0;
	LinkList p = L->next;  //p指向第一个结点
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}
bool GetElem(LinkList L, int i, int *e)//用*e输出第i个结点值
{
	int j;
	LinkList p;		/* 声明一结点p */
	p = L->next;		/* 让p指向链表L的第一个结点 */
	j = 1;		/*  j为计数器 */
	while (p && j<i)  /* p不为空或者计数器j还没有等于i时，循环继续 */
	{
		p = p->next;  /* 让p指向下一个结点 */
		++j;
	}
	if (!p || j>i)
		return false;  /*  第i个元素不存在 */
	*e = p->data;   /*  取第i个元素的数据 */
	return true;
}
bool ListReverse(LinkList *L)//链表反转
{//头结点不动
	LinkList p, q, r;
	p = (*L)->next;//p指向第一个结点
	if (p == NULL)
		return NULL;
	q = p->next;//q指向第二个结点
	p->next = NULL;
	while (q)
	{
		r = q-> next;//r指向再下一个节点
		q->next = p;
		p = q;
		q = r;
	}
	(*L)->next = p;
	return 1;
}


LinkList Merge(LinkList L1, LinkList L2)   ///合并两个有序单链表
{
	LinkList pa, pb, pc, L;
	//L = (LinkList)malloc(sizeof(Node));
	L = new Node;
	pa = L1->next;
	pb = L2->next;
	pc = L;
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	L1->next = NULL;
	L2->next = NULL;
	return L;
}

 

int main(){
	//    int n;
	//	cin >> n;
	//	int a[1000] = { 0 };
	//	for (int i = 0; i < n; i++)
	//		cin >> a[i];
	//	int k;
	//	cin >> k;
	//	/*尾插法建立链表，并实现测长，输出倒数第k个元素*/
	//	
	//	LinkList L;
	//	
	//	CreateListTail(&L, n, a);//尾插法
	//	 ListTraverse(L);
	//	int len = ListLength(L);
	//	cout << "链表长度："<<len << endl;
	//	int result = 0;
	//	GetElem(L, n - k + 1, &result);
	//	cout << result << endl;
	//	
 // //头插法建立链表，并实现测长，输出倒数第k个元素
	//	LinkList L1;
	//	CreateListHead(&L1, n, a);//头插法
	//	ListTraverse(L1);
	//	GetElem(L1, k , &result);
	//	cout << result << endl;
	//	
	////反转链表
 //   ListReverse(&L1);
	//printf("逆转后L1的元素：");
	//ListTraverse(L1);
		
	//合并两个有序单链表

	LinkList La,Lb,Lc;
	

	int A[6]={0,1,4,7,8,11};
	int B[5]={1,2,3,7,8};
	CreateListTail(&Lb, 6, A);
     ListTraverse(Lb);
	CreateListTail(&La, 5, B);
	 ListTraverse(La);
	 Lc = Merge(La, Lb);
	 
    ListTraverse(Lc);
	
	system("pause");
}