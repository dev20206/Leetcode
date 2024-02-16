class Solution {
public:
    bool isPalindrome(string a) {
        if(a.empty()) return true;
         string ans;
         transform(a.begin(), a.end(), a.begin(), ::tolower);
         
         for (int i = 0; i < a.length(); i++) {
             if (isalnum(a[i]))  ans.push_back(a[i]);
            
        }

        cout<<ans<<endl;
        a= ans;
        reverse(ans.begin(), ans.end());
        return ans==a ;
    }
};