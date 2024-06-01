class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int opencount = 0;
        
        for(char c: s){
            if(c=='('){
                if(opencount>0){
                    ans+=c;
                }
                opencount++;
            }
            else if(c==')')
            {
                opencount--;
                if(opencount>0){
                    ans+=c;
                }
            }
        }
        return ans;
    }
};