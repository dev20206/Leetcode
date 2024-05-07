class Solution {
public:
    string reversePrefix(string word, char ch) {
        int temp = -1;
        int count = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == ch) {
                temp = i;
                break;
            }
        }
        if (temp == -1)
            return word;

        string word2(temp + 1, ' ');
        for (int i = 0; i <= temp; i++) {
            word2[i] = word[i];
        }
        reverse(word2.begin(), word2.end());

        string word3(word.length() - temp - 1, ' ');
        for (int i = temp + 1; i < word.length(); i++) {
            word3[count] = word[i];
            count++;
        }
        return word2 + word3;
    }
};
