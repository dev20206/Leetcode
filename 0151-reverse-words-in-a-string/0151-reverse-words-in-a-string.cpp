#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        for(int i = s.length()-1; i >= 0; i--) {
            if(s[i] != ' ') {
                temp.push_back(s[i]);
            } else {
                if (!temp.empty()) {
                    reverse(temp.begin(), temp.end());
                    ans += temp + ' ';
                    temp = "";
                }
            }
        }
        if (!temp.empty()) {
            reverse(temp.begin(), temp.end());
            ans += temp;
        } else {
            // Remove last space if it exists
            if (!ans.empty() && ans.back() == ' ')
                ans.pop_back();
        }
        return ans;
    }
};
