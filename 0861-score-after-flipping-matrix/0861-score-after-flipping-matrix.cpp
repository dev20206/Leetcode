#include <vector>
#include <cmath>

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < m; ++j) {
                    grid[i][j] ^= 1;
                }
            }
        }
        
        for (int j = 0; j < m; ++j) {
            int zeros = 0;
            for (int i = 0; i < n; ++i) {
                if (grid[i][j] == 0)
                    zeros++;
            }
            if (zeros > n - zeros) {
                for (int i = 0; i < n; ++i) {
                    grid[i][j] ^= 1;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    sum += pow(2, m - j - 1);
                }
            }
        }
        
        return sum;
    }
};
