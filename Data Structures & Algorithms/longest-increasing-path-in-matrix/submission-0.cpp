class Solution {
   private:
    int totalRows = 0;
    int totalCols = 0;

   private:
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp) {
        if (dp[r][c] != 0) return dp[r][c];
        int maxFrom_other = 0;
        if (r + 1 < totalRows && matrix[r + 1][c] > matrix[r][c]) {
            maxFrom_other = max(maxFrom_other, dfs(matrix, r + 1, c, dp));
        }
        if (r - 1 >= 0 && matrix[r - 1][c] > matrix[r][c]) {
            maxFrom_other = max(maxFrom_other, dfs(matrix, r - 1, c, dp));
        }
        if (c + 1 < totalCols && matrix[r ][c +1] > matrix[r][c]) {
            maxFrom_other = max(maxFrom_other, dfs(matrix, r , c + 1, dp));
        }
        if (c - 1 >=  0 && matrix[r][c - 1 ] > matrix[r][c]) {
            maxFrom_other = max(maxFrom_other, dfs(matrix, r , c -1, dp));
        }
        dp[r][c] = 1 + maxFrom_other ;
        return dp[r][c];
    }

   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        totalRows = matrix.size();
        totalCols = matrix[0].size();
        vector<vector<int>> dp(totalRows, vector<int>(totalCols, 0));
        int maxPath = 0;
        for (int i = 0; i < totalRows; i++) {
            for (int j = 0; j < totalCols; j++) {
                int currentPath = dfs(matrix, i, j, dp);
                maxPath = max(maxPath, currentPath);
            }
        }
        return maxPath;
    }
};