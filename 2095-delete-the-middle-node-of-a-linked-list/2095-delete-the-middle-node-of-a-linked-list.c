struct ListNode* deleteMiddle(struct ListNode* head){
    if(!head->next) return NULL;
        
    struct ListNode *fast = head->next;
    struct ListNode *slow = head;
    
    while(fast && fast->next){
        fast = fast->next->next;
        if(!fast) break;
        slow = slow->next;
    }
    struct ListNode *q = slow->next;
    slow->next = slow->next->next;
    free(q);
    return head;
}