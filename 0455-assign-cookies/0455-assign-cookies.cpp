class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int j = 0; // Initialize cookie index outside the loop
        
        for (int i = 0; i < g.size(); i++) {
            while (j < s.size() && s[j] < g[i]) {
                j++; // Move to the next cookie if the current one cannot satisfy the child
            }
            if (j < s.size() && s[j] >= g[i]) {
                count++; // Count the child as content
                j++; // Move to the next cookie for the next child
            }
        }
        
        return count;
    }
};