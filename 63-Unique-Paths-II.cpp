class Solution {
public:
    int n, m, dp[105][105];
    int go( int i, int j, vector<vector<int>>& obstacleGrid)
    {
        if( i == n - 1 && j == m - 1 )
            return (obstacleGrid[i][j] == 0);
        
        if( i == n || j == m || obstacleGrid[i][j] == 1 )
            return 0;

        if( dp[i][j] != -1 )
            return dp[i][j];

        int op1 = go(i + 1, j, obstacleGrid);
        int op2 = go(i, j + 1, obstacleGrid);

        return dp[i][j] = op1 + op2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size(), m = obstacleGrid[0].size();
        memset(dp, -1, sizeof dp);
        return go(0, 0, obstacleGrid);
    }
};