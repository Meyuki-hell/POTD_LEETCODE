class Solution {
public:
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    int mod = 1000000007;

    bool isValid(int i, int j, vector< vector<int>> &grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return false;
        
        return true;
    }

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 1;
        for(int x = 0; x < 4; x++){
            int r = i + dr[x];
            int c = j + dc[x];

            if(isValid(r, c, grid) && grid[i][j] < grid[r][c]){
                ans = (ans % mod + dfs(r, c, grid, dp) % mod) % mod;
            }
        }
        return dp[i][j] = ans;
    }

    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        long long count = 0;
        if(grid.empty() || grid[0].empty()){
            return 0;
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                count = (count % mod + dfs(i, j, grid, dp) % mod) % mod;
            }
        }
        return (int)count % mod;
    }
};
