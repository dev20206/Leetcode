class Solution {
public:
    int minimizedStringLength(string s) {
        int len = s.length();
        int count = len;
        sort(s.begin(),s.end());
        for(int i = 1 ; i<len ; i++)
        {
            if(s[i-1]==s[i])
                count--;
        }
        return count;
    }
};