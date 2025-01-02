class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // Define vowels for quick lookup
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        // Precompute the counts of words starting and ending with vowels
        vector<int> prefixSum(words.size() + 1, 0);
        for (int i = 0; i < words.size(); ++i) {
            if (vowels.count(words[i].front()) && vowels.count(words[i].back())) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }
        
        // Answer each query using the prefix sum
        vector<int> ans;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            ans.push_back(prefixSum[r + 1] - prefixSum[l]);
        }
        
        return ans;
    }
};
