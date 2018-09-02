//https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&tPage=3&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead){
            return nullptr;
        }
        ListNode* ret=pHead;
        ListNode* pre=nullptr,*current=pHead;
        while (current) {
            bool shoud_delete=false;
            if(current->next&&current->val==current->next->val){
                shoud_delete=true;
            }
            if(!shoud_delete){
                pre=current;
                current=current->next;
            }else{
                int val=current->val;
                ListNode* pnext;
                while (current&&(current->val==val)) {
                    pnext=current->next;
                    delete current;
                    current=pnext;
                }
                if(pre==nullptr){
                    pHead=current;
                }else{
                    pre->next=current;
                }
                 
            }
        }
        return pHead;
    }
};