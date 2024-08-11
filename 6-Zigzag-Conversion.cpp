class Solution {
public:
    string convert(string s, int numRows) {
        if( numRows == 1 )
            return s;

        char grid[(int)2e3][(int)2e3];
        memset(grid, '/', sizeof grid);

        pair<int,int>cell = {0, 0};
        int i = 0, n = s.size();
        while( true )
        {
            if( cell.first == numRows )
            {
                cell.first -= 2;
                cell.second++;
                while( cell.first > -1 && i < n )
                    grid[cell.first--][cell.second++] = s[i++];
            }

            if( cell.first == -1 )
                cell.first += 2;

            if( i >= n )
                break;

            grid[cell.first++][cell.second] = s[i++];
        }

        string ans;
        for( int i = 0; i < 2e3; i++ )
            for( int j = 0; j < 2e3; j++ )
                if( grid[i][j] != '/' )
                    ans += grid[i][j];

        return ans;
    }
};