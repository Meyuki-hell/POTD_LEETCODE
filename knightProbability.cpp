class Solution {
public:
    double solve(int n, int k, int r, int c, vector<vector<vector< double>>>&dp){
        if(r < 0 || c < 0 || r >= n || c >= n) return 0;

        if(k == 0) return 1;

        if(dp[r][c][k] != -1) return dp[r][c][k];

        double ans = 0.0;

        int x[8] = {2, -2, 1, -1, 2, -2, 1, -1};
        int y[8] = {1, 1, 2, 2, -1, -1, -2, -2};

        for(int i = 0; i < 8; i++){
            ans += solve(n, k - 1, r + x[i], c + y[i], dp) / 8;
        }
        return dp[r][c][k] = ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector< double>>>dp(n+1, vector<vector<double>>(n+1, vector<double>(k+1,-1)));
        return solve(n, k, row, column, dp);
    }
};
