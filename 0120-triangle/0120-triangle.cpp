class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int j = 0; j < triangle[n-1].size(); j++) {
            dp[n-1][j] = triangle[n-1][j];
        }

        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int down = triangle[i][j] + dp[i+1][j];
                int downright = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, downright);
            }
        }
        return dp[0][0];        
    }
};
