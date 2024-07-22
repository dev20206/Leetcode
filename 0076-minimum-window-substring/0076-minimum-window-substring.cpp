#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return "";
        
        int hash[256] = {0};
        int window[256] = {0};
        
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }
        
        int l = 0, r = 0, cnt = 0, minlen = INT_MAX, sindex = -1;
        
        while (r < n) {
            char c = s[r];
            if (hash[c] > 0) {
                window[c]++;
                if (window[c] <= hash[c]) cnt++;
            }
            
            while (cnt == m) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sindex = l;
                }
                
                char c2 = s[l];
                if (hash[c2] > 0) {
                    window[c2]--;
                    if (window[c2] < hash[c2]) cnt--;
                }
                l++;
            }
            
            r++;
        }
        
        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};
