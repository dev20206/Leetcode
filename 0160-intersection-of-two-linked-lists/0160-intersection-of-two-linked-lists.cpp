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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        struct ListNode* itr = headA;
        int length1=0;
        int length2=0;
        int diff = 0;
        while(itr)
        {
            length1++;
            itr=itr->next;
        }
         itr = headB;
        while(itr)
        {
            length2++;
            itr=itr->next;
        }
        if(length1>length2)
        {
            diff = length1-length2;
            while(diff--)
            {
                headA= headA->next;
            }
        }
        if(length1<length2)
        {
            diff = length2-length1;
            while(diff--)
            {
                headB= headB->next;
            }
        }
        while(headA!=NULL && headB!=NULL)
        {
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
            
            
        
    }
};