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
typedef  Node *LinkList;//LinkListwei Node*����

/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
bool ListInsert(LinkList *L, int i, int e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i)     /* Ѱ�ҵ�i����� */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return 0;   /* ��i��Ԫ�ز����� */
	s = (LinkList)malloc(sizeof(Node));  /*  �����½��(C���Ա�׼����) */
	s->data = e;
	s->next = p->next;      /* ��p�ĺ�̽�㸳ֵ��s�ĺ��  */
	p->next = s;          /* ��s��ֵ��p�ĺ�� */
	return 1;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
bool ListDelete(LinkList *L, int i, int *e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* ����Ѱ�ҵ�i��Ԫ�� */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return 0;           /* ��i��Ԫ�ز����� */
	q = p->next;
	p->next = q->next;			/* ��q�ĺ�̸�ֵ��p�ĺ�� */
	*e = q->data;               /* ��q����е����ݸ�e */
	free(q);                    /* ��ϵͳ���մ˽�㣬�ͷ��ڴ� */
	return 1;
}

void CreateListHead(LinkList *L, int n,int *a)//ͷ�巨
{
	LinkList p;
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	int i;         
	for (i = 0; i<n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); /*  �����½�� */
		p->data = a[i];            
		p->next = (*L)->next;
		(*L)->next = p;						/*  ���뵽��ͷ */
	}
}
void CreateListTail(LinkList *L, int n,int *a)//β�巨
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(Node));
	//(*L)->next = NULL;����дҲ���Բ�д
	r = *L;                                /* rΪָ��β���Ľ�� */
	for (i = 0; i<n; i++)
	{
		p = (Node *)malloc(sizeof(Node)); /*  �����½�� */
		p->data =a[i] ;          
		r->next = p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = NULL;                       /* ��ʾ��ǰ������� */
}

bool ListTraverse(LinkList L)//������нڵ�ֵ
{
	LinkList p = L->next;
	if (p == NULL) return 0;
	while (p&&p->next)//����ȥ�����һ�����ֵĺ�Ŀո�
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("%d", p->data);
	printf("\n");
	return 1;
}

int ListLength(LinkList L)//������
{
	int i = 0;
	LinkList p = L->next;  //pָ���һ�����
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}
bool GetElem(LinkList L, int i, int *e)//��*e�����i�����ֵ
{
	int j;
	LinkList p;		/* ����һ���p */
	p = L->next;		/* ��pָ������L�ĵ�һ����� */
	j = 1;		/*  jΪ������ */
	while (p && j<i)  /* p��Ϊ�ջ��߼�����j��û�е���iʱ��ѭ������ */
	{
		p = p->next;  /* ��pָ����һ����� */
		++j;
	}
	if (!p || j>i)
		return false;  /*  ��i��Ԫ�ز����� */
	*e = p->data;   /*  ȡ��i��Ԫ�ص����� */
	return true;
}
bool ListReverse(LinkList *L)//����ת
{//ͷ��㲻��
	LinkList p, q, r;
	p = (*L)->next;//pָ���һ�����
	if (p == NULL)
		return NULL;
	q = p->next;//qָ��ڶ������
	p->next = NULL;
	while (q)
	{
		r = q-> next;//rָ������һ���ڵ�
		q->next = p;
		p = q;
		q = r;
	}
	(*L)->next = p;
	return 1;
}


LinkList Merge(LinkList L1, LinkList L2)   ///�ϲ�������������
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
	//	/*β�巨����������ʵ�ֲⳤ�����������k��Ԫ��*/
	//	
	//	LinkList L;
	//	
	//	CreateListTail(&L, n, a);//β�巨
	//	 ListTraverse(L);
	//	int len = ListLength(L);
	//	cout << "�����ȣ�"<<len << endl;
	//	int result = 0;
	//	GetElem(L, n - k + 1, &result);
	//	cout << result << endl;
	//	
 // //ͷ�巨����������ʵ�ֲⳤ�����������k��Ԫ��
	//	LinkList L1;
	//	CreateListHead(&L1, n, a);//ͷ�巨
	//	ListTraverse(L1);
	//	GetElem(L1, k , &result);
	//	cout << result << endl;
	//	
	////��ת����
 //   ListReverse(&L1);
	//printf("��ת��L1��Ԫ�أ�");
	//ListTraverse(L1);
		
	//�ϲ�������������

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