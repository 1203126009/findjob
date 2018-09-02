#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
	int       val;
	ListNode* next;
	//ListNode(int x) :val(x), next(NULL)

};

ListNode* CreateListNode(int value)//生成值为value的节点
{
	ListNode* pNode = new ListNode();
	//ListNode* pNode = new ListNode(0);
	
	pNode->val = value;
	pNode->next = nullptr;

	return pNode;
}
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)//连接两个节点
{
	if (pCurrent == nullptr)
	{
		printf("Error to connect two nodes.\n");
		exit(1);
	}

	pCurrent->next = pNext;
}
/*void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
	{
		printf("The node is nullptr\n");
	}
	else
	{
		printf("The key in node is %d.\n", pNode->val);
	}
}
*/
void PrintList(ListNode* pHead)
{
	printf("PrintList starts.\n");

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->val);
		pNode = pNode->next;
	}
}
/*
void DestroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->next;
		delete pNode;
		pNode = pHead;
	}
}

void AddToTail(ListNode** pHead, int value)//链表尾部加一个节点
{
	ListNode* pNew = new ListNode();
	pNew->val = value;
	pNew->next = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->next != nullptr)
			pNode = pNode->next;

		pNode->next = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pToBeDeleted = nullptr;
	if ((*pHead)->val == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->next;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->next != nullptr && pNode->next->val != value)
			pNode = pNode->next;

		if (pNode->next != nullptr && pNode->next->val == value)
		{
			pToBeDeleted = pNode->next;
			pNode->next = pNode->next->next;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}
*/


int main(){
	vector<ListNode*> vec;
	vector<ListNode*> vec1;
	int a[5] = { 0, 1, 2, 32, 4 };
	for (int i = 0; i < 5; i++)//生成的节点存在vector里面
	{
		vec.push_back(CreateListNode(a[i]));
		//vec1.push_back(new ListNode(a[i]));
	}
	for (int i = 0; i < 4; i++)
	{
		ConnectListNodes(vec[i], vec[i + 1]);
		//ConnectListNodes(vec1[i], vec1[i + 1]);
	}

	PrintList(vec[0]);
	//PrintList(vec1[0]);

	cout << endl;
	system("pause");
}