class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size();
        set<int>rows, cols;
        for( int i = 0; i < n; ++i )
            for( int j = 0; j < m; ++j )
                if( !matrix[i][j] )
                    rows.insert(i), cols.insert(j);

        for( int i : rows )
            for( int j = 0; j < m; ++j )
                matrix[i][j] = 0;

        for( int j : cols )
            for( int i = 0; i < n; ++i )
                matrix[i][j] = 0;
    }
};