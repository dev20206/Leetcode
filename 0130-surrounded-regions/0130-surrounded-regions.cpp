class Solution {
private:
    void dfs(int row, int col, int delrow[], int delcol[], vector<vector<char>>& board, vector<vector<int>>& vis) {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) { // Adjust loop to iterate over the size of delrow
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, delrow, delcol, board, vis); // Pass vis to the recursive call
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Traverse first and last rows
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, delrow, delcol, board, vis);
            }
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, delrow, delcol, board, vis);
            }
        }
        
        // Traverse first and last columns
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, delrow, delcol, board, vis);
            }
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, delrow, delcol, board, vis);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
