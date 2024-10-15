class Solution {
public:
    int n, m;
    int dp[205][205];
    int go( int i, int j, vector<vector<int>>& grid)
    {
        if( i == n - 1 && j == m - 1 )
            return grid[i][j];

        if( j == m || i == n )
            return 1e6;

        if( dp[i][j] != -1 )
            return dp[i][j];
        
        int op1 = go(i + 1, j, grid);
        int op2 = go(i, j + 1, grid);

        return dp[i][j] = min(op1, op2) + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof dp);
        return go(0, 0, grid);
    }
};