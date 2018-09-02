//https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> array;
    stack<int> S;
        ListNode* phead = head;
        while(phead!=NULL)
            {
            S.push(phead->val);
            phead = phead->next;
        }
        while(!S.empty())
            {
            array.push_back(S.top());
            S.pop();
        }
        return array;
    }
};