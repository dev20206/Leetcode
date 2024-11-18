class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) return ans; // If k is 0, return all zeros.

        int direction = k > 0 ? 1 : -1; // Determine the direction of the sum.
        k = abs(k); // Work with the absolute value of k.

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 1; j <= k; j++) {
                int index = (i + direction * j + n) % n; // Calculate circular index.
                sum += code[index];
            }
            ans[i] = sum;
        }

        return ans;
    }
};
