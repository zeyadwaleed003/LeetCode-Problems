class Solution {
public:
    map<string,int>frq;
    int m;
    int dp[305][305];

    bool go( int i, int cnt, string &s )
    {
        if( i == m )
            return cnt == 1;

        if( i + cnt - 1 >= m )
            return false;

        if( dp[i][cnt] != -1 )
            return dp[i][cnt];

        bool op1 = go( i, cnt + 1, s );
        bool op2 = 0;

        if( frq[s.substr(i, cnt)] )
            op2 = go( i + cnt, 1, s );

        return dp[i][cnt] = op1 | op2;
    }

    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n = wordDict.size();
        m = s.size();

        for( int i = 0; i < n; i++ )
            frq[wordDict[i]]++;

        memset(dp, -1, sizeof dp);
        return go(0, 1, s);
    }
};