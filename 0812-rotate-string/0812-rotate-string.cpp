class Solution {
public:
    bool rotateString(string s, string goal) {
        // If the lengths are different, goal can't be a rotation of s
        if (s.size() != goal.size()) {
            return false;
        }

        // Concatenate s with itself to cover all possible rotations
        string final = s + s;

        // Check if goal is a substring of the concatenated string
        return final.find(goal) != string::npos;
    }
};
