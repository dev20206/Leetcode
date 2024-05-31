class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10)
            return {};
        
        unordered_set<string> seen ,repeated;
        for(int i = 0 ; i < s.length()-9 ; i++)
        {
            string sequence = s.substr(i,10);
            if(seen.find(sequence)!=seen.end())
            {
                repeated.insert(sequence);
            }
            else
                seen.insert(sequence);
        }
        return vector<string>(repeated.begin(),repeated.end());
    }
};