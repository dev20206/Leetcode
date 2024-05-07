class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* dummy = new ListNode(10);
        ListNode* newList = dummy;
        vector<int> ans;
        vector<int> news;
        while (head != nullptr) {
            ans.push_back(head->val);
            head = head->next;
        }
        int temp = 0;
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            temp += (ans[i] * 2);
            int rem = temp % 10;
            news.push_back(rem);
            temp /= 10;
        }
        while (temp > 0) {
            news.push_back(temp % 10);
            temp /= 10;
        }
        reverse(news.begin(), news.end());
        for (int i = 0; i < news.size(); i++) {
            ListNode* temp = new ListNode(news[i]);
            dummy->next = temp;
            dummy = dummy->next;
        }
        return newList->next;
    }
};
