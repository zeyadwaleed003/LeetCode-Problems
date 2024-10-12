class Solution {
public:
    bool vis[305][305];
    vector<int>dx = {1, -1, 0, 0};
    vector<int>dy = {0, 0, 1, -1};
    int n, m;
    bool valid( int x, int y ){ return x >= 0 && x < n && y >= 0 && y < m; }
    void dfs( int x, int y, vector<vector<char>>& grid )
    {
        vis[x][y] = 1;
        for( int i = 0; i < 4; i++ )
        {
            int nx = x + dx[i], ny = y + dy[i];
            if( valid( nx, ny ) && grid[nx][ny] == '1' && !vis[nx][ny] )
                dfs( nx, ny, grid );
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        n = grid.size(), m = grid[0].size();
        
        int cnt = 0;
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                if( grid[i][j] == '1' && !vis[i][j] )
                {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }    
};