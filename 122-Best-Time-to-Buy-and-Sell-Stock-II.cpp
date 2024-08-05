class Solution {
public:
    int dp[(int)3e4 + 5][2];

    int go( int i, bool minus, vector<int>& prices )
    {
        if( i == prices.size() )
        {
            if( !minus )
                return 0;

            return -1e5;
        }
        
        if( dp[i][minus] != -1 )
            return dp[i][minus];
        
        int op1 = go( i + 1, minus, prices );
        int op2 = go( i + 1, minus ^ 1, prices ) + ((minus == 0)? -prices[i] : prices[i]);

        return dp[i][minus] = max(op1, op2);
    }

    int maxProfit(vector<int>& prices)
    {
        memset(dp, -1, sizeof dp);
        return go(0, 0, prices);
    }
};