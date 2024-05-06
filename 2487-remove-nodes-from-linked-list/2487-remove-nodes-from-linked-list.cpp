class Solution {
public:

    ListNode* removeNodes(ListNode* head) {
        if(!head->next) return head;
        ListNode* nxtGreaterNode = removeNodes(head->next);
        if(nxtGreaterNode->val > head->val){
            return nxtGreaterNode;
        }
        head->next = nxtGreaterNode;
        return head;
    }
};