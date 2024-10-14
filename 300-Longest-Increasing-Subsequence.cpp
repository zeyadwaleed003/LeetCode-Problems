class Solution {
public:
    int n;
    int dp[2505][2505][2];
    int go( int i, int lastIdx, bool take, vector<int>& nums )
    {
        if( i == n )
            return 0;

        if( dp[i][lastIdx][take] != -1 )
            return dp[i][lastIdx][take];

        int op1 = -1e5, op2 = -1e5;
        if( nums[i] > nums[lastIdx] || take )
            op1 = go( i + 1, i, 0, nums ) + 1;

        op2 = go( i + 1, lastIdx, take,  nums );
        return dp[i][lastIdx][take] = max(op1, op2);
    }

    int lengthOfLIS(vector<int>& nums)
    {
        n = nums.size();
        memset(dp, -1, sizeof dp);
        return go(0, 0, 1, nums);
    }
};