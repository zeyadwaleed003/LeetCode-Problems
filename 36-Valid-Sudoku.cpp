class Solution {
public:
    bool validRows(vector<vector<char>>& board)
    {
        for( int i = 0; i < board.size(); i++ )
        {
            map<char,int>vis;
            for( int j = 0; j < board[i].size(); j++ )
                vis[board[i][j]]++;

            for( int j = '1'; j <= '9'; j++ )
                if( vis[j] > 1 )
                    return false;
        }

        return true;
    }

    bool validCols(vector<vector<char>>& board)
    {
        for( int j = 0; j < board[0].size(); j++ )
        {
            map<char,int>vis;
            for( int i = 0; i < board.size(); i++ )
                vis[board[i][j]]++;

            for( int i = '1'; i <= '9'; i++ )
                if( vis[i] > 1 )
                    return false;
        }

        return true;
    }

    bool validSubs(vector<vector<char>>& board)
    {
        int l = 0, r = 0, begl = 0;
        map<char, int>vis;
        while( true )
        {
            int begr = r;
            while( r < begr + 3 )
                vis[board[l][r++]]++;

            l++;
            r = begr;
            if( l == begl + 3 )
            {
                l = begl, r = begr + 3;
                for( int i = '1'; i <= '9'; i++ )
                    if( vis[i] > 1 )
                        return false;

                for( int i = '1'; i <= '9'; i++ )
                    vis[i] = 0;
            }

            if( r >= board[0].size() )
            {
                l = begl + 3, r = 0;
                begl += 3;
            }
            
            if( l >= board.size() )
                break;
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board)
    {
        bool row = validRows(board);
        bool column = validCols(board);
        bool subs = validSubs(board);

        if( row && column && subs )
            return true;

        return false;
    }
};