#include<iostream>
#include<vector>
using namespace std;
typedef struct tagLinkNode
{
	int val;
	struct tagLinkNode *next;

}LinkNode;
int res(int i, int k){
	int sum = i;
	for (int j = 1; j <= k; j++){
		sum *= 10;
	}
	return sum;
}
LinkNode* CreateLinkNode(int value)//生成值为value的节点
{
	LinkNode* pNode = new LinkNode();
	pNode->val = value;
	pNode->next = nullptr;

	return pNode;
}
void ConnectLinkNodes(LinkNode* pCurrent, LinkNode* pNext)//连接两个节点
{
	pCurrent->next = pNext;
}
void PrintList(LinkNode* pHead)
{

	LinkNode* pNode = pHead;
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->val);
		pNode = pNode->next;
	}
}
LinkNode   *BuildBridge(LinkNode *B1, LinkNode *B2)
{
	int a[100] = { 0 };
	int b[100] = { 0 };
	int i = 0;
	int j = 0;
	while (B1 != nullptr){
		a[i] = B1->val;
		B1 = B1->next;
		i++;
	}
	while (B2 != nullptr){
		b[j] = B2->val;
		B2 = B2->next;
		j++;
	}
	int sum1 = 0,sum2=0;
	for (int k = 0; k < i; k++)
		sum1 += res(a[k], i - k-1);
	for (int k = 0; k < j; k++)
		sum2 += res(b[k], j - k-1);
	int result = sum1 + sum2;
	int c[100] = { 0 };
	int k = 0;
	while (result){
		c[k++] = result % 10;
		result = result / 10;
	}
	int *tempt = new int[k];
	for (int kk = 0; kk < k; kk++){
		tempt[kk] = c[k - kk - 1];
	}

	for (int jjj = 0; jjj < k; jjj++){
		cout << tempt[jjj] << endl;
	}

	vector<LinkNode *> vec3;
	for (int i = 0; i < k; i++){
		vec3.push_back(CreateLinkNode(tempt[i]));
	}
		
	for (int i = 0; i < k-1; i++)
		ConnectLinkNodes(vec3[i], vec3[i + 1]);

	return  vec3[0];

}


int main(){
	vector<LinkNode*> vec;
	vector<LinkNode*> vec1;
	int a[3] = {2,4,8 };
	int b[4] = { 1, 5, 7, 9 };
	for (int i = 0; i < 3; i++)//生成的节点存在vector里面
	{
			vec.push_back(CreateLinkNode(a[i]));

	}
	for (int i = 0; i < 2; i++)
	{
		ConnectLinkNodes(vec[i], vec[i + 1]);
		
	}
	for (int i = 0; i < 4; i++)//生成的节点存在vector里面
	{
			vec1.push_back(CreateLinkNode(b[i]));

	}
	for (int i = 0; i <3; i++)
	{
		ConnectLinkNodes(vec1[i], vec1[i + 1]);

	}
	LinkNode   * s;
	s= BuildBridge(vec[0], vec1[0]);
	while (s != nullptr){
		cout << s->val<<endl;
		s = s->next;
	}
	system("pause");
}