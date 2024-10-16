class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>>ans(n, vector<int>(n));

        for( int j = 0; j < n; ++j )
            for( int i = n - 1, ii = 0; i >= 0; --i, ++ii )
                ans[j][ii] = matrix[i][j];        
        
        matrix = ans;
    }
};