class Solution 
{
public:
    int go( int i, int M, bool Alice, vector<int>& piles )
    {
        if( i >= piles.size() )
            return 0;

        if( dp[i][M][Alice] != -1 )
            return dp[i][M][Alice];

        int ans = (Alice? 0 : 1e9), sum = 0;
        for( int step = 1; step <= 2 * M; step++ )
        {
            if( step + i - 1 == piles.size() )
                break;

            sum += piles[i + step - 1];
            if( Alice )
                ans = max(ans, go(i + step, max(M, step), !Alice, piles) + sum);
            else
                ans = min(ans, go(i + step, max(M, step), !Alice, piles));
        }

        return dp[i][M][Alice] = ans;
    }

    int stoneGameII(vector<int>& piles)
    {
        memset(dp, -1, sizeof dp);
        return go(0, 1, 1, piles);
    }

private:
int dp[105][305][2];
};