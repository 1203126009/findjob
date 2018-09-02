//https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == NULL) return pHead2;
    if (pHead2 == NULL) return pHead1;
    ListNode *mergeList = NULL;
    if (pHead1->val < pHead2->val) {
        mergeList = pHead1;
        mergeList->next = Merge(pHead1->next, pHead2);
    }
    else {
        mergeList = pHead2;
        mergeList->next = Merge(pHead1, pHead2->next);
    }
    return mergeList;
}
};
