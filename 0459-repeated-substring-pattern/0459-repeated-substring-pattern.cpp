class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        
        // Check possible lengths for the repeated substring pattern
        for (int len = 1; len <= n / 2; ++len) {
            if (n % len == 0) {  // Check if `len` divides `n`
                string sub = s.substr(0, len);
                string repeated = "";
                
                // Repeat the substring len times to reconstruct the original string
                for (int i = 0; i < n / len; ++i) {
                    repeated += sub;
                }
                
                // If the constructed string matches the original, return true
                if (repeated == s) {
                    return true;
                }
            }
        }
        
        // If no valid repeating pattern found, return false
        return false;
    }
};
