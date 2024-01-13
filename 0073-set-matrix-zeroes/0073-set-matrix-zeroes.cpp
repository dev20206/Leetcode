#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return; // Handle empty matrix
        
        int m = matrix[0].size();
        
        std::vector<int> row(n, 0);
        std::vector<int> col(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
