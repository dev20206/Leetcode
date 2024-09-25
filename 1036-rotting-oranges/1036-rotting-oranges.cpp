#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, minutes = 0;

        vector<int> delRow = {0, 0, -1, 1};
        vector<int> delCol = {1, -1, 0, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            minutes++;
            while (size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nrow = row + delRow[k];
                    int ncol = col + delCol[k];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;
                        fresh--;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};
