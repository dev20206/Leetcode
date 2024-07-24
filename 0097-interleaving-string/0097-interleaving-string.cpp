class Solution {
public:
    bool f(string &s1, string &s2, string &s3, int i, int j, int o) {
        if (o == 0) {
            return i == 0 && j == 0;
        }

        if (i > 0 && s1[i - 1] == s3[o - 1] && f(s1, s2, s3, i - 1, j, o - 1)) {
            return true;
        }
        if (j > 0 && s2[j - 1] == s3[o - 1] && f(s1, s2, s3, i, j - 1, o - 1)) {
            return true;
        }

        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();
        if (n + m != o) {
            return false;
        }
        return f(s1, s2, s3, n, m, o);
    }
};
