/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode * itr=head1;
        while(itr)
        {
            itr->val=itr->val*-1;
            itr=itr->next;
        }
        itr=head2;
        while(itr)
        {
            if(itr->val <0)
                break;
            itr=itr->next;
        }
        ListNode* temp=head1;
        while(temp)
        {
            temp->val=temp->val*-1;
            temp=temp->next;
        }
        return itr;
    }
};