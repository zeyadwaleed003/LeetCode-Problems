class Solution
{
public:
    int n, m;
    vector<int>dx = {1, -1, 0, 0, 1, 1, -1, -1};
    vector<int>dy = {0, 0, 1, -1, 1, -1, 1, -1};
    bool valid(int i, int j){ return i >= 0 && i < n && j >= 0 && j < m; }
    int alive( int i, int j, vector<vector<int>>& board )
    {
        int cnt = 0;
        for( int ii = 0; ii < 8; ii++ )
        {
            int x = i + dx[ii], y = j + dy[ii];
            if( valid(x, y) )
                cnt += board[x][y];
        }

        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) 
    {
        n = board.size(), m = board[0].size();

        vector<vector<int>>cnt(n, vector<int>(m));
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < m; j++ )
                cnt[i][j] = alive(i, j, board);

        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                if( board[i][j] )
                    board[i][j] = !(cnt[i][j] > 3 || cnt[i][j] < 2);
                else if( !board[i][j] )
                    board[i][j] = (cnt[i][j] == 3);
            }
        }
    }
};