class Solution {
public:
    int n, m;
    bool valid(int i, int j){ return i >= 0 && i < n && j >= 0 && j < m;}

    int dp[1005][1005];
    int go( int i, int j, vector<vector<int>>& grid ){
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int op1 = 0, op2 = 0, op3 = 0;
        if(valid(i - 1, j + 1) && grid[i - 1][j + 1] > grid[i][j])
            op1 = go(i - 1, j + 1, grid) + 1;

        if(valid(i, j + 1) && grid[i][j + 1] > grid[i][j])
            op2 = go(i, j + 1, grid) + 1;

        if(valid(i + 1, j + 1) && grid[i + 1][j + 1] > grid[i][j])
            op3 = go(i + 1, j + 1, grid) + 1;
        
        return dp[i][j] = max({op1, op2, op3});
    }

    int maxMoves(vector<vector<int>>& grid){
        n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n + 2; ++i)
            for(int j = 0; j < m + 2; ++j)
                dp[i][j] = -1;
        
        int mx = 0;
        for(int i = 0; i < n; i++)
            mx = max(mx, go(i, 0, grid));
        
        return mx;
    }
};