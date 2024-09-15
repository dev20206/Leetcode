class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0, count = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            while (st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            count = max(count, right - left + 1);
        }
        
        return count;
    }
};
