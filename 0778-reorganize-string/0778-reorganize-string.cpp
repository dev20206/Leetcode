class Solution {
public:
    string reorganizeString(string str) {
        vector<int> hash(26, 0);
        for(char c : str) {
            hash[c - 'a']++;
        }

        int maxCount = 0, letter = 0;
        for(int i = 0; i < 26; i++) {
            if(hash[i] > maxCount) {
                maxCount = hash[i];
                letter = i;
            }
        }

        if(maxCount > (str.length() + 1) / 2) return "";

        string res(str.length(), ' ');
        int idx = 0;

        while(hash[letter] > 0) {
            res[idx] = 'a' + letter;
            idx += 2;
            hash[letter]--;
        }

        for(int i = 0; i < 26; i++) {
            while(hash[i] > 0) {
                if(idx >= str.length()) idx = 1;
                res[idx] = 'a' + i;
                idx += 2;
                hash[i]--;
            }
        }

        return res;
    }
};