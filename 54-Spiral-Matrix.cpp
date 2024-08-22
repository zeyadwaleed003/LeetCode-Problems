class Solution {
public:
    vector<int>ans;
    vector<vector<bool>>vis;
    int n, m;
    void go( int i, int j, bool r, bool l, bool d, bool u, vector<vector<int>>& matrix)
    {
        ans.push_back(matrix[i][j]);
        vis[i][j] = 1;
        if( (r && j + 1 >= m) || (r && vis[i][j + 1]) )
            r = 0, d = 1;
        else if( (d && i + 1 >= n) || (d && vis[i + 1][j]))
            d = 0, l = 1;
        else if( (l && j == 0) || (l && vis[i][j - 1]))
            l = 0, u = 1; 
        else if( (u && i == 0) || (u && vis[i - 1][j]))
            u = 0, r = 1;
        
        if(r && j + 1 < m && !vis[i][j + 1])
            go( i, j + 1, r, l, d, u, matrix );
        
        if(l && j - 1 >= 0 && !vis[i][j - 1])
            go( i, j - 1, r, l, d, u, matrix );
        
        if(d && i + 1 < n && !vis[i + 1][j])
            go( i + 1, j, r, l, d, u, matrix );
        
        if(u && i - 1 >= 0 && !vis[i - 1][j])
            go(i - 1, j, r, l, d, u, matrix);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        n = matrix.size();
        m = matrix[0].size();
        vis.resize(n, vector<bool>(m, 0));
        go(0, 0, 1, 0, 0, 0, matrix);
        return ans;
    }
};