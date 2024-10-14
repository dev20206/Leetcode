class Solution {
public:
    int balancedStringSplit(string s) {
        int countr = 0;
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i]=='R')
                countr++;
            if(s[i]=='L')
                countr--;
            
            if(countr == 0){
                ans++;
            }
        }
     return ans;   
    }
};