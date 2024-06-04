#include <string>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        int i = 0, j = 0;
        
        // Use two pointers to traverse both strings
        while (i < sLen && j < tLen) {
            if (s[i] == t[j]) {
                j++;  // Move to the next character in t
            }
            i++;  // Always move to the next character in s
        }
        
        // The number of characters to append is the length of t minus the matched characters
        return tLen - j;
    }
};
