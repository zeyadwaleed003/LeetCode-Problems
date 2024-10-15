class Solution {
public:
    int go( int i, int j, string &word1, string &word2 )
    {
        if( i >= n && j >= m )
            return 0;

        if( dp[i][j] != -1 )
            return dp[i][j];

        if( i < n && j < m && word1[i] == word2[j] )
            return dp[i][j] = go(i + 1, j + 1,word1, word2);

        int op1 = 1e5, op2 = 1e5, op3 = 1e5;
        if( i < n )
            op1 = go(i + 1, j,word1, word2);

        if( i < n && j < m )
            op2 = go(i + 1, j + 1, word1, word2);
        
        if( j < m )
            op3 = go(i, j + 1, word1,word2);

        return dp[i][j] = min({op1, op2, op3}) + 1;
    }
    int minDistance(string word1, string word2) {
        n = word1.size(), m = word2.size();
        memset(dp, -1, sizeof dp);
        return go(0, 0,word1, word2);
    }
private:
    int n, m, dp[550][550];
};