class Solution {
public:
    int n, dp[105];
    int go( int i, vector<int>& nums )
    {
        if( i >= n )
            return 0;
        
        if( dp[i] != -1 )
            return dp[i];

        int op1 = go( i + 1, nums );
        int op2 = go( i + 2, nums ) + nums[i];
        
        return dp[i] = max(op1, op2);
    }

    int rob(vector<int>& nums)
    {
        n = nums.size();
        memset(dp, -1, sizeof dp);
        return go( 0, nums );
    }
};