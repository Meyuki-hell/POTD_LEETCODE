class Solution {
public:
    int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    if (dp[i][j] != 0) {
        return dp[i][j];
    }
    
    int m = matrix.size();
    int n = matrix[0].size();
    
    int longestPath = 1;
    
    for (int k = 0; k < 4; k++) {
        int r = i + dr[k];
        int c = j + dc[k];
        
        if (r >= 0 && r < m && c >= 0 && c < n && matrix[r][c] > matrix[i][j]) {
            longestPath = max(longestPath, 1 + dfs(r, c, matrix, dp));
        }
    }
    
    dp[i][j] = longestPath;
    return longestPath;
}

    
int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    
    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    int maxPath = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            maxPath = max(maxPath, dfs(i, j, matrix, dp));
        }
    }
    
    return maxPath;
}
};
