class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevA = nullptr;
        ListNode* nodeA = list1;
        ListNode* nodeB = list1;
        
        for (int i = 0; i < a; ++i) {
            prevA = nodeA;
            nodeA = nodeA->next;
        }
        
        for (int i = 0; i < b + 1; ++i) {
            nodeB = nodeB->next;
        }
        
        if (prevA != nullptr) {
            prevA->next = list2;
        }
        
        ListNode* lastNodeList2 = list2;
        while (lastNodeList2->next != nullptr) {
            lastNodeList2 = lastNodeList2->next;
        }
        
        lastNodeList2->next = nodeB;
        
        return list1;
    }
};
