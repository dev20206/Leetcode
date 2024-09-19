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

    ListNode* split(ListNode* head)
    {
        ListNode* slow =head, *fast = head;

        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondhalf = slow->next;
        slow->next = NULL;
        return secondhalf;
    }

    ListNode* merge(ListNode* first , ListNode* second)
    {
        if(!first)
            return second;
        if(!second)
            return first;

        if(first->val < second->val)
        {
            first->next = merge(first->next, second);
            return first;
        }
        else
        {
            second->next = merge(first, second->next);
            return second;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        
    ListNode* secondhalf = split(head);
    secondhalf = sortList(secondhalf);
    head = sortList(head);
    

    return merge(head,secondhalf);
    }

};