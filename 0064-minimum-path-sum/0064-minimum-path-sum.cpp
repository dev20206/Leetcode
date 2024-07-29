class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (i < 0 || j < 0) {
            return INT_MAX;  // Out of bounds
        }
        if (i == 0 && j == 0) {
            return grid[0][0];  // Base case: start of the grid
        }
        if (dp[i][j] != -1) {
            return dp[i][j];  // Return the memoized result
        }
        int up = INT_MAX;
        int left = INT_MAX;
        if(i>0)
             up = grid[i][j]+f(i - 1, j, dp, grid);
        if(j>0)
            left = grid[i][j]+f(i, j - 1, dp, grid);
        
        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp, grid);
    }
};
