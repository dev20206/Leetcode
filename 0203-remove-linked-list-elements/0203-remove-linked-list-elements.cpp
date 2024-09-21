/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return NULL;
        
        if(head!=nullptr && head->val==val)
        {
            while(head!=nullptr && head->val==val)
            {
                head = head->next;
            }
        }
        ListNode *prev = NULL;
        ListNode *curr = head;

        while(curr!=NULL)
        {
            if(curr->val==val)
            {
                prev->next = curr->next;
            }
            else
            {
            prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};