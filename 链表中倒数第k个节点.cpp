//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
     if(k<=0||pListHead==nullptr){
            return nullptr;
        }
        ListNode* head=pListHead;
        ListNode* tail=pListHead;
        for(int i=1;i<k;i++){
            if(head->next)
                head=head->next;
            else
                return nullptr;
        }
        while(head->next!=nullptr){
            head=head->next;
            tail=tail->next;
        }
        return tail;
     
    }
    
};