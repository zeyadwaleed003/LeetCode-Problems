class Solution 
{
public:
    int dp[55];
    int go( int steps, int n )
    {
        if( steps > n )
            return 0;

        if( steps == n )
            return 1;

        if( dp[steps] != -1 )
            return dp[steps];

        int op1 = go( steps + 1, n );
        int op2 = go( steps + 2, n );

        return dp[steps] = op1 + op2;
    }

    int climbStairs(int n) 
    {
        memset(dp, -1, sizeof dp);
        return go(0, n);
    }
};