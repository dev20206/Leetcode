class Solution {
public:
    bool rotateString(string s, string goal) {
         if (s.size() != goal.size()) {
            return false;
        }
        string final = s+s;
        if(final.find(goal)!=string::npos)
        {
            return true;

        }
        return false;
    }
};