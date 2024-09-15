class Solution {
public:
    void prefix_table(string needle, int n, vector<int>& f) {
        int i = 1, j = 0;
        f[0] = 0;
        
        // Build the prefix table (failure function)
        while (i < n) {
            if (needle[i] == needle[j]) {
                f[i] = j + 1;
                i++;
                j++;
            } else if (j > 0) {
                j = f[j - 1];
            } else {
                f[i] = 0;
                i++;
            }
        }
    }

    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        
        if (n == 0) return 0; // If needle is empty, return 0
        
        vector<int> f(n);
        prefix_table(needle, n, f); // Pass the needle and its size

        int i = 0, j = 0;

        while (i < m) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;

                if (j == n) {
                    return i - j; // Match found, return the start index
                }
            } else if (j > 0) {
                j = f[j - 1]; // Use failure function to avoid redundant comparisons
            } else {
                i++;
            }
        }
        
        return -1; // No match found
    }
};
