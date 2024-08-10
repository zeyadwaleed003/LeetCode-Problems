class Solution {
    vector<int>dx, dy;
public:
    map<pair<int,int>, bool>vis;

    vector<vector<int>> build(vector<string>& grid)
    {
        int n = grid.size();
        vector<vector<int>>ans(3 * n, vector<int>(3 * n, 0));
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                if( grid[i][j] == '\\' )
                {
                    ans[i * 3][j * 3] = 1;
                    ans[i * 3 + 1][j * 3 + 1] = 1;
                    ans[i * 3 + 2][j * 3 + 2] = 1;
                }

                if( grid[i][j] == '/' )
                {
                    ans[i * 3 + 2][j * 3] = 1;
                    ans[i * 3 + 1][j * 3 + 1] = 1;
                    ans[i * 3][j * 3 + 2] = 1;
                }
            }
        }

        return ans;
    }

    bool valid( int i, int j, int n ){ return i >= 0 && i < n && j >= 0 && j < n; }

    void dfs( int x, int y, vector<vector<int>> &ans )
    {
        vis[{x, y}] = 1;
        for( int i = 0; i < 4; i++ )
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if( valid(nx, ny, ans.size()) && ans[nx][ny] == 0 && !vis[{nx, ny}] )
                dfs(nx, ny, ans);
        }
    }

    int regionsBySlashes(vector<string> &grid)
    {
        dx = {1, -1, 0, 0};
        dy = {0, 0, 1, -1};
        int res = 0;
        vector<vector<int>>ans = build(grid);
        for( int i = 0; i < ans.size(); i++ )
        {
            for( int j = 0; j < ans.size(); j++ )
            {
                if( ans[i][j] == 0 && !vis[{i, j}])
                    dfs(i, j, ans), res++;
            }
        }

        return res;
    }
};