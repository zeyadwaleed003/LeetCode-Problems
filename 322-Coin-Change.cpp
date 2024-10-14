class Solution {
public:
    int n;
    int dp[13][(int)1e4 + 5];

    int go( int i, int money, vector<int>& coins )
    {
        if( !money )
            return 0;

        if( i == n )
            return 1e9;
        
        if( dp[i][money] != -1 )
            return dp[i][money];
    
        int op1 = 1e9, op2 = 1e9;
        if( coins[i] <= money )
            op1 = go(i, money - coins[i], coins) + 1;
        op2 = go( i + 1, money, coins );

        return dp[i][money] = min(op1, op2);
    }

    int coinChange(vector<int>& coins, int amount)
    {
        n = coins.size();
        sort(coins.rbegin(), coins.rend());
        memset(dp, -1, sizeof dp);
        int ans = go( 0, amount, coins );
        if( ans == 1e9 )
            ans = -1;
        return ans;
    }
};