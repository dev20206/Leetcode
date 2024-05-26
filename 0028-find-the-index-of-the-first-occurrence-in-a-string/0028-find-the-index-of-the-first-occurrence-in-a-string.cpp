class Solution {
public:
    int strStr(string haystack, string needle) {
        // Check for the edge case where needle is an empty string
        if (needle.empty()) return 0;

        int d = 256;  // Number of characters in the input alphabet
        int q = 101;  // A prime number
        int m = haystack.length();
        int n = needle.length();

        // If needle is longer than haystack, no match is possible
        if (n > m) return -1;

        int p = 0;  // Hash value for needle
        int t = 0;  // Hash value for haystack
        int h = 1;

        // The value of h would be "pow(d, n-1) % q"
        for (int i = 0; i < n - 1; i++)
            h = (h * d) % q;

        // Calculate the hash value of needle and the first window of haystack
        for (int i = 0; i < n; i++) {
            p = (d * p + needle[i]) % q;
            t = (d * t + haystack[i]) % q;
        }

        // Slide the pattern over text one by one
        for (int i = 0; i <= m - n; i++) {
            // Check the hash values of current window of text and pattern.
            // If the hash values match then only check for characters one by one
            if (p == t) {
                // Check for characters one by one
                int j;
                for (j = 0; j < n; j++) {
                    if (haystack[i + j] != needle[j])
                        break;
                }

                // If p == t and needle[0...n-1] = haystack[i, i+1, ...i+n-1]
                if (j == n)
                    return i;
            }

            // Calculate hash value for next window of haystack: Remove leading digit,
            // add trailing digit
            if (i < m - n) {
                t = (d * (t - haystack[i] * h) + haystack[i + n]) % q;

                // We might get negative value of t, converting it to positive
                if (t < 0)
                    t = (t + q);
            }
        }

        return -1;  // If no match is found
    }
};
