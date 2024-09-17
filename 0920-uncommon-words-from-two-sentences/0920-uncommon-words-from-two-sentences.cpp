class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;  // To count the frequency of each word
        
        // Process the first sentence
        istringstream is1(s1);
        string word;
        while (is1 >> word) {
            wordCount[word]++;  // Increment word count
        }
        
        // Process the second sentence
        istringstream is2(s2);
        while (is2 >> word) {
            wordCount[word]++;  // Increment word count
        }
        
        // Now we have the frequency of all words from both sentences.
        vector<string> ans;
        
        // Find all words that appear exactly once
        for (const auto& entry : wordCount) {
            if (entry.second == 1) {
                ans.push_back(entry.first);  // Add to result if the word appears exactly once
            }
        }
        
        return ans;  // Return the list of uncommon words
    }
};
