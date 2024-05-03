class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != 'O')
            return;
        
        board[row][col] = '#'; // Mark visited
        
        // Perform DFS in all four directions
        dfs(row + 1, col, board);
        dfs(row - 1, col, board);
        dfs(row, col + 1, board);
        dfs(row, col - 1, board);
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        
        // Traverse first and last columns
        for (int i = 0; i < n; ++i) {
            dfs(i, 0, board);
            dfs(i, m - 1, board);
        }
        
        // Traverse first and last rows
        for (int j = 0; j < m; ++j) {
            dfs(0, j, board);
            dfs(n - 1, j, board);
        }
        
        // Convert captured regions marked by '#' back to 'O', and the rest to 'X'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Mark as surrounded by 'X'
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O'; // Restore surrounded 'O'
                }
            }
        }
    }
};
