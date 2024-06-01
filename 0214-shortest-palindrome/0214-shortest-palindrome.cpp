class Solution {
public:
    string shortestPalindrome(string s) {
        const int BASE = 131; // Base for polynomial hashing
        
        // Initialize hash values and other variables
        unsigned long long prefixHash = 0; // Hash value for the prefix
        unsigned long long suffixHash = 0; // Hash value for the suffix
        unsigned long long baseMultiplier = 1; // Power multiplier for the hash computation
        int longestPalindromeEndIndex = 0; // Index marking the end of the longest palindrome starting at position 0
        int length = s.size(); // Length of the input string

        // Loop through the string character by character
        for (int i = 0; i < length; ++i) {
            int charValue = s[i] - 'a' + 1; // Convert char to int (1-based for 'a' to 'z')
            prefixHash = prefixHash * BASE + charValue; // Update prefix hash polynomially
            suffixHash = suffixHash + baseMultiplier * charValue; // Update suffix hash
            baseMultiplier *= BASE; // Update the base multiplier for the next character

            // If the current prefix is a palindrome (checked by comparing its hash with the suffix hash)
            if (prefixHash == suffixHash) {
                longestPalindromeEndIndex = i + 1; // Update the end index of the longest palindrome found
            }
        }

        // If the whole string is a palindrome, return it as is
        if (longestPalindromeEndIndex == length) {
            return s;
        }

        // Otherwise, construct the shortest palindrome by appending the reverse of the remaining substring
        string remainingSubstring = s.substr(longestPalindromeEndIndex, length - longestPalindromeEndIndex);
        reverse(remainingSubstring.begin(), remainingSubstring.end());
        return remainingSubstring + s; // Concatenate the reversed substring with the original string
    }
};