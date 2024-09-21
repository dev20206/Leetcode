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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)  // Handle edge cases: empty list or only one node
            return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        head = head->next;  // The new head is the second node after the first swap

        while (curr && curr->next) {
            ListNode* second = curr->next;  // The second node in the pair
            
            curr->next = second->next;      // Point current node to the node after the pair
            second->next = curr;            // Swap the current pair

            if (prev) {
                prev->next = second;        // Link the previous pair to the swapped pair
            }

            prev = curr;                    // Update prev to the current node
            curr = curr->next;              // Move to the next pair
        }

        return head;
    }
};
